# Building the Development Environment

The goal here is to build the development system that can be used for cross-target development on Cortex-M devices. This will be done on Visual Studio Code. 

[MeowWorkshop](https://www.meoworkshop.org/firmware-dev-with-vs-code-and-cmake/) offers a nice brekdown of the setting up cmake, build tasks in vscode, and little on setting up debugging. This was one of the main resources, though others were used to supplement various sections.

The key steps include:
- Installing Tools
	- [Visual Studio Code](https://code.visualstudio.com)
	- [pico-sdk](https://github.com/raspberrypi/pico-sdk)
	- [pico-examples](https://github.com/raspberrypi/pico-examples)
	- [FreeRTOS](https://github.com/FreeRTOS/FreeRTOS-Kernel)
	- CMake
- Setting up system vars
- Starting the VSCode Project
- Integrating pico-sdk
- Setting up the CMake Build System
- Setting up VSCode Tasks
- Integrating FreeRTOS
- Setting up VSCode Debugging for Pico W
- 

## Setting Up Your System

Each OS (e.g. Windows, MacOS, Linux) require their own unique setups. Some of those necessities are presented below.

### Windows

Here's some tool's you'll need to install
1. [CMake](https://cmake.org/download/)
1. [Build Tools for Visual Studio](https://visualstudio.microsoft.com/downloads/)
    - This is installed through the Visual Studio Installer app
1. [Git](https://git-scm.com/download/win)
1. [ARM GCC Compiler](https://developer.arm.com/downloads/-/gnu-rm)

This youtube [vid](https://www.youtube.com/watch?v=mUF9xjDtFfY&t=403s) provides a good run down of all the tools you'll need to intall.


### MacOS

You'll need to stall a number of tools, like on Windows. However, this tutorial suggests using the [Homebrew](https://brew.sh) package manager, install instructions can be found at the link provided.

Once installed, install the following packages:
1. cmake
1. gcc-arm-embedded (cask)

NOTE: Git should already be installed (comes with MacOS)


### System Vars

Some system vars need to be installed. The provided VSCode resources are being built to be OS-agnostic and user-agnostic. This is because some resources could be different on a given system or for a given user. For Windows, 

1. PICO_SDK_PATH
	- set this to the path to the root path of the pico lib
1. GCC_ARM_PATH
	- set this to the folder with the arm-gcc compiler
1. SEGGER_PATH
	- set this to the filder with all Segger tools (e.g. JLink)


## Setting up VSCode

VSCode does a really good job of suggesting new extensions as it notices the file types you are working with. However, here is list of the  extensions you'll need/want to install to develop C/C++ for target cotext-m microcontrollers
- [Cortext-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
- [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)
- [C/C++ Themes](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-themes) (optional)
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)

> ISSUE
>
> On Windows machines, you'll need to start VSCode from a specific shell: Developer Command Prompt. This is a tool that is installed with the other *Build Tools for Visual Studio*. Opening the project, into VSCode, from this shell will setup VSCode to use it's environmental variables.

## Creating Build Tasks

This is how we can tie the CMake build system into VSCode. One reason I like this process over invoking the CMake Extension (so far) is I find it easier to setup the cmake cli commands and see them all in one place. It's also nice for later when I forget what I have setup and I don't have to search to CMake Tools Extension Settings. This also keeps things consistent with setting up debugging. As will be discussed, I use VSCode's c/c++ launch feature for both release and debug programming as well as entering into debug mode.

- Under the project root, add the file *.vscode*
	- add a new file *tasks.json*
	- Can find details on this under [vscode docs](https://code.visualstudio.com/docs/editor/tasks)
	- Can use this to create an number of different tasks. You could setup a task that build the project from the gcc/clang cli interface, invoke a makefile, or, in our case, invoke cmake and build the project.
- To run various tasks (other than the default one) you just need to get to the command pallett and type *task run*. you should get the option *Tasks: Run Task*. hit **enter** and the command pallet dropdown should show you all the tasks options you have in your *tasks.json* file.

>ISSUE
>One problem I ran into was that vscode did not recognize the *tasks.json* file I had created. I ended up closing vscode and reopening the project. That seemed to get vscode to recognize the tasks and I could select any of them to run.


## Setting Up Pico Debugging in VSCode

[Segger](https://www.segger.com/news/segger-j-link-flasher-and-embedded-studio-now-support-raspberry-pi-rp2040/) announced that has support for the RP2040 microcontroller. They also offer [instructions](https://wiki.segger.com/J-Link_Visual_Studio_Code) for setting up debugging in vscode for all major desktop OSs.

- [J-Link drivers](https://www.segger.com/downloads/jlink/)
- 