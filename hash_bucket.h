//
// Created by Ramon Petgrave on 5/21/17.
//

#ifndef HASH_TABLE_HASH_CONTAINER_H
#define HASH_TABLE_HASH_CONTAINER_H

#include "hash_container.h"
#include "bst.h"
#include "linked_list.h"

namespace ramon_petgrave_hashtable {
    template<class Item>
    class hash_bucket : public hash_container<Item> {
    public:
        hash_bucket();
        ~hash_bucket();
        size_t size();
        void put(int key, const Item& value);
        Item& get(int key);
        void remove(int key);
        void switch_cont_type();
        int top_key();
        void print(std::ostream& os);
    private:
        hash_container<Item>* container;
        bool is_ll;
        size_t upper_limit = 8;
        size_t lower_limit = 6;
    };
}

#include "hash_bucket.template"

#endif //HASH_TABLE_HASH_CONTAINER_H
