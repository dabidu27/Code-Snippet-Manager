#include <iostream>
#include <string>
#include <vector>
#include "snippetManager.h"


snippetManager::snippetManager(std::string title, std::string lang, std::string code, std::vector<std::string> tags) {

	this->snippet.title = title;
	this->snippet.lang = lang;
	this->snippet.code = code;
	this->snippet.tags = tags;

}

void snippetManager::addSnippet() {

	snippets.push_back(this->snippet);
}

void snippetManager::showSnippets() {
	
	for (const auto& s : snippets) {
		
		std::cout << std::endl << s.title << std::endl << s.code << std::endl << s.lang <<std::endl;
		for (const auto& tag : s.tags) {
			std::cout << tag << " ";
		}
	}
}