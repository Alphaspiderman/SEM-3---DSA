#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

// Write a Program to implement a stack as well as its operations using Structures

void main()
{
    // Start
    struct stacks
    {
        int stack[MAXSIZE];
        int top;
    } stack;
    int cond = 1;

    stack.top = -1;

    while (cond)
    {
        int choice;
        printf("\n\nOptions for Operations (STRUCTURES) \n1) Push an Element \n2) Pop an Element \n3) Display the Stack \n4) Quit\nEnter you Choice - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // Push
            if (stack.top + 1 != MAXSIZE)
            {
                int data;
                printf("\nEnter a value - ");
                scanf("%d", &data);
                stack.top += 1;
                stack.stack[stack.top] = data;
                printf("\nSaved Value\n");
            }
            else
            {
                printf("\nStack if full (Overflow)\n");
            }
            break;
        case 2:
            // Pop
            if (stack.top != -1)
            {
                int data = stack.stack[stack.top--];
                printf("\nValue - %d", data);
            }
            else
            {
                printf("\nStack is empty (Underflow)\n");
            }
            break;
        case 3:
            // Display
            printf("\nDisplaying Values - ");
            for (int i = stack.top; i != -1; i--)
            {
                int data = stack.stack[i];
                printf("\n%d", data);
            }
            break;
        case 4:
            // Quit
            cond = 0;
            exit(0);
        default:
            printf("\nInvalid Choice");
            break;
        }
    }
}