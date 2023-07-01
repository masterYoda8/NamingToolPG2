#include <string>

#include "fileData.h"
#include "utils.h"

fileData::fileData(std::string fileToRename_): fileToRename{fileToRename_},
                                               filePathString{static_cast<std::string>(std::filesystem::current_path())},
                                               filePath{static_cast<std::filesystem::path>(fileToRename_)} {}

void fileData::keepExtension(){
    fileFormatExtension = filePath.extension();
}


