#include <iostream>
#include <string>
#include <vector>
#include "snippetData.h"
#include "snippetManager.h"
#include "fileManager.h"
#include <sstream>
#include <algorithm>

void showMenu() {
    std::cout << "\n==== Code Snippet Manager ====\n";
    std::cout << "1. Add a snippet\n";
    std::cout << "2. View all snippets\n";
    std::cout << "3. Exit\n";
    std::cout << "> ";
}

int main() {

    fileManager fm("snippets.json");
    snippetManager sm;

    int choice;
    while (true) {
        
        showMenu();
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 1) {

            std::string title, lang, code, tagInput;
            std::vector<std::string> tags;
            std::cout << std::endl << "Enter title: ";
            getline(std::cin, title);

            std::cout << std::endl << "Enter language: ";
            getline(std::cin, lang);

            std::cout << std::endl << "Enter code: ";
            getline(std::cin, code);

            std::cout << std::endl << "Enter tags (Comma Separated): ";
            getline(std::cin, tagInput);
            tagInput.erase(remove_if(tagInput.begin(), tagInput.end(), ::isspace), tagInput.end());

            std::stringstream ss(tagInput);
            std::string tag;

            while (getline(ss, tag, ',')) {
                if (!tag.empty())
                    tags.push_back(tag);
            }

            SnippetData newSnippet{ title, lang, code, tags };
         
            std::vector<SnippetData> all_snippets = fm.getSnippets();
            all_snippets.push_back(newSnippet);
            fm.setSnippets(all_snippets);

            fm.saveToFile();

            std::cout << std::endl << "Snippet added succesfully";

        }

        else if (choice == 2) {

            std::vector<SnippetData> all_snippets = fm.getSnippets();
            if (all_snippets.empty()) {
                std::cout << std::endl << "No snippets found";
            }
            else {
                sm.showSnippets(all_snippets);
            }
        }
        else if (choice == 3) {
            std::cout << std::endl << "Exiting";
            break;
        }
        else {
            std::cout << std::endl << "Invalid choice.";
        }

    }
}