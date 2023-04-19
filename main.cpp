#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include <cstdlib>

typedef struct {
    std::string nameInPath;
    std::string nameInFile;
    std::string groupName;
} subject;

std::vector<subject> subjects; 
const std::string PRACTISE_STRING = "/u";
const std::string TASK_STRING = "/a";
const int PRACTISE_STRING_LENGTH = 2;
const int TASK_STRING_LENGTH = 2;

void init();
std::string createFileName();


int main(int argc, char* argv[]) {
    if (argc != 2){
	std::cerr << "Usage: submit filepath" << std::endl;
	std::cerr << "No files have been changed" << std::endl;
	std:exit(1);
    }
    
    init();
    std::string newFileName = createFileName();
    std::rename(argv[1], newFileName.c_str());
    
    std::cout << "Renamed:  " << argv[1] << " --> " << newFileName << std::endl;
    return 0;
}

void init() {
    subject ds {"ds", "DS", "3-14"};
    subjects.push_back(ds);
    subject pg2 {"pg2", "PG2", "1-14"};
    subjects.push_back(pg2);
    // add more subjects here
}

std::string createFileName() {
    // get current filepath
    std::string filePath = static_cast<std::string>(std::filesystem::current_path());

    // search for a subject in the current filepath; exit if no subject found
    int counter;
    for(counter = 0; counter < subjects.size(); counter++){
	std::size_t found = filePath.find(subjects.at(counter).nameInPath);
	if(found != std::string::npos)
	    break;
    }

    if(counter == subjects.size()){
        std::cerr << "No subject has been found in the filepath" << std::endl;
	std::exit(1);
    }

    // extract numbers from path
    std::string practiseNumber;
    std::string taskNumber;
    std::size_t found;
   
    found = filePath.find(PRACTISE_STRING);
    if(found != std::string::npos){
	practiseNumber = filePath.substr((found + PRACTISE_STRING_LENGTH), 2);	
    } else {
	std::cerr << "No practise has been found in the filepath" << std::endl;
        std::exit(1);
    }

    found = filePath.find(TASK_STRING);
    if(found != std::string::npos){
        taskNumber = filePath.substr((found + TASK_STRING_LENGTH), 1);
    } else {
	std::cerr << "No task has been found in the filepath" << std::endl;
        std::exit(1);
    }

    // create new filename and return
    std::stringstream newFileName;
    newFileName << subjects.at(counter).nameInFile << '-' << subjects.at(counter).groupName << "_U" << practiseNumber << "_" << taskNumber << ".txt";
    return newFileName.str();   
}
