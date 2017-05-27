//
// Created by Ramon Petgrave on 5/21/17.
//

#ifndef HASH_TABLE_HASH_CONTAINER_H
#define HASH_TABLE_HASH_CONTAINER_H

#include "bst.h"
#include "linked_list.h"

namespace ramon_petgrave_hashtable {
    template<class Item>
    class hash_bucket {
    public:
        hash_bucket();
        hash_bucket(int key, const Item& data);
        ~hash_bucket();
        size_t size();
        void put(int key, const Item& value);
        Item& get(int key);
        void remove(int key);
        void switch_to_bst();
        void switch_to_ll();
        int top_key();
        friend std::ostream &operator<<(std::ostream &os, hash_bucket<Item> &bucket) {
            if (bucket.list != NULL) {
                os << *bucket.list;
            } else {
                os << *bucket.tree;
            }
            return os;
        }
    private:
        linked_list<Item>* list;
        bst<Item>* tree;
        size_t upper_limit = 8;
        size_t lower_limit = 6;
    };
    template<class Item>
    std::ostream &operator<<(std::ostream &os, hash_bucket<Item> &bucket);
}

#include "hash_bucket.template"

#endif //HASH_TABLE_HASH_CONTAINER_H
