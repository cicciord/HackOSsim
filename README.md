# HackOSsim

Welcome to the HackOSsim Project! This project is designed to provide hands-on experience with operating systems, utilizing the QEMU Instruction Set Architecture (ISA) simulator. The primary focus is on customizing embedded operating systems to implement new features and testing their functionalities.

## Project Overview

Explore the different aspects of this project:

- [**QEMU Installation and Usage**](./docs/qemu.md): Learn the essentials of using QEMU for running embedded operating systems. The tutorial provides step-by-step instructions for installation and usage.

- [**Demo & Projects**](./docs/projects.md): Explore how an embedded project is developed and some functionalities of FreeRTOS at work.

- [**Custom FreeRTOS Features**](./docs/custom_freertos.md): Take a look at the new features implemented on FreeRTOS.

## Getting Started

### Download the Project

Clone this repo running the following command. Be sure to have git installed on your system.

```bash
git clone --recurse-submodules https://github.com/cicciord/HackOSsim.git
```

to clone the repo using ssh use this instead.

```bash
git clone --recurse-submodules git@github.com:cicciord/HackOSsim.git
```

### Submodules

Pay attention, this project includes _submodules_, so you need to run `git clone` with the flag `--recurse-submodules` otherwise the content of the submodule directories will not be cloned.

If you cloned the repo without the flag you can run the following command to download the submodules content in a second time.

```bash
git submodule update --init --recursive
```

## Contributors

- (**s323518**) Francesco Laterza
- (**s328764**) Leonardo Rizzo
- (**s328743**) Massimo Aresca
- (**s322787**) Yann Freddy Dongue Dongmo

If you are a student working on this project, please run the `init.sh` script after cloning the repo.