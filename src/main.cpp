#include <iostream>
#include <filesystem>
#include <string>
#include <cstring>

#include "Libs/utils.h"
#include "Libs/flags.h"


int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 6){
	std::cerr << COLOR_YELLOW << "Usage: " << BASH_NAME << " filepath" << std::endl;
	std::cerr << "No files have been changed" << COLOR_RESET << std::endl;
	std::exit(1);
    }

    std::filesystem::path filePath = static_cast<std::filesystem::path>(argv[1]);
    std::string filePathString = static_cast<std::string>(std::filesystem::current_path());

    std::string fileFormatExtension = ".txt";
    std::string addon = "";
    std::string fileToRename = argv[1];

    flags::checkForFlags(argc, argv, addon);

    if (!(flags::isSet(flags::fFlag))) {
        addOldFileName(filePath);
    } else {
        fileFormatExtension = filePath.extension();
    } 
    if (flags::isSet(flags::cFlag)) {
        std::filesystem::path newTmpFileName = static_cast<std::filesystem::path>((filePathString + "_tmp"));
        std::filesystem::copy_file(filePath, newTmpFileName); 
        fileToRename = static_cast<std::string>(newTmpFileName);
    }

    std::string newFileName = createFileName(addon, fileFormatExtension, filePathString);
    
    std::rename(fileToRename.c_str(), newFileName.c_str());
    
    std::cout << ((flags::isSet(flags::cFlag)) ? "Copied: ": "Renamed: ");
    std::cout << argv[1] << " --> " << COLOR_GREEN << newFileName << COLOR_RESET << std::endl;

    return 0;
}


