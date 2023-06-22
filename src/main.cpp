#include <iostream>
#include <filesystem>
#include <string>
#include <cstdlib>
#include <cstring>
#include "utils.h"
#include <cstdbool>

bool fFlag = 0;
bool aFlag = 0;

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 5){
	std::cerr << COLOR_YELLOW << "Usage: " << BASH_NAME << " filepath" << std::endl;
	std::cerr << "No files have been changed" << COLOR_RESET << std::endl;
	std::exit(1);
    }

    std::filesystem::path filePath = static_cast<std::filesystem::path>(argv[1]);

    std::string fileFormatExtension = ".txt";
    std::string addon = "";

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) { 
            fileFormatExtension = filePath.extension(); 
            fFlag = true;
        }
        else if (strcmp(argv[i], "-a") == 0) { 
            addon = "_" + static_cast<std::string>(argv[++i]);
            aFlag = true;
        }  
    }

    // only add old file name to file if new type is txt (could make problems if new file type is pdf and not txt)
    if (!fFlag) {addOldFileName(filePath);}


    std::string newFileName = createFileName(addon, fileFormatExtension);

    std::rename(argv[1], newFileName.c_str());
    
    std::cout << "Renamed:  " << argv[1] << " --> " << COLOR_GREEN << newFileName << COLOR_RESET << std::endl;

    return 0;
}


