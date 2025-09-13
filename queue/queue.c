#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value){
    if(rear == MAX-1){
        printf("Queue is full\n");
        return ;
    }
    queue[++rear] = value;
    printf("Enqueued: %d\n", value);
    if(front == -1){
        front = 0;
    }
}

int dequeue(){
    if(front == -1){
        printf("Queue is empty\n");
        return -1;
    }
    printf("Returned: %d\n", queue[front++]);
    if(front>rear){
        front = -1;
        rear = -1;
    }
}

int front_ele(){
    if(front == -1){
        printf("Queue is empty\n");
        return -1;
    }
    printf("Front element: %d\n", queue[front]);
}

int display(){
    if(front == -1){
        printf("Queue is empty\n");
        return -1;
    }
    printf("Queue: ");
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int isEmpty(){
    return front == -1;
}
int isFull(){
    return rear == MAX - 1;
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    front_ele();
    display();
    dequeue();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
}