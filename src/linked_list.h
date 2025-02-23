#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<iostream>
#include<string>

class LinkedList{
public:
    inline static std::shared_ptr<LinkedList> start_ = nullptr; 

    LinkedList(std::string name) :
        name_ { name },
        next_ { nullptr } 
    {  }

    char getInitialChar()
    {
        return name_[0];
    }

    void displayTree() const {
        auto tempStart = start_;

        while(tempStart != nullptr){
            std::cout << tempStart->name_ << std::endl;
            tempStart = tempStart->next_;
        }
    }

    friend void insert(std::shared_ptr<LinkedList>);
private:
    std::shared_ptr<LinkedList> next_;
    std::string name_;
};

void insert(std::shared_ptr<LinkedList> temp)
{
    auto tempStart = LinkedList::start_;

    while(tempStart->next_ != NULL){
        tempStart = tempStart->next_;
    }

    tempStart->next_ = temp;
}

#endif