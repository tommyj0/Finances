# Finances

## Overview

Simple C++ project to manage expenses

## Requirements

- CMake >= 3.16
- CC
- Make

## Usage

if on Linux or Mac, source setup once

```sh
chmod +x setup.sh run.sh
./setup.sh
```

Use the following script to run the programc

```sh
./run.sh
```



## TODO

- Make Expense its own class, encapsulate has_xxx and the expense, maybe also the way it varies

- Implement Mortgage, Car and Savings classes, inheriting from the simple expense classes

- Make an example that includes an interface that handles everything from the command line, so no need to modify main
