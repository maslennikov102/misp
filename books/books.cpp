#include "books.h"
#include "fstream"

Book::Book() : title(""), author(""), publishYear(0) {}

Book::Book(const std::string &t, const std::string &a, unsigned y)
    :title(t), author(a), publishYear(y) {}

std::string Book::getTitle() const
{
    return title;
}

std::string Book::getAuthor() const
{
    return author;
}

unsigned Book::getYear() const
{
    return publishYear;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return ((lhs.getTitle() == rhs.getTitle()) && (lhs.getAuthor() == rhs.getAuthor()) 
	    && (lhs.getYear() == rhs.getYear()));
}

DBBooks::DBBooks() {}

bool DBBooks::addBook(const Book &book)
{
    for(const auto &b: books)
    {
        if (b == book)
	{
	    return false;
	}
    }
    books.push_back(book);
    return true;
}

static void sortBooksByAuthor(std::vector<Book> &vec)
{
    size_t n = vec.size();
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
	{
	    if(vec[j].getAuthor() > vec[j + 1].getAuthor())
	    {
	        Book temp = vec[j];
		vec[j] = vec[j + 1];
		vec[j + 1] = temp;
	    }
	}
    }
}

bool DBBooks::save(const std::string &fileName) const
{
    std::ofstream out(fileName);
    if (!out.is_open())
    {
        return false;
    }
    std::vector<Book> sorted = books;
    sortBooksByAuthor(sorted);
    bool firstGroup = true;
    size_t i = 0;
    while (i < sorted.size())
    {
        std::string currentAuthor = sorted[i].getAuthor();
	if(!firstGroup)
	{
	    out << std::endl;
	}
	firstGroup = false;
	out << currentAuthor << ":\n";
	while (i < sorted.size() && sorted[i].getAuthor() == currentAuthor)
	{
	    out << sorted[i].getTitle() << " " << sorted[i].getYear() << "\n";
	    i++;
	}
    }
    out.close();
    return true;
}


