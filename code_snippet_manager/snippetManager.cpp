#include <iostream>
#include <string>
#include <vector>
#include "snippetManager.h"
#include <set>


snippetManager::snippetManager(std::string title, std::string lang, std::string code, std::vector<std::string> tags) {

	this->snippet.title = title;
	this->snippet.lang = lang;
	this->snippet.code = code;
	this->snippet.tags = tags;
	snippets.push_back(this->snippet);

}

void snippetManager::showSnippets(std::vector<SnippetData> snippets) {
	
	for (const auto& s : snippets) {
		
		std::cout << std::endl << s.title << std::endl << s.code << std::endl << s.lang <<std::endl;
		for (const auto& tag : s.tags) {
			std::cout << tag << " ";
		}
		std::cout << std::endl;
	}
}


std::vector<SnippetData>snippetManager::getSnippets() {

	return snippets;
}

void snippetManager::filterByLanguage(std::vector<SnippetData> all_snippets, std::vector<SnippetData>& filtered) {

	
	std::set<std::string> languages;
	for (const auto& s : all_snippets) {
		languages.insert(s.lang);
	}

	std::cout << std::endl << "Languages: ";
	for (const auto& l : languages) {
		std::cout << std::endl << l;
	}

	std::cout << std::endl << "Enter language: ";
	
	std::cout << std::endl;
	std::string lang;
	getline(std::cin, lang);

	for (const auto& s : all_snippets) {
		if (s.lang == lang)
			filtered.push_back(s);
	}
	
}
void snippetManager::filterByTag(std::vector<SnippetData> all_snippets, std::vector<SnippetData>& filtered) {

	std::set<std::string> tags;
	for (const auto& s : all_snippets) {
		for (const auto& t : s.tags)
			tags.insert(t);
	}

	std::cout << std::endl << "Tags: ";
	for (const auto& t : tags) {
		std::cout << std::endl << t;
	}

	std::cout << std::endl << "Enter tag: ";
	
	std::cout << std::endl;
	std::string tag;
	getline(std::cin, tag);

	for (const auto& s : all_snippets) {
		for (const auto& t : s.tags)
			if (t == tag) {
				filtered.push_back(s);
				break;
			}

	}

}