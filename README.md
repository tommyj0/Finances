# Finances

## Overview

Simple C++ project to manage expenses

## Requirements

- CMake >= 3.16
- CC
- Make

## Usage

1. Update the info in include/secret_financial_info.h to reflect salary and savings

2. if on Linux or Mac, source setup.sh (only to be done once)

```sh
chmod +x setup.sh run.sh
./setup.sh
```

3. Finally, run the program

```sh
./run.sh
```



## TODO

- Implement Mortgage, Car and Savings classes, inheriting from the simple expense classes

- Make an example that includes an interface that handles everything from the command line, so no need to modify main

- Host this as a website, on an RPi, so you can upload specific expenses that get logged
