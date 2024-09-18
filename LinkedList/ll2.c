// write a program to create a singly Linked List
// https://dpaste.org/LiLwx
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node* head = NULL;

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addElementAtLast(int data)
{
    node* newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node* last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    return;
}

void deleteElementAtLast()
{
    if (head == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    node *temp = head;
    if (temp->next == NULL)
    {
        head = NULL;
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

void search(int data){
    if(head == NULL){
        printf("No element in Linked List\n");
    }

    node* temp = head;
    while (temp != NULL){
        if(temp->data == data){
            printf("Data Found in given Linked List\n");
            return;
        }
        temp = temp->next;
    }

    printf("%d Not found in your linked List\n", data);
}

// void reverse(){
    
// }

void display(){
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
    
    // add element 12
    addElementAtLast(12);
    addElementAtLast(13);
    addElementAtLast(14);
    addElementAtLast(15);
    addElementAtLast(16);
    addElementAtLast(17);
    // deleteElementAtLast(&head);
    // deleteElementAtLast(&head);
    // deleteElementAtLast(&head);
    display(head);
    search(15);
    search(13);
    // reverse(&head);

    return 0;
}