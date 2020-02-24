#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

const int NO_ELEM = -1;

template <typename T1, typename T2>
struct Node {
    T1 key;
    T2 val;          // данные в узле
    size_t repeat;
    Node <T1, T2> *left;  // левый ребенок
    Node <T1, T2> *right; // правый ребенок
    Node <T1, T2> *parent;
};

template <typename T1, typename T2>
class mymap {
public:
    void insert (T1 key, T2 val);
    T2 find (T1 key);
    size_t count (T1 key);
    void clear ();
    void print ();
    int erase (T1 key);
    size_t size ();
    mymap ();
    ~mymap ();
    T2 &operator[] (T1 key);
private:
    Node <T1, T2> *tree_add (Node <T1, T2> *tree, Node <T1, T2> *parent, T1 key, T2 val);
    void tree_destroy (Node <T1, T2> *tree);
    void tree_print (Node <T1, T2> *tree);
    Node <T1, T2> *tree_find (Node <T1, T2> *tree, T1 key);

    Node <T1, T2> *TREE;
    Node <T1, T2> *last_added;
    size_t sz;
    T2 NOT_FOUND;
};

#include "map.cpp"

#endif // TREE_H_INCLUDED
