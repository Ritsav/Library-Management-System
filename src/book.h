#ifndef BOOKINFO_H
#define BOOKINFO_H

#include<iostream>

class Book{
public:
    Book(std::string name, std::string author, std::string genre, int yearOfPublication) :
        name_ { name },
        author_ { author },
        genre_ { genre },
        yearOfPublication_ { yearOfPublication }
    {  }

    void displayBookInfo() const;
    void updateCount();
private:
    int yearOfPublication_;
    std::string name_;
    std::string genre_;
    std::string author_;
    int count_; // To count the no of same books
};

#endif