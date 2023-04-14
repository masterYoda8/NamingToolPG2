# NamingToolPG2
Command Line Tool which changes file name to specified name.

## How it works
The tool checks from which subdirectory it was called.
It creates the new File name according to const values specified in tool.cpp (e.g. groupName = "1-14") and adding parts of directory names.
Example: if you would execute the tool via tool testFile.txt with path pg2/u02/a3/ the tool would change the filename from testFile.txt to PG2-1-14_U02_3.txt
PG2-1-14 is specified in tool.cpp. The 02 and 3 would be changed because of the directory of the file. 

## How to use it
Download tool.cpp file.
Compile it on your machine.
Add compiled file to /usr/local/bin path.
