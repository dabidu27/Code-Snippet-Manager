#include <iostream>
#include <string>
#include <vector>
#include "snippetData.h"
#include "snippetManager.h"
#include "fileManager.h"
#include <sstream>
#include <algorithm>
#include <set>

void showMenu() {
    std::cout << "\n==== Code Snippet Manager ====\n";
    std::cout << std::endl << "1. Add a snippet";
    std::cout << std::endl << "2. View all snippets";
    std::cout << std::endl << "3. Filter snippets";
    std::cout << std::endl << "4. Edit a snippet";
    std::cout << std::endl << "5. Delete a snippet";
    std::cout << std::endl << "6. Exit";
    std::cout << std::endl << "> ";
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

            std::vector<SnippetData> all_snippets = fm.getSnippets();
            if (all_snippets.empty()) {

                std::cout << std::endl << "No snippets available to filter";
                continue;
            }
            
            std::cout << std::endl << "Filter by: ";
            std::cout << std::endl << "1. Language";
            std::cout << std::endl << "2. Tag";

            int filter_choice = 0;
            std::cin >> filter_choice;
            std::cin.ignore();

            std::vector<SnippetData> filtered;

            if (filter_choice == 1) {

                sm.filterByLanguage(all_snippets, filtered);
            }

            else if (filter_choice == 2) {

                sm.filterByTag(all_snippets, filtered);
            }
            else {
                std::cout << std::endl << "Invalid filter choice";
            }
            if (filtered.empty())
                std::cout << std::endl << "No snippets found for this filter";
            else
                sm.showSnippets(filtered);
        }

        else if (choice == 4) {

            auto snippets = fm.getSnippets();
            sm.editSnippet(snippets);
            fm.setSnippets(snippets);
            fm.saveToFile();

        }

        else if (choice == 5) {

            auto snippets = fm.getSnippets();
            sm.deleteSnippet(snippets);
            fm.setSnippets(snippets);
            fm.saveToFile();

        }

        else if (choice == 6) {
            std::cout << std::endl << "Exiting";
            break;
        }

        else {
            std::cout << std::endl << "Invalid choice.";
        }

    }
}