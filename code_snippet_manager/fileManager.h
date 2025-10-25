#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "snippetData.h"
#include <ifstream>

class fileManager {

	private:

	std::string file;
	std::vector <SnippetData> snippets;

	public:

		fileManager(std::string file = "snippets.json");
		~fileManager();

	private:

		void loadFromFile();




};