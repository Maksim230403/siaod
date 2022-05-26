#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node* left, * right;
};

void Push(int value, Node** t)
{
    if ((*t) == NULL)
    {
        (*t) = new Node();
        (*t)->info = value;
        (*t)->left = (*t)->right = NULL;

        return;
    }
    if (value > (*t)->info) 
    {
        Push(value, &(*t)->right);
    }
    else 
    { 
        Push(value, &(*t)->left); 
    }
}


void Print(Node* t, int deepth)
{
    if (t == NULL) 
    { 
        return;
    }
    else
    {
        Print(t->left, ++deepth);
        for (int i = 0; i < deepth;
            ++i, cout << "|");
        cout << t->info << endl;
        deepth--;
    }
    Print(t->right, ++deepth);
}

int main()
{
    setlocale(0, "");

    Node* tree = NULL;
    int count, value;
    cout << "nodes count = ";
    cin >> count;

    for (int i = 0; i < count; ++i)
    {
        cout << "node value = ";
        cin >> value;

        Push(value, &tree);
    }
    cout << "\n";
    Print(tree, 0);
}
