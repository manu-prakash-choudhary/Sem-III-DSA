// write a program to create a singly Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
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

    node *last = *headPtr;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    return;
}

void deleteElementAtLast(node **headPtr)
{
    if (*headPtr == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    node *temp = *headPtr;
    if (temp->next == NULL)
    {
        *headPtr = NULL;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    // int valueToReturn = temp->next->data;
    temp->next = NULL;
    // return valueToReturn;
    return;
}

void search(node* head, int key){

    if(head == NULL){
        printf("Linked List is Empty\n");
        return;
    }

    node* temp = head;

    while(temp != NULL){
        if (temp->data == key)
        {
            printf("Element with value %d Found\n", key);
            // break;
            return;
        }
        temp = temp->next;
    }

    printf("Element with value %d is Not Found\n", key);
    return;
}

void reverse(node **headPtr){


    node* prev = NULL;
    node* crr = *headPtr;
    node* next;

    while (crr != NULL){
        next = crr->next;
        crr->next = prev;
        prev = crr;
        crr = next;
    }
    *headPtr = prev;
}

void display(node *head){
    if (head == NULL)
    {
        printf("No Elements to Display\n");
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    return;
}

int main(){
    node* head = NULL;
    // add element 12
    addElementAtLast(12, &head);
    addElementAtLast(13, &head);
    addElementAtLast(14, &head);
    
    addElementAtLast(16, &head);
    addElementAtLast(17 , &head);

    printf("Linked list before Reverse operation -\n");
    display(head);

    reverse(&head);

    printf("\n");
    printf("Linked list after Reverse operation -\n");
    display(head);

    return 0;
}