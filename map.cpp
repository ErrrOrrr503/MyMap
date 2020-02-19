template <typename T1, typename T2>
mymap<T1, T2>::mymap ()
{
    TREE = nullptr;
    sz = 0;
    NOT_FOUND = {};
}

template <typename T1, typename T2>
mymap<T1, T2>::~mymap ()
{
    tree_destroy(TREE);
    TREE = nullptr;
    sz = 0;
}

template <typename T1, typename T2>
Node <T1, T2> * mymap<T1, T2>::tree_add (Node <T1, T2> *tree, Node <T1, T2> *parent, T1 key, T2 val)
{
    if (tree == nullptr) {
        tree = new Node <T1, T2>;
        tree->key = key;
        tree->val = val;
        tree->repeat = 1;
        tree->left = nullptr;
        tree->right = nullptr;
        tree->parent = parent;
        return tree;
    }
    if (key > tree->key)
        tree->right = tree_add (tree->right, tree, key, val);
    if (key < tree->key)
        tree->left = tree_add (tree->left, tree, key, val);
    if (key == tree->key) {
        if (val == tree->val)
            tree->repeat++;
        else
            tree->val = val;
    }
    return tree;
}

template <typename T1, typename T2>
void mymap<T1, T2>::tree_print (Node <T1, T2> * tree)
{
    if (tree == nullptr)
        return;
    std::cout << "key = " << tree->key << " val = " << tree->val << " repeated " << tree->repeat << " times" << std::endl;
    if (tree->left != nullptr)
        tree_print (tree->left);
    if (tree->right != nullptr)
        tree_print (tree->right);
}

template <typename T1, typename T2>
void mymap<T1, T2>::tree_destroy (Node <T1, T2> *tree)
{
    if (tree == nullptr)
        return;
    if (tree->left != nullptr)
        tree_destroy (tree->left);
    if (tree->right != nullptr)
        tree_destroy (tree->right);
    delete tree;
}

template <typename T1, typename T2>
Node <T1, T2> * mymap<T1, T2>::tree_find (Node <T1, T2> *tree, T1 key)
{
    if (tree == nullptr)
        return nullptr;
    if (key > tree->key)
        return tree_find (tree->right, key);
    if (key < tree->key)
        return tree_find (tree->left, key);
    if (key == tree->key)
        return tree;
    return nullptr;
}

template <typename T1, typename T2>
void mymap<T1, T2>::insert (T1 key, T2 val)
{
    TREE = tree_add (TREE, nullptr, key, val);
    sz++;
}

template <typename T1, typename T2>
void mymap<T1, T2>::clear ()
{
    tree_destroy (TREE);
    sz = 0;
}

template <typename T1, typename T2>
void mymap<T1, T2>::print ()
{
    tree_print (TREE);
    std::cout << std::endl;
}

template <typename T1, typename T2>
T2 mymap<T1, T2>::find (T1 key)
{
    Node <T1, T2> *found = tree_find (TREE, key);
    if (found != nullptr)
        return found->val;
    return NOT_FOUND;
}

template <typename T1, typename T2>
size_t mymap<T1, T2>::count (T1 key)
{
    Node <T1, T2> *found = tree_find (TREE, key);
    if (found != nullptr)
        return found->repeat;
    return 0;
}

template <typename T1, typename T2>
size_t mymap<T1, T2>::size ()
{
    return sz;
}

template <typename T1, typename T2>
int mymap<T1, T2>::erase (T1 key)
{
    Node <T1, T2> *erasing = nullptr, *swapping = nullptr;
    erasing = tree_find (TREE, key);
    if (erasing == nullptr)
        return NO_ELEM;
    sz--;
    if (erasing->right != nullptr) {
        swapping = erasing->right;
        while (swapping->left != nullptr)
            swapping = swapping->left;
        erasing->val = swapping->val;
        erasing->key = swapping->key;
        erasing->repeat = swapping->repeat;
        if (swapping->parent == erasing)
            erasing->right = swapping->right;
        if (swapping->parent->left == swapping)
            swapping->parent->left = swapping->right;
        delete swapping;
        return 0;
    }
    if (erasing->left != nullptr) {
        swapping = erasing->left;
        erasing->val = swapping->val;
        erasing->key = swapping->key;
        erasing->repeat = swapping->repeat;
        erasing->left = swapping->left;
        erasing->right = swapping->right;
        delete swapping;
        return 0;
    }
    if (erasing->parent->left == erasing)
        erasing->parent->left = nullptr;
    if (erasing->parent->right == erasing)
        erasing->parent->right = nullptr;
    delete erasing;
    return 0;
}
