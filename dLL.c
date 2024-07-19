// write a program to create a singly Linked List
// https : // dpaste.org/Pr1mS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* createNode(int data)
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
    // int valueToReturn = temp->next->data;
    temp->next = NULL;
    // return valueToReturn;
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
    return;
}

void reverse(node** headPtr){
    if(*headPtr == NULL){
        printf("Linked List is Empty\n");
        return;
    }
    node* prev = NULL;
    node* current = *headPtr;
    node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headPtr = prev;
    return;
}

void display(node *head)
{
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

int main()
{
    node* head = NULL;
    // add element 12
    addElementAtLast(12, &head);
    addElementAtLast(13, &head);
    addElementAtLast(14, &head);
    // deleteElementAtLast(&head);
    // deleteElementAtLast(&head);
    // deleteElementAtLast(&head);
    display(head);
    // deleteElementAtLast(&head);
    search(head, 12);
    reverse(&head);
    display(head);

    return 0;
}