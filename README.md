# HackOSsim

Welcome to the HackOSsim Project! This project is designed to provide hands-on experience with operating systems, utilizing the QEMU Instruction Set Architecture (ISA) simulator. The primary focus is on customizing embedded operating systems to implement new features and evaluating their performance under significant workloads.

## Project Overview

Explore the different aspects of this project:

- [**QEMU Installation and Usage**](./docs/qemu.md): Learn the essentials of using QEMU for running embedded operating systems. The tutorial provides step-by-step instructions for installation and usage.

## Getting Started

### Download the Project

Clone this repo running the following command. Be sure to have git installed on your system.

```bash
git clone --recurse-submodules https://github.com/cicciord/HackOSsim.git
```

#### Submodules

Beware that this project includes _submodules_, so you need to run git clone with the flag `--recurse-submodules` otherwise the content of the submodule directories will not be cloned.

If you run the command without the flag you can run the following command, after changing the directory in the cloned one, to download the submodules content in a second time.

```bash
cd HackOSsim
git submodule update --init --recursive
```

#### Contributors
If you are a student working on this project, please run the `init.sh` script after cloning the repo.

### Explore the Project

To begin, follow the instructions in the [QEMU Installation and Usage](./docs/qemu.md) to install and use QEMU with the chosen embedded operating system. Each section is designed to be self-contained, allowing you to focus on specific aspects of the project.
