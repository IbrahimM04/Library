#include "addBook.h"

addBook::addBook() {
}

addBook::~addBook() {
}

void addBook::SetBook(std::string bookName) {
	book = bookName;
}

std::string addBook::GetBook() {
	return book;
}

void addBook::SetUser(std::string userName) {
	user = userName;
}

std::string addBook::GetUser() {
	return user;
}
