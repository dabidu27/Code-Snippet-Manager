#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "snippetData.h"
#include <fstream>

class fileManager {

	private:

	std::string filename;
	std::vector <SnippetData> snippets;

	public:

		fileManager(std::string file = "snippets.json");
		//~fileManager();
		std::vector<SnippetData> getSnippets();
		void setSnippets(std::vector<SnippetData> newSnippets);
		void saveToFile();

	private:

		void loadFromFile();

};