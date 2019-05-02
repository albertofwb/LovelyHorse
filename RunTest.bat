@echo off

set testBin=Release\Test.exe


call BuildOnly.bat

%testBin%