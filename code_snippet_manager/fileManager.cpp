#include <string>
#include "fileManager.h"




fileManager::fileManager(std::string filename) {

	this->file = filename;
	loadFromFile();
	std::cout << std::endl << "File Manager: Loaded snippets from " << this->file;

}

fileManager::~fileManager() {

	saveToFile();
	std::cout << std::endl << "File Manager: Saved snippets to " << this->file;

}

void fileManager::loadFromFile() {

	std::ifstream file(filename);
}