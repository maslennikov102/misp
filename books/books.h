#pragma once
#include <string>
#include <vector>
class Book
{
    private:
        std::string title;
	std::string author;
	unsigned publishYear;
    public:
        Book();
	Book(const std::string &n, const std::string &a, unsigned year);

	std::string getTitle() const;
	std::string getAuthor() const;
	unsigned getYear() const;
};
bool operator==(const Book &lhs, const Book &rhs);
class DBBooks
{
    private:
	std::vector<Book> books;
    public:
	DBBooks();
	bool addBook(const Book &book);
	bool save(const std::string &fileName) const;
};



