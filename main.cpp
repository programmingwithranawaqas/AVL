#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node()
    {
        data = 0;
        left = right = NULL;
        height = 0;
    }
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
        height = 1;
    }
};

class AVL
{
public:
    Node* root;
    AVL()
    {
        root = NULL;
    }
    int Height(Node* temp)
    {
        if(temp==NULL)
            return 0;
        return temp->height;
    }
    int max(int a, int b)
    {
        if(a>b)
            return a;
        return b;
    }
    Node* rightRotation(Node *x)
    {
        Node* y = x->left;
        Node* T2 = y->right;

        y->right = x;
        x->left = T2;

        x->height = max(Height(x->left), Height(x->right))+1;
        y->height = max(Height(y->left), Height(y->right))+1;
        return y;
    }
    Node* leftRotation(Node *x)
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(Height(x->left), Height(x->right))+1;
        y->height = max(Height(y->left), Height(y->right))+1;
        return y;
    }
    int getBalanceFactor(Node* temp)
    {
        if(temp==NULL)
            return 0;
        return Height(temp->left) - Height(temp->right);
    }
    Node* insertNode(Node* temp, int data)
    {
        if(temp==NULL)
            return new Node(data);
        else if(temp->data > data)
        {
            temp->left = insertNode(temp->left, data);
        }
        else if(temp->data < data)
        {
            temp->right = insertNode(temp->right, data);
        }
        else
        {
            return temp;
        }

        temp->height = max(Height(temp->left), Height(temp->right))+1;

        int bf = getBalanceFactor(temp);

        if(bf == -2)
        {
            if(data>temp->right->data)
            {
                return leftRotation(temp);
            }
            else
            {
                temp->right = rightRotation(temp->right);
                return leftRotation(temp);
            }
        }
        if(bf == 2)
        {
            if(data < temp->left->data)
            {
                return rightRotation(temp);
            }
            else
            {
                temp->left = leftRotation(temp->left);
                return rightRotation(temp);
            }
        }
        return temp;

    }

    void print(Node* temp)
    {
        if(temp== NULL)
            return;
        print(temp->left);
        cout<<temp->data<<" , ";
        print(temp->right);
    }

};

int main()
{
    AVL avl;
    avl.root = avl.insertNode(avl.root, 33);
    avl.root = avl.insertNode(avl.root, 13);
    avl.root = avl.insertNode(avl.root, 53);
    avl.root = avl.insertNode(avl.root, 9);
    avl.root = avl.insertNode(avl.root, 21);
    avl.root = avl.insertNode(avl.root, 61);
    avl.root = avl.insertNode(avl.root,8);
    avl.root = avl.insertNode(avl.root, 11);
    avl.root = avl.insertNode(avl.root, 7);
    avl.print(avl.root);

    return 0;
}
