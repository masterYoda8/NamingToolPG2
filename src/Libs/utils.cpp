#include <string>
#include <vector>
#include <sstream>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "utils.h"


static std::vector<subject> subjects;

void initSubjectVector() {
    subject ds {"ds", "DS", "3-14"};
    subjects.push_back(ds);
    subject pg2 {"pg2", "PG2", "1-14"};
    subjects.push_back(pg2);
    // add more subjects here
}

void addOldFileName(std::filesystem::path filePath) {
    std::ofstream outputFile("tmp");
    std::ifstream inputFile(filePath);
    
    if (outputFile.fail() || inputFile.fail()){return;}

    outputFile << "// Renamed from: " << filePath << "\n\n";
    outputFile << inputFile.rdbuf();

    inputFile.close();
    outputFile.close(); 

    std::remove(filePath.c_str());
    std::rename("tmp", filePath.c_str());
}

std::string createFileName(const std::string & addon, const std::string & fileFormatExtension, const std::string & filePathString) {
    
    initSubjectVector();

    // search for a subject in the current filepath; exit if no subject found
    int subjectIndex = getSubjectIndex(filePathString);
    std::string subjectNameInFile = subjects.at(subjectIndex).nameInFile;
    std::string groupName = subjects.at(subjectIndex).groupName; 

    // extract numbers from path
    std::string practiseNumber = extractPractiseNumber(filePathString);
    std::string taskNumber = extractTaskNumber(filePathString);

    // create new filename and return
    std::stringstream newFileName;
    newFileName <<  subjectNameInFile << '-' << groupName << "_U" << practiseNumber << "_" << taskNumber << addon << fileFormatExtension;
    return newFileName.str();   
}

int getSubjectIndex(const std::string & filePathRef) {

    int counter;

    for(counter = 0; counter < subjects.size(); counter++){

	std::size_t found = filePathRef.find(subjects.at(counter).nameInPath);

	if(found != std::string::npos) break;

    }

    if(counter == subjects.size()){

        std::cerr << COLOR_RED << "No subject has been found in the filepath" << COLOR_RESET << std::endl;
	std::exit(1);

    }

    return counter;
}

std::string extractPractiseNumber(const std::string & filePathRef) {

    std::size_t found = filePathRef.find(PRACTISE_STRING);

    if(found != std::string::npos){

  	return filePathRef.substr((found + PRACTISE_STRING_LENGTH), 2);	

    } else {

        std::cerr << COLOR_RED << "No practise has been found in the filepath" << COLOR_RESET << std::endl;
        std::exit(1);
	
    }  
}

std::string extractTaskNumber(const std::string & filePathRef) {
    
    std::size_t found = filePathRef.find(TASK_STRING);

    if(found != std::string::npos){
    
        return filePathRef.substr((found + TASK_STRING_LENGTH), 1);

    } else {

	std::cerr << COLOR_RED << "No task has been found in the filepath" << COLOR_RESET << std::endl;
        std::exit(1);

    }
}
