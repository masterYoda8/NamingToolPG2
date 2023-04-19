#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <filesystem>
#include <cstdlib>

const std::string PRACTISE_STRING = "/u";
const std::string TASK_STRING = "/a";
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
std::string extractPractiseNumber(std::string);
std::string extractTaskNumber(std::string);
int getSubjectIndex(std::string);


int main(int argc, char* argv[]) {
    if (argc != 2){
	std::cerr << "Usage: submit filepath" << std::endl;
	std::cerr << "No files have been changed" << std::endl;
	std::exit(1);
    }
    
    initSubjectVector();
    std::string newFileName = createFileName();
    std::rename(argv[1], newFileName.c_str());
    
    std::cout << "Renamed:  " << argv[1] << " --> " << newFileName << std::endl;
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
    std::string filePath = static_cast<std::string>(std::filesystem::current_path());

    // search for a subject in the current filepath; exit if no subject found
    int subjectIndex = getSubjectIndex(filePath);
    std::string subjectNameInFile = subjects.at(subjectIndex).nameInFile;
    std::string groupName = subjects.at(subjectIndex).groupName; 

    // extract numbers from path
    std::string practiseNumber = extractPractiseNumber(filePath);
    std::string taskNumber = extractTaskNumber(filePath);

    // create new filename and return
    std::stringstream newFileName;
    newFileName <<  subjectNameInFile << '-' << groupName << "_U" << practiseNumber << "_" << taskNumber << ".txt";
    return newFileName.str();   
}

int getSubjectIndex(std::string filePath) {

    int counter;

    for(counter = 0; counter < subjects.size(); counter++){

	std::size_t found = filePath.find(subjects.at(counter).nameInPath);

	if(found != std::string::npos) break;

    }

    if(counter == subjects.size()){

        std::cerr << "No subject has been found in the filepath" << std::endl;
	std::exit(1);

    }

    return counter;
}

std::string extractPractiseNumber(std::string filePath) {

    std::size_t found = filePath.find(PRACTISE_STRING);

    if(found != std::string::npos){

  	return filePath.substr((found + PRACTISE_STRING_LENGTH), 2);	

    } else {

        std::cerr << "No practise has been found in the filepath" << std::endl;
        std::exit(1);
	
    }  
}

std::string extractTaskNumber(std::string filePath) {
    
    std::size_t found = filePath.find(TASK_STRING);

    if(found != std::string::npos){
    
        return filePath.substr((found + TASK_STRING_LENGTH), 1);

    } else {

	std::cerr << "No task has been found in the filepath" << std::endl;
        std::exit(1);

    }
}
