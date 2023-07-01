#ifndef FILEDATA_H
#define FILEDATA_H

#include <filesystem>
#include <string>

typedef struct fileData{
    std::string fileToRename;
    std::string newFileName;
    std::filesystem::path filePath;
    std::string filePathString;
    std::string fileFormatExtension{".txt"};
    std::string addon{""};

    fileData(std::string);

    void keepExtension();

} fileData;

#endif
