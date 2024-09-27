
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node* root = NULL;
node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addElement(int data){
    node* newNode = createNode(data);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    node* temp = root;
    while (1)
    {
        if (data < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            temp = temp->left;
        }
        else
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            temp = temp->right;
        }
    }
}

void deleteElement(int data){
    if (root == NULL)
    {
        printf("Binary Search Tree is Empty\n");
        return;
    }
    node* temp = root;
    node* parent = NULL;
    while (temp != NULL)
    {
        if (data < temp->data)
        {
            parent = temp;
            temp = temp->left;
        }
        else if (data > temp->data)
        {
            parent = temp;
            temp = temp->right;
        }
        else   // data == temp->data, element found
        {
            break;
        }
    }
    if (temp == NULL)
    {
        printf("Element not found in Binary Search Tree\n");
        return;
    }
    if (temp->left == NULL && temp->right == NULL)
    {
        if (parent == NULL)
        {
            root = NULL;
            
            return;
        }
        if (parent->left == temp)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        
        return;
    }

    if (temp->left == NULL || temp->right == NULL)
    {
        if (parent == NULL)
        {
            if (temp->left != NULL)
            {
                root = temp->left;
            }
            else
            {
                root = temp->right;
            }
            
            return;
        }
        if (parent->left == temp)
        {
            if (temp->left != NULL)
            {
                parent->left = temp->left;
            }
            else
            {
                parent->left = temp->right;
            }
        }
        else
        {
            if (temp->left != NULL)
            {
                parent->right = temp->left;
            }
            else
            {
                parent->right = temp->right;
            }
        }
        
        return;
    }

    node* successor = temp->right;
    parent = temp;
    while (successor->left != NULL)
    {
        parent = successor;
        successor = successor->left;
    }
    temp->data = successor->data;
    if (parent->left == successor)
    {
        parent->left = successor->right;
    }
    else
    {
        parent->right = successor->right;
    }
    
    return;
}

void search(int key){
    if(root == NULL){
        printf("Binary Search Tree is Empty\n");
        return;
    }
    node* temp = root;
    while(temp != NULL){
        if(temp->data == key){
            printf("Element Found\n");
            return;
        }
        if(key < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    printf("Element Not Found\n");
    return;
}

void inOrderTraversal(node* temp){
    if(temp == NULL){
        return;
    }
    
    inOrderTraversal(temp->left);
    printf("%d ", temp->data);
    inOrderTraversal(temp->right);
}




int main()
{
    addElement(10);
    addElement(5);
    addElement(15);
    addElement(3);
    addElement(7);
    addElement(12);
    addElement(18);
    // search(15);
    search(18);
    // deleteElement(15);
    // search(21);
    
    deleteleaf(18);
    search(18);
    inOrderTraversal(root);
    printf("\n");
    deleteleaf(15);
    inOrderTraversal(root);
    printf("\n");

    return 0;
}