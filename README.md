# Submission Naming Tool
Command-line tool that changes the specified file to a name that obey to the submission rules.

## How it works
The tool checks from which subdirectory it was called.
It creates the new File name according to the values specified in the subjects vector of main.cpp. 

### Example: 
if you would execute the tool via: 'tool testFile.txt' with path pg2/u02/a3/ the tool would change the filename from testFile.txt to PG2-1-14_U02_3.txt.

PG2-1-14 is specified in tool.cpp. The 02 and 3 would be changed because of the directory of the file. 

## How to use it

- Download tool.cpp file.
- Compile it on your machine.
```bash
	g++ main.cpp -o "name to call the programm"
```
- Add compiled file to /usr/local/bin path.

	Linux:
	```bash
	    - sudo mv "filepath to compiled programm" /usr/local/bin
	```
	OSX:
	```bash
	    - mv "filepath to compiled programm" /usr/local/bin
	```
