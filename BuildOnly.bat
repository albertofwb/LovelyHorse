@echo off

:: Looks like starting from VS 2017 this variable is not set by default any more,
:: if you are using VS2017, make sure update %VS140COMNTOOLS% to "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\Tools\" in system Environment Variables.
set devenv="%VS140COMNTOOLS:~0, -7%\IDE\devenv"


:: Note if you are using VS2017, make sure that the Lightweight solution load is disabled, 
:: otherwise project will fail to build with " Rebuild All: 0 succeeded, 0 failed, 0 skipped"(but no error!)
:: see https://developercommunity.visualstudio.com/content/problem/122403/devenv-build-on-commandline-fails-on-lightweigth-s.html


set SolutionFible="LovelyHorse.sln"
echo %SolutionFible%

echo ============ Building solution with "Release|x86" ... ===============
%devenv% %SolutionFible% /clean "Release|x86"
%devenv% %SolutionFible% /build "Release|x86"
call :handleError



:handleError
if %ERRORLEVEL% NEQ 0 (
  if "%1"=="" (
    echo ERROR!
  ) else (
    echo %1
  )
  pause
  exit
)
goto :EOF