# Building the Development Environment

The goal here is to build the development toolchain that can be used for cross-target development on the Raspberry Pi Pico W board. The Pico-W board houses the RP2040 and is the Foundation's first in-house IC build. It is a dual-core Cortex-M0+ chip. The Pico-W board offers a number of feature, including a Wifi and Bluetooth chip for wirelss communications.

> Tip
>
> Most tutorials found around the time this tuorial originated (Nov 2022) were for the original Pico board. The original board did not include the wireless chip and there some nuances to using this chip that are different from the original. A good example is the on-board LED. It is ran through the wireless chip so using blinky examples from the original board will fail.

This project integrates the Pico-SDK, the FreeRTOS kernel, and debugging through the Visual Studio Code IDE.


The key steps include:
- Installing Tools
	- [Visual Studio Code](https://code.visualstudio.com)
	- [Rasnperrby Pi Pico W]()
		- [Pico W Overview](https://datasheets.raspberrypi.com/picow/pico-w-product-brief.pdf)
		- [Datasheet](https://datasheets.raspberrypi.com/picow/pico-w-datasheet.pdf)
		- [Getting Started with C/C++ Development](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)
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

[MeowWorkshop](https://www.meoworkshop.org/firmware-dev-with-vs-code-and-cmake/) offers a nice brekdown of the setting up cmake, build tasks in vscode, and little on setting up debugging. This was one of the main resources, though others were used to supplement various sections.

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

Some MacOS-specific references:
- Here's a simple reference for [Pico Dev on MacOS](https://www.robertthasjohn.com/post/how-to-set-up-the-raspberry-pi-pico-for-development-on-macos)
- Here's a simple example of [setting up and building pic-example projects](https://vanhunteradams.com/Pico/Setup/PicoSetupMac.html)


### System Vars

Some system vars need to be installed. The provided VSCode resources are being built to be OS-agnostic and user-agnostic. This is because some resources could be different on a given system or for a given user. 

1. PICO_SDK_PATH
	- set this to the path to the root path of the pico lib
1. GCC_ARM_PATH
	- set this to the folder with the arm-gcc compiler
1. SEGGER_PATH
	- set this to the filder with all Segger tools (e.g. JLink)

For Windows OS systems, these should be installed throught the Viscual Studio Developer Command Prompt.

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





# References

- [Learn Embedded Systems - YouTube Channel](https://www.youtube.com/@LowLevelLearning/featured)
	- [Setting Up Pico Dev VSCode](https://www.youtube.com/watch?v=mUF9xjDtFfY)
	- [FreeRTOS Dev on Pico and VSCode](https://www.youtube.com/watch?v=jCZxStjzGA8&list=RDCMUCFJibhZ9FOjbsZIr6AxR0AQ&start_radio=1&rv=jCZxStjzGA8)
		- [Blog post](https://learnembeddedsystems.co.uk/freertos-on-rp2040-boards-pi-pico-etc-using-vscode)
- [Low Level Learning - Raspberry Pi Pico Series](https://www.youtube.com/watch?v=JhajoAyP8e4&list=PLc7W4b0WHTAV6EYRVayb9c9dEsq-NeXAt) on youTube provides some information on getting build environment together
- Pico-W References
	- This general tutorial on on [Programming the Pico W](https://www.electromaker.io/blog/article/electromaker-educator-getting-started-with-the-pico-w) may be useful to get started.
	- This [Getting Started with Pic W SDK Dev](https://www.electromaker.io/blog/article/getting-started-with-the-raspberry-pi-pico-w-cc-sdk) was usefull to pick out some nuances about the Pico W board.
- General Setup Resources
	- [Firmware Dev with VSCode and CMake](https://www.meoworkshop.org/firmware-dev-with-vs-code-and-cmake/)
		- this is a quick rundown on setting up VSCode to integrate CMake, building projects using Tasks, and setting up debugging through Launch settings
	- [Pico and FreeRTOS](https://blog.smittytone.net/2022/02/24/how-to-use-freertos-with-the-raspberry-pi-pico/) is a nice tutorial on using Pico SDK with the FreeRTOS kernel.
	- [Using FreeRTOS with Pico](https://embeddedcomputing.com/technology/open-source/linux-freertos-related/using-freertos-with-the-raspberry-pi-pico)
		- this resource offers some basics for installing tools on Windows, MacOS, and Linux
- JLink Debugger References
	- [JLink Hardware Interface](https://www.segger.com/products/debug-probes/j-link/technology/interface-description/)
	- [JLink Configuration in VSCode](https://github.com/Marus/cortex-debug/wiki/J-Link-Specific-Configuration)
	- [Flashing a Device with JLink and OpenOCD](https://machinehum.medium.com/flashing-the-rp2040-with-a-jlink-and-openocd-b5c6806d51c2)
	- 
- Visaul Studio Code References
	- [Tasks in VSCode](https://code.visualstudio.com/docs/editor/tasks)
	- [Configuring C/C++ in VSCode](https://code.visualstudio.com/docs/cpp/config-msvc)
	- Segger's notes on [Setting up Jlink in VSCode](https://wiki.segger.com/J-Link_Visual_Studio_Code)
- FreeRTOS Resources
	- [FreeRTOS Quick Start Guide](https://www.freertos.org/FreeRTOS-quick-start-guide.html)
