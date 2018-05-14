
:: Seet POLLY_ROOT, HUNTER_ROOT and PATH for PYTHON on Windows Platform
::
:: Reference:
set PATH=c:\\Users\dhirv\AppData\\Local\\Programs\\Python\\Python35;c:\\Program Files\\CMake\\bin;%PATH%
set POLLY_ROOT=c:\\devel\ruslo\polly

set CONFIG=Release
set TOOLCHAIN=vs-15-2017
python %POLLY_ROOT%\bin\polly.py --reconfig ^
--verbose ^
--config "%CONFIG%" ^
--toolchain "%TOOLCHAIN%" ^
--test ^
--fwd HUNTER_USE_CACHE_SERVERS=NO DRISHTI_BUILD_TESTS=ON ^
--install ^
--open --reconfig --test
