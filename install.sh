#!/bin/bash

# get cwd
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

# exit if no program name provided
if [ -z $1 ]; then
  echo -e "usage bash instal.sh <program_name>"
  exit 1
fi

# compile main.cpp using g++
output=$(g++ -std=c++20 main.cpp -DBASH_NAME=\"$1\" -o $1)

# exit on compile error
if [[ $? != 0 ]]; then
    echo -e "Error:\n$output"
else 
    # move file to usr/local/bin
    sudo mv $SCRIPT_DIR/$1 /usr/local/bin/$1
    echo "$1 successfully installed"  
fi

