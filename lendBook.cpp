#include "lendBook.h"

lendBook::lendBook() {
}

lendBook::~lendBook() {
}

void lendBook::SetBook(std::string aBook) {
	book = aBook;
}

std::string lendBook::GetBook() {
	return book;
}
