#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <filesystem>

const std::string PRACTISE_STRING = "/u";
const std::string TASK_STRING = "/a";
const std::string COLOR_RED = "\033[1;31m";
const std::string COLOR_GREEN = "\033[1;32m";
const std::string COLOR_YELLOW = "\033[1;33m";
const std::string COLOR_RESET = "\033[0m";
constexpr int PRACTISE_STRING_LENGTH = 2;
constexpr int TASK_STRING_LENGTH = 2;

typedef struct {
    std::string nameInPath;
    std::string nameInFile;
    std::string groupName;
} subject;

void initSubjectVector();
void addOldFileName(std::filesystem::path);
std::string createFileName(const std::string &, const std::string &, const std::string &);
std::string extractPractiseNumber(const std::string &);
std::string extractTaskNumber(const std::string &);
int getSubjectIndex(const std::string &);

#endif

