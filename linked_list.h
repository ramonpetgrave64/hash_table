//
// Created by Ramon Petgrave on 5/21/17.
//

#ifndef HASH_TABLE_LINKED_LIST_H
#define HASH_TABLE_LINKED_LIST_H

#include <cstdlib>
#include <iostream>

#include "hash_container.h"

namespace ramon_petgrave_hashtable {
    template<class Item>
    class linked_list;

    template<class Item>
    class list_node {
    private:
        Item data;
        list_node<Item> *next;
        list_node<Item> *prev;
        int key;
    public:
        friend void linked_list<Item>::remove(int key);
        list_node(int key, const Item& value, list_node<Item>* prev);
        bool has(int key);
        Item& value_at(int key);
        void add(int key, const Item& value);
        void remove_at(int key);
        void remove_self(); //remove self
        int get_key();
        list_node& get_next();
        friend std::ostream &operator<<(std::ostream &os, list_node<Item> &node) {
            os << "(" << node.key << "," << node.data << ")";
            return os;
        }
    };
    template<class Item>
    std::ostream &operator<<(std::ostream &os, list_node<Item> &n);

    template<class Item>
    class linked_list : public hash_container<Item>{
    public:
        linked_list();
        ~linked_list();
        void put(int key, const Item& value);
        Item& get(int key);
        void remove(int key);
        void clear();
        int top_key();
        void print(std::ostream& os);
    private:
        list_node<Item>* head;
    };
};
#include "linked_list.template"

#endif //HASH_TABLE_LINKED_LIST_H
