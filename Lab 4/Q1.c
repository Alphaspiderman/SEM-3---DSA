#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void enqueue();
void dequeue();
void display();
int front = -1, rear = -1, queue[MAX];

int main()
{
    int choice;
    while (1)
    {
        printf("\nFunctions of Queue:\n1) Enqueue\n2) Dequeue\n3) Display\n4) End");
        printf("\n\nEnter choice -\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice");
            break;
        }
    }
}

void enqueue()
{
    if (rear == MAX - 1)
        printf("Queue Overflow");
    else
    {
        if (front == -1)
            front = 0;
        int element;
        printf("Enter element to be inserted - \n");
        scanf("%d", &element);
        rear++;
        queue[rear] = element;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
        printf("Queue Underflow");
    else
    {
        printf("Element  - %d", queue[front]);
        front++;
    }
}
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Empty Queue\n");
    }

    else
    {
        printf("The queue is:\n");
        for (int i = front; i <= rear; i++)
            printf("%d\n", queue[i]);
    }
}