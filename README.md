# vgedit [![travis](https://travis-ci.org/vgmoose/vgedit.svg?branch=master)](https://travis-ci.org/vgmoose/vgedit)
An SDL2 text editor designed for easy use on a console using a controller or touch screen.


## Compilation instructions

### Building for Switch (with libnx)
1. Install [dkp-pacman](https://devkitpro.org/viewtopic.php?f=13&t=8702)
2. Install devkitA64 and needed Switch dependencies via dkp-pacman:
```
sudo dkp-pacman -S devkitA64 libnx switch-tools switch-bzip2 switch-freetype switch-libjpeg-turbo switch-sdl2 switch-sdl2_gfx switch-sdl2_image switch-sdl2_ttf switch-libpng switch-mesa
```
3. Once it's all setup, recursively clone the repo and run make:
```
git clone --recursive https://github.com/vgmoose/vgedit.git
cd vgedit
make -f Makefile.switch
```

If all goes well, `vgedit.nro` should be sitting in the current directory.

### Building for Wii U (with WUT)
The below instructions are currently for Linux and macOS
1. Install [dkp-pacman](https://devkitpro.org/viewtopic.php?f=13&t=8702)
2. Setup [wiiu-fling](https://gitlab.com/QuarkTheAwesome/wiiu-fling#wiiu-fling) according to the instructions
3. Install sdl2, wut, devkitPPC and other dependencies (on macOS, use `wut-osx` instead of `wut-linux`)
```
sudo dkp-pacman -S wut-linux wiiu-sdl2 devkitPPC wiiu-libromfs wiiu-sdl2_gfx wiiu-sdl2_image wiiu-sdl2_ttf ppc-bzip2 ppc-freetype ppc-libpng
```
4. Once the environment is setup:
```
git clone --recursive https://github.com/vgmoose/vgedit.git
cd vgedit
make -f Makefile.wiiu
```

If all goes well, `vgedit.rpx` should be sitting in the current directory.

### Building for PC
There's a separate makefile for building the SDL2 app for PC. Below instructions are for Ubuntu, but should be similar on other platforms:
```
sudo apt-get install libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libsdl2-gfx-dev gcc g++ git
git clone --recursive https://github.com/vgmoose/vgedit.git
cd vgedit
make -f Makefile.pc
```

## License
This software is licensed the GPLv3

Folder and file icons by [Alfredo Hernandez](https://www.flaticon.com/authors/alfredo-hernandez) under the Flaticon Basic License

### Contributing
It's not required, but running a clang-format before making a PR helps to clean up styling issues:
```
find . \( -name "*.cpp" -or -name "*.hpp" \) -not -path "./libs/*" -exec clang-format -i {} \;
```

