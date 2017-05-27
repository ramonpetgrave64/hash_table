//
// Created by Ramon Petgrave on 5/20/17.
//

#ifndef HASH_TABLE_BST_H
#define HASH_TABLE_BST_H

#include <iostream>

using std::ostream;
using std::endl;

namespace ramon_petgrave_hashtable {
    template<class Item>
    class tree_node {
    public:
        tree_node(int key, const Item &value, tree_node<Item>* up_ptr);
        int get_key() const;
        Item &get_value();
        void add(int key, const Item &value);
        Item& value_at(int key);
        tree_node<Item>& node_at(int key);
        void print_tree_view(size_t level) const;
        bool has_key(int key) const;
        void remove_self(); //remove self
        void remove(int key);
        tree_node& leftmost();
        tree_node<Item>& rightmost();
        void tree_stream(ostream &os);
        friend ostream &operator<<(ostream &os, tree_node<Item> &node) {
            os << "(" << node.get_key() << "," << node.get_value() << ")";
            return os;
        }
    private:
        int key;
        Item value;
        tree_node *up_node;
        tree_node *left_node;
        tree_node *right_node;
    };
    template<class Item>
    ostream &operator<<(ostream &os, tree_node<Item> &node);

    template<class Item>
    class bst {
        private:
            tree_node<Item>* root;
            size_t tree_size;
            tree_node<Item>& leftmost();
            tree_node<Item>& rightmost();
        public:
            bst();
            ~bst();
            size_t size();
            void put(int key, Item value);
            Item& get(int key);
            void remove(int key);
            void print_tree_view();
            friend ostream &operator<<(ostream &os, bst<Item> &bst) {
                os << "[BST: ";
                if (bst.root !=  NULL) {
                    bst.root->tree_stream(os);
                }
                os << "]";
                return os;
            };
            int top_key();
    };
    template<class Item>
    ostream &operator<<(ostream &os, bst<Item> &node);
}
#include "bst.template"
#endif //HASH_TABLE_BST_H