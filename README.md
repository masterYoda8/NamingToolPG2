# Submission Naming Tool
Command-line tool that changes the specified file to a name that obey to the submission rules.

## How it works
The tool checks from which subdirectory it was called.
It creates the new File name according to the values specified in the subjects vector of main.cpp. 

### Example: 
if you would execute the tool via: 'tool testFile.txt' with path pg2/u02/a3/ the tool would change the filename from testFile.txt to PG2-1-14_U02_3.txt.

PG2-1-14 is specified in main.cpp. The 02 and 3 would be changed because of the directory of the file.

## How to install

With install.sh an install-script is provided so you don't to compile anything by hand or move the compiled files around.

You can use it the following way:
```bash
bash instal.sh <name_of_the_programm>
```



