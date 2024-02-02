# DLL Plugin Loader

This loads `.dll` files loader in the `Plugins` directory.

This loader is implemented on different wrappers.
The following are the available wrappers:

- `d3d9.dll`
- ... and more


## Installation
Put the `DLL Plugin Loader DLL` where your application `.exe` is located.
Example:
```
C:\Program Files\MyApp\MyApp.exe
C:\Program Files\MyApp\d3d9.dll
```

## Building from source

## Pre-requisites
- Visual Studio 2022

## Steps

1. Clone the repository
```
git clone https://github.com/t4bby/dll-plugin-loader
```
2. Open the solution file `dll-plugin-loader.sln` in Visual Studio 2022.
3. Build the project in either `Debug` or `Release`