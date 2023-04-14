#include <iostream>
#include <cstdio>
#include <string>
#include <filesystem>
#include <unistd.h>

using std::filesystem::current_path;

std::string exerciseNumber;
std::string taskNumber;
std::string groupName = "1-14";

void setExerciseAndTaskNumber() {
    // Create buffer
    char tmp[256];
    // Copy current working directory path into buffer
    getcwd(tmp, 256);
    std::string tmpString = static_cast<std::string>(tmp);
    // Extract excersiceNumber from full path
    exerciseNumber = tmpString.substr(tmpString.size() - 5, 2);
    // Extract taskNumber from full path
    taskNumber = tmpString.substr(tmpString.size() - 1, 1);
}

std::string getNewFileName() {
    std::string newFileName = "PG2-" + groupName + "_U" + exerciseNumber + "_" + taskNumber + ".txt"; 
    return newFileName;
}

int main(int argc, char* argv[]) {
    setExerciseAndTaskNumber();
    if (argc == 2) {
	std::rename(argv[1], getNewFileName().c_str());
    }
    return 0;
}
