#include "hashmap.h"
#include "book.h"
#include "linked_list.h"
#include<memory>
#include<vector>

int main(){
    // Test Run ----- Temporary
    auto person = std::make_shared<LinkedList>("Bunny");
    LinkedList::start_ = person;

    // List of all the names to insert
    std::vector<std::string> names{"Usagi", "Neko", "Kimiko"};
    
    // Insert all the names using the same variable
    for(const auto& name: names){
        auto person = std::make_shared<LinkedList>(name);
        insert(person);
    }

    auto map = std::make_unique<HashMap<LinkedList>>();
    map->insert(LinkedList::start_);

    map->listAllBucketObjects(1);
}