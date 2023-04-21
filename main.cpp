#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include <cstdlib>

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

std::vector<subject> subjects; 

void initSubjectVector();
std::string createFileName();
std::string extractPractiseNumber(const std::string &);
std::string extractTaskNumber(const std::string &);
int getSubjectIndex(const std::string &);


int main(int argc, char* argv[]) {
    if (argc != 2){
	std::cerr << COLOR_YELLOW << "Usage: " << BASH_NAME << " filepath" << std::endl;
	std::cerr << "No files have been changed" << COLOR_RESET << std::endl;
	std::exit(1);
    }
    
    initSubjectVector();
    std::string newFileName = createFileName();
    std::rename(argv[1], newFileName.c_str());
    
    std::cout << "Renamed:  " << argv[1] << " --> " << COLOR_GREEN << newFileName << COLOR_RESET << std::endl;
    return 0;
}

void initSubjectVector() {
    subject ds {"ds", "DS", "3-14"};
    subjects.push_back(ds);
    subject pg2 {"pg2", "PG2", "1-14"};
    subjects.push_back(pg2);
    // add more subjects here
}

std::string createFileName() {
    // get current filepath
    const std::string filePath = static_cast<std::string>(std::filesystem::current_path());
    const std::string & filePathRef = filePath;

    // search for a subject in the current filepath; exit if no subject found
    int subjectIndex = getSubjectIndex(filePathRef);
    std::string subjectNameInFile = subjects.at(subjectIndex).nameInFile;
    std::string groupName = subjects.at(subjectIndex).groupName; 

    // extract numbers from path
    std::string practiseNumber = extractPractiseNumber(filePathRef);
    std::string taskNumber = extractTaskNumber(filePathRef);

    // create new filename and return
    std::stringstream newFileName;
    newFileName <<  subjectNameInFile << '-' << groupName << "_U" << practiseNumber << "_" << taskNumber << ".txt";
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
