// write a program to create a doubly Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
} node;

node* createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addElementAtLast(int data, node **headPtr)
{
    node *newNode = createNode(data);
    if (*headPtr == NULL)
    {
        *headPtr = newNode;
        return;
    }
    node* temp = *headPtr;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return;
}


void deleteElementAtLast(node** headPtr){
    if(*headPtr == NULL){
        printf("Linked List is Empty\n");
        return;
    }
    node* temp = *headPtr;
    if(temp->next == NULL){
        *headPtr = NULL;
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
    return;
}


void search(node* head, int data){
    if(head == NULL){
        printf("Linked List is Empty\n");
        return;
    }
    node* temp = head;
    while(temp != NULL){
        if(temp->data == data){
            printf("Element Found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element Not Found\n");
}

void reverse(node** headPtr){
    if(*headPtr == NULL){
        printf("Linked List is Empty\n");
        return;
    }
    node* temp = *headPtr;
    node* prev = NULL;
    node* next = NULL;
    while(temp != NULL){
        next = temp->next;
        temp->next = prev;
        temp->prev = next;
        prev = temp;
        temp = next;
    }
    *headPtr = prev;
    return;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    node* head = NULL;
    // add element 12
    addElementAtLast(12, &head);
    addElementAtLast(13, &head);
    addElementAtLast(14, &head);
    display(head);
    deleteElementAtLast(&head);
    
    display(head);

    search(head, 12);
    search(head, 111);
    
    addElementAtLast(15, &head);
    reverse(&head);
    display(head);

    return 0;
}