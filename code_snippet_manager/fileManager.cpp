#include <string>
#include "fileManager.h"
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;




fileManager::fileManager(std::string filename) {

	this->filename = filename;
	loadFromFile();
	std::cout << std::endl << "File Manager: Loaded snippets from " << this->filename;

}

fileManager::~fileManager() {

	saveToFile();
	std::cout << std::endl << "File Manager: Saved snippets to " << this->filename;

}

void fileManager::loadFromFile() {

	std::ifstream file(this->filename);
	if (!file.is_open()) {
		std::cerr << std::endl << "Warning: Could not open " << this->filename;
		snippets.clear();
		return;
	}

	json j_snippets;
	file >> j_snippets;
	snippets.clear();

	for (const auto& j : j_snippets) {

		SnippetData s;
		s.title = j.at("title").get<std::string>();
		s.lang = j.at("language").get<std::string>();
		s.code = j.at("code").get<std::string>();
		s.tags = j.at("tags").get<std::vector<std::string>>();
		snippets.push_back(s);
	}
}

void fileManager::saveToFile() {

	json j_snippets = json::array();
	for (const auto& s : snippets) {

		j_snippets.push_back({
		   {"title", s.title},
		   {"language", s.lang},
		   {"code", s.code},
		   {"tags", s.tags}
			});
	}

	std::ofstream file(this->filename);
	if (!file.is_open()) {
		std::cerr << std::endl << "Warning: Could not open " << this->filename << " for writing";
		return;
	}

	file << j_snippets.dump(4);
}

std::vector<SnippetData> fileManager::getSnippets() {
	return snippets;
}

void fileManager::setSnippets(std::vector<SnippetData> newSnippets) {

	snippets = newSnippets;
}