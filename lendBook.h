#pragma once
#include <string>
class lendBook {
public:
	lendBook();
	~lendBook();

	void SetBook(std::string aBook);
	std::string GetBook();
private:
	std::string book;
};

