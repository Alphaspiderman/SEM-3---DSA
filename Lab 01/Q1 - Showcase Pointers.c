#include <stdio.h>

// Showcase Pointers

void main()
{
    int num;
    int *ptr;

    num = 5;
    ptr = &num;
    printf("Value of num - %d", num);
    printf("\nAddress of num - %p", num);
    printf("\nAddress of ptr - %p", &ptr);
    printf("\nValue pointed by ptr - %d", *ptr);
}