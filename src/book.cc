#include "book.h"

void Book::displayBookInfo() const
{
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Author: " << author_ << std::endl;
    std::cout << "Genre: " << genre_ << std::endl;
    std::cout << "Date of Publication: " << yearOfPublication_ << std::endl;
}

void Book::updateCount()
{
    // TODO: While searching for a book, if we find the book already in our AVL,
    // then, update the count of the book while in the node by calling onto this function from that object

    count_++;
}