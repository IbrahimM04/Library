#pragma once
#include <string>
class addBook {
public:
	addBook();
	~addBook();

	void SetBook(std::string bookName);
	std::string GetBook();

	void SetUser(std::string userName);
	std::string GetUser();
private:
	std::string user;
	std::string book;
};

