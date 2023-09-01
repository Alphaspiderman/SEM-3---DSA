#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front = 0;
int rear = -1;
int queue[MAX];
int size = 0;

void dequeue()
{

    if (size == 0)
    {
        printf("Queue Underflow");
    }
    else
    {
        printf("Element  - %d", queue[front]);
        front = (front + 1) % MAX;
        size--;
    }
}
void display()
{
    if (size == 0)
    {
        printf("Empty Queue\n");
    }

    else
    {
        // printf("Display - %d %d\n", front, rear);
        printf("The queue is - \n");
        for (int i = 0; i < size; i++)
        {
            int n = (front + i) % MAX;
            printf("%d\n", queue[n]);
        }
    }
}

void enqueue()
{
    if (size == MAX)
    {
        printf("Queue Overflow");
        return;
    }
    int element;
    rear = (rear + 1) % MAX;
    printf("Enter element to be inserted - \n");
    scanf("%d", &element);
    queue[rear] = element;
    size++;
}

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