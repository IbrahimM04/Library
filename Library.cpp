#include <iostream>
#include <fstream>
#include <chrono>
#include "lendBook.h"
#include "addBook.h"
#include <experimental/filesystem>
#include <stdio.h>
#include <algorithm>

int main() {
	std::string path = "books\\";

	lendBook* lendedBook = new lendBook();
	addBook* addedBook = new addBook();
	
	std::string input;
	int choice;
	std::string filename;
	std::ofstream file;
	std::ifstream fin;
	
	char chars[] = "\\\/:*<>|";

	while (true) {
		std::cout << "Choose what you want to do:" << std::endl;
		std::cout << "1: Add a book to the library" << std::endl;
		std::cout << "2: Lend a book from the library" << std::endl;
		std::cout << "3: Leave" << std::endl;
		std::getline(std::cin, input);
		system("CLS");

		choice = std::stoi(input);

		switch (choice) {
		case 1:
			std::cout << "What is the name of the book you'd like to add? \n";
			std::getline(std::cin, input);
			for (unsigned int i = 0; i < strlen(chars); i++) {
				input.erase (std::remove(input.begin(), input.end(), chars[i]));
			}
			addedBook->SetBook(input);
			std::cout << "Who added this book? (What is your name) \n";
			std::getline(std::cin, input);
			addedBook->SetUser(input);
			std::cout << "Book was added!" << std::endl;
			
			system("CLS");

			filename = path + addedBook->GetBook();
			file.open(filename);

			file << "This is the book called: " << addedBook->GetBook() << std::endl
				<< "This book was added by: " << addedBook->GetUser() << std::endl;
			file.close();
			break;
		case 2:
			if (!std::experimental::filesystem::is_empty(path)) {
				std::cout << "Here are some books you may lend: " << std::endl;
				for (const auto& entry : std::experimental::filesystem::directory_iterator(path)) {
					std::cout << entry.path().filename().string() << std::endl;
				}
				std::cout << std::endl << "Which book would you want to lend?" << std::endl;
				std::getline(std::cin, input);
				if (!input.empty()) {
					std::experimental::filesystem::remove(path + input);
				}
				system("CLS");
			} else {
				std::cout << "No books in the library" << std::endl << std::endl;
			}


			break;
		case 3:
			return 0;
		default:
			break;
		}
	}
}

