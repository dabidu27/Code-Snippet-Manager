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
		snippetManager() = default;
		void showSnippets(std::vector<SnippetData> snippets);
		std::vector<SnippetData> getSnippets();
		void filterByLanguage(std::vector<SnippetData> all_snippets, std::vector<SnippetData>& filtered);
		void filterByTag(std::vector<SnippetData> all_snippets, std::vector<SnippetData>& filtered);

};