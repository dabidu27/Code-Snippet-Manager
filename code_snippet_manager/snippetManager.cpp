#include <iostream>
#include <string>
#include <vector>
#include "snippetManager.h"
#include <set>
#include <sstream>


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

void snippetManager::editSnippet(std::vector<SnippetData>& snippets) {
	if (snippets.empty()) {
		std::cout << "\nNo snippets to edit.\n";
		return;
	}

	std::cout << "\nAvailable snippets:\n";
	for (size_t i = 0; i < snippets.size(); ++i) {
		std::cout << i + 1 << ". " << snippets[i].title << "\n";
	}

	std::cout << "\nEnter snippet number to edit: ";
	int choice;
	std::cin >> choice;
	std::cin.ignore();

	if (choice < 1 || choice >(int)snippets.size()) {
		std::cout << "Invalid choice.\n";
		return;
	}

	SnippetData& s = snippets[choice - 1];

	std::cout << "\nEditing snippet: " << s.title << "\n";

	std::string newTitle, newLang, newCode;
	std::vector<std::string> newTags;
	std::string tagInput;

	std::cout << "New title (leave empty to keep current): ";
	getline(std::cin, newTitle);
	if (!newTitle.empty()) s.title = newTitle;

	std::cout << "New language (leave empty to keep current): ";
	getline(std::cin, newLang);
	if (!newLang.empty()) s.lang = newLang;

	std::cout << "New code (leave empty to keep current): ";
	getline(std::cin, newCode);
	if (!newCode.empty()) s.code = newCode;

	std::cout << "New tags (comma separated, leave empty to keep current): ";
	getline(std::cin, tagInput);

	if (!tagInput.empty()) {
		newTags.clear();
		tagInput.erase(remove_if(tagInput.begin(), tagInput.end(), ::isspace), tagInput.end());
		std::stringstream ss(tagInput);
		std::string tag;
		while (getline(ss, tag, ',')) {
			if (!tag.empty()) newTags.push_back(tag);
		}
		s.tags = newTags;
	}

	std::cout << "\nSnippet updated successfully.\n";
}

void snippetManager::deleteSnippet(std::vector<SnippetData>& snippets) {
	if (snippets.empty()) {
		std::cout << "\nNo snippets to delete.\n";
		return;
	}

	std::cout << "\nAvailable snippets:\n";
	for (size_t i = 0; i < snippets.size(); ++i) {
		std::cout << i + 1 << ". " << snippets[i].title << "\n";
	}

	std::cout << "\nEnter snippet number to delete: ";
	int choice;
	std::cin >> choice;
	std::cin.ignore();

	if (choice < 1 || choice >(int)snippets.size()) {
		std::cout << "Invalid choice.\n";
		return;
	}

	std::cout << "Deleting: " << snippets[choice - 1].title << "\n";
	snippets.erase(snippets.begin() + (choice - 1));

	std::cout << "Snippet deleted successfully.\n";
}