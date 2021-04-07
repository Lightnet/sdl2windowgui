# SDL2Test

# Information:
  Tested build for mingw32 from raylib standalone and portable compiler. To have some basic code tests.

  Tested imgui simple window gui display.

# Setup:
  Download the SDL2 Development Libraries MinGW.

  Download Raylib installer.

  Need to set raylib "C:\raylib\mingw\bin" to path system environment variables.

# Builds:
 * build32bat (build main.exe)
 * debugbuild32bat (build main.exe and run execute file)

# Notes:
imgui.cpp missing function call
```c++
//line 10760
//if (HWND hwnd = (HWND)io.ImeWindowHandle)
  //if (HIMC himc = ::ImmGetContext(hwnd))
  //{
    //COMPOSITIONFORM cf;
    //cf.ptCurrentPos.x = x;
    //cf.ptCurrentPos.y = y;
    //cf.dwStyle = CFS_FORCE_POSITION;
    //::ImmSetCompositionWindow(himc, &cf);
    //::ImmReleaseContext(hwnd, himc);
  //} 
```