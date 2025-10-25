#include <iostream>
#include <string>
#include <vector>
#include "snippetManager.h"
using namespace std;




int main() {

	std::string title = "My first snippet";
	std::string lang = "English";
	std::string code = "for(int i = 0; i<n; i++) cout << i ";
	std::vector <std::string> tags;
	std::string tag1 = "Loop";
	std::string tag2 = "for";
	tags.push_back(tag1);
	tags.push_back(tag2);

	snippetManager snippet = snippetManager(title, lang, code, tags);
	snippet.addSnippet();
	snippet.showSnippets();

	return 0;
}