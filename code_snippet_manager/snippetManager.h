#pragma once
#include <string>
#include "snippetData.h"
#include <vector>


class snippetManager {

	private:

		SnippetData snippet;
		std::vector<SnippetData> snippets;

	public:
		snippetManager(std::string title, std::string lang, std::string code, std::vector<std::string> tags);
		void addSnippet();
		void showSnippets();

};