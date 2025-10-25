# Code Snippet Manager

A lightweight, modular C++ console application for organizing and managing your personal code snippets.  
Each snippet includes a title, programming language, code body, and searchable tags — all saved persistently to a JSON file.

---

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Building and Running](#building-and-running)
- [Usage](#usage)
  - [Menu Options](#menu-options)
  - [Filtering Snippets](#filtering-snippets)
- [Persistence](#persistence)
- [Extending for Web or API](#extending-for-web-or-api)
- [Contributing](#contributing)
- [License](#license)

---

## Overview

Code Snippet Manager is a command-line tool built with C++20 that helps developers keep track of their reusable code snippets.  
Each entry is stored in a structured JSON file with attributes like title, language, code, and tags — making it easy to search, filter, and extend.

The app uses a modular OOP design for clarity and scalability:
- `SnippetData` — represents a single snippet  
- `SnippetManager` — manages snippet operations  
- `FileManager` — handles loading and saving from JSON  

---

## Features

- Add new code snippets with title, language, code, and tags  
- View all saved snippets  
- Filter snippets by language or tag
- Edit snippets and delete no longer wanted ones
- Persistent local JSON storage (`snippets.json`)  
- Modular architecture for easy extension  


---

## Project Structure

/code_snippet_manager/

├── main.cpp # Entry point (CLI menu)

├── snippetData.h # Struct for snippet info

├── snippetManager.h/.cpp # Handles snippet operations

├── fileManager.h/.cpp # Handles JSON persistence

├── json.hpp # nlohmann/json library (header-only)

├── snippets.json # Generated JSON data file

└── README.md # Project documentation


---

## Getting Started

### Prerequisites

You’ll need:
- A C++20 compiler (e.g. `g++`, `clang++`, or MSVC)
- The [`nlohmann/json`](https://github.com/nlohmann/json) header file (included in repo as `json.hpp`)
- Command-line tools or IDE (VS Code, CLion, Visual Studio, etc.)

---

### Building and Running

1. **Clone the repository**
   ```bash
   git clone https://github.com/dabidu27/Code-Snippet-Manager.git
   cd Code-Snippet-Manager/code_snippet_manager

    Compile

g++ main.cpp snippetManager.cpp fileManager.cpp -std=c++17 -o snippet_manager

Run

    ./snippet_manager

    The program will automatically create snippets.json in the same directory.

Usage
Menu Options

When you launch the program, you’ll see:

==== Code Snippet Manager ====
1. Add a snippet
2. View all snippets
3. Filter snippets
4. Edit snippet
5. Delete snippet
6. Exit
>

    Add a snippet — Enter the snippet’s title, language, code, and comma-separated tags.

    View all snippets — Displays all snippets stored in the JSON file.

    Filter snippets — Choose to filter by language or tag to narrow down results.

    Edit snippet - Modify the details of an already saved snippet

    Delete snippet - Delete a snipped that you no longer want stored

    Exit — Quits the program safely.

Filtering Snippets

You can filter snippets by language or tag:

Example:

Filter by:
1. Language
2. Tag
>

After choosing an option:

    All available languages or tags are listed.

    You enter one value.

    Only snippets matching your choice are shown.

Persistence

All data is stored in a single JSON file: snippets.json.
Example structure:

[
  {
    "title": "For Loop Example",
    "language": "C++",
    "code": "for(int i = 0; i < n; i++) cout << i;",
    "tags": ["loop", "example", "beginner"]
  },
  {
    "title": "Reverse String",
    "language": "Python",
    "code": "print('hello'[::-1])",
    "tags": ["string", "python"]
  }
]

The FileManager class automatically:

    Loads snippets from file at startup

    Saves new snippets after addition

    Keeps in-memory data synced with JSON file

Extending for Web or API

Because of its modular design, this app can easily evolve into a web-based code manager.
Possible Extensions:

    Build a Flask or Node.js REST API to serve snippets from JSON.

    Add endpoints:

        GET /snippets – View all snippets

        POST /snippets – Add a snippet

        DELETE /snippets/{id} – Remove a snippet

    Use a React or Vue frontend for a browser interface.

    Upgrade persistence to SQLite or MongoDB for scalability.

Contributing

Contributions are welcome.
Here’s how you can help:

    Fork the repository

    Create your feature branch

git checkout -b feature/edit-feature

Commit your changes

git commit -m "Added edit snippet functionality"

Push your branch

    git push origin feature/edit-feature

    Open a Pull Request

You can contribute new features, fix bugs, or improve documentation.
License

This project is licensed under the MIT License.
