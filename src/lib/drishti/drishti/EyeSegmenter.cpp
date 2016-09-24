/**
  @file   EyeSegmenter.cpp
  @author David Hirvonen
  @brief  Implementation of public API for eye model estimation using simple portable types.

  \copyright Copyright 2014-2016 Elucideye, Inc. All rights reserved.
  \license{This project is released under the 3 Clause BSD License.}

  This file contains the Eyesegmenter public API class for eye model estimation.
*/

#include "drishti/EyeSegmenter.hpp"
#include "drishti/EyeSegmenterImpl.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

_DRISHTI_SDK_BEGIN

/*
 * EyeSegmenter
 */

EyeSegmenter::EyeSegmenter(const std::string &filename, ArchiveKind kind)
{
    std::ifstream is(filename);
    init(is, kind);
}

EyeSegmenter::EyeSegmenter(std::istream &is, ArchiveKind kind)
{
    init(is, kind);
}

void EyeSegmenter::init(std::istream &is, ArchiveKind kind)
{
    try
    {
        m_impl = std::unique_ptr<Impl>(new Impl(is, kind));
    }
    catch(std::exception &e)
    {
        std::cerr << "exception: EyeSegmenter::init() :" << e.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "exception: EyeSegmenter::init()" << std::endl;
    }
}

EyeSegmenter::~EyeSegmenter()
{

}

bool EyeSegmenter::good() const
{
    return static_cast<bool>(m_impl.get()); 
}

EyeSegmenter::operator bool() const
{
    return good();
}

int EyeSegmenter::operator()(const Image3b &image, Eye &eye, bool isRight)
{
    int status = (*m_impl)(image, eye, isRight);
    return status;
}

Eye EyeSegmenter::getMeanEye(int width) const
{
    return m_impl->getMeanEye(width);
}

int EyeSegmenter::getIrisInits() const
{
    return m_impl->getIrisInits();
}

void EyeSegmenter::setIrisInits(int count)
{
    m_impl->setIrisInits(count);
}

int EyeSegmenter::getEyelidInits() const
{
    return m_impl->getEyelidInits();
}

void EyeSegmenter::setEyelidInits(int count)
{
    m_impl->setEyelidInits(count);
}

int EyeSegmenter::getMinWidth() const
{
    return m_impl->getMinWidth();
}

float EyeSegmenter::getRequiredAspectRatio() const
{
    return m_impl->getRequiredAspectRatio();
}

void EyeSegmenter::setOptimizationLevel(int level)
{
    m_impl->setOptimizationLevel(level);
}

_DRISHTI_SDK_END

/*
 * Extern "C" interface (dlopen/dlsym)
 */

DRISHTI_EXTERN_C_BEGIN
drishti::sdk::EyeSegmenter* drishti_create_from_file(const std::string &filename)
{
    return new drishti::sdk::EyeSegmenter(filename);
}

drishti::sdk::EyeSegmenter* drishti_create_from_stream(std::istream &is)
{
    return new drishti::sdk::EyeSegmenter(is);
}

void drishti_destroy(drishti::sdk::EyeSegmenter *segmenter)
{
    if(segmenter)
    {
        delete segmenter;
    }
}

void drishti_segment(drishti::sdk::EyeSegmenter *segmenter, const drishti::sdk::Image3b &image, drishti::sdk::Eye &eye, bool isRight)
{
    (*segmenter)(image, eye, isRight);
}
DRISHTI_EXTERN_C_END

