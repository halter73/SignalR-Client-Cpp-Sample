```
> # Run https://github.com/dotnet/aspnetcore/tree/8481b938802c769f7c231a7f8d5fd37d3ee90699/src/SignalR/samples/SignalRSamples
> C:\dev\microsoft\vcpkg\vcpkg.exe install signalrclient:x64-windows
> $env:Path+=";C:\dev\microsoft\vcpkg\installed\x64-windows\bin"
> mkdir build
> cd build
> cmake .. -D CMAKE_PREFIX_PATH="C:/dev/microsoft/vcpkg/installed/x64-windows/"
> cmake --build .
> .\Debug\sample.exe
```