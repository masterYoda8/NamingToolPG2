#!/bin/bash

# get cwd
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

# exit if no program name provided
if [ -z $1 ]; then 
  echo -e "\033[1;31mInstallation Error!\033[0m"
  echo -e "\033[1;33mUsage: bash install.sh \033[1;31m<program_name>\033[0m"
  exit 1
fi

# compile main.cpp using g++
output=$(g++ -std=c++20 main.cpp -DBASH_NAME=\"$1\" -o $1)

# exit on compile error
if [[ $? != 0 ]]; then
    echo -e "\033[1;31mError:\n$output\033[0m"
else 
    # move file to usr/local/bin
    sudo mv $SCRIPT_DIR/$1 /usr/local/bin/$1
    echo -e "\033[1;32m$1\033[0m successfully installed"  
fi

