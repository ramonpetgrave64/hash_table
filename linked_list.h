//
// Created by Ramon Petgrave on 5/21/17.
//

#ifndef HASH_TABLE_LINKED_LIST_H
#define HASH_TABLE_LINKED_LIST_H

#include <cstdlib>
#include <iostream>

namespace ramon_petgrave_hashtable {
    template<class Item>
    class linked_list;

    template<class Item>
    class node {
    private:
        Item data;
        node<Item> *next;
        node<Item> *prev;
        int key;
    public:
        friend void linked_list<Item>::remove(int key);
        node(int key, const Item& value, node<Item>* prev);
        bool has(int key);
        Item& value_at(int key);
        void add(int key, const Item& value);
        void remove_at(int key);
        void remove_self(); //remove self
        int get_key();
        node& get_next();
        friend std::ostream &operator<<(std::ostream &os, node<Item> &node) {
            os << "(" << node.key << "," << node.data << ")";
            return os;
        }
    };
    template<class Item>
    std::ostream &operator<<(std::ostream &os, node<Item> &n);

    template<class Item>
    class linked_list {
    public:
        linked_list();
        ~linked_list();
        size_t size();
        void put(int key, const Item& value);
        Item& get(int key);
        void remove(int key);
        void clear();
        friend std::ostream &operator<<(std::ostream &os, linked_list<Item> &list) {
            os << "[LL: ";
            for (node<Item>* cursor = list.head; cursor != NULL; cursor = &cursor->get_next()) {
                os << *cursor;
            }
            os << "]";
            return os;
        }
        int top_key();
    private:
        size_t used;
        node<Item>* head;
    };
    template<class Item>
    std::ostream &operator<<(std::ostream &os, linked_list<Item> &list);
};
#include "linked_list.template"

#endif //HASH_TABLE_LINKED_LIST_H
