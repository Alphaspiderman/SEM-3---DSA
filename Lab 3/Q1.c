#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
// Write a Program to implement a stack as well as its operations using arrays
void main()
{
    // Start
    int stack[MAXSIZE];
    int top = -1;
    int cond = 1;

    while (cond)
    {
        int choice;
        printf("\nOptions for Operations (ARRAYS) \n1) Push an Element \n2) Pop an Element \n3) Display the Stack \n4) Quit\nEnter you Choice - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // Push
            if (top + 1 != MAXSIZE)
            {
                int data;
                printf("\nEnter a value - ");
                scanf("%d", &data);
                top += 1;
                stack[top] = data;
                printf("\nSaved Value");
            }
            else
            {
                printf("\nStack if full (Overflow)");
            }
            break;
        case 2:
            // Pop
            if (top != -1)
            {
                int data = stack[top--];
                printf("\nValue - %d", data);
            }
            else
            {
                printf("\nStack is empty (Underflow)");
            }
            break;
        case 3:
            // Display
            printf("\nDisplaying Values - ");
            for (int i = top; i != -1; i--)
            {
                int data = stack[i];
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