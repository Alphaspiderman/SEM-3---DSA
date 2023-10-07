#include <stdio.h>
#include <stdlib.h>

// Showcase the usage of dynamic memory allocation

void main(){
    int *ptr_1, *ptr_2, i;
    ptr_1 = malloc(sizeof(int));
    printf("Enter a number - ");
    scanf("%d", ptr_1);

    printf("Address of ptr1 - %p", ptr_1);
    printf("\nValue of ptr1 - %d", *ptr_1);

    ptr_2 = calloc(3, sizeof(int));
    printf("\nValues that 2nd pointer can hold - 3");

    printf("\nEnter 3 numbers - \n");
    for(i = 0; i<3; i++){
        scanf("\n%d", ptr_2+i);
    }

    printf("Stored Values in 2nd Pointer -");
    for(i = 0; i<3; i++){
        printf("\n%d", *(ptr_2+i));
    }

    printf("\nExtedning 2nd Pointer");
    realloc(ptr_2, 5*sizeof(int));

    printf("\nValues that 2nd pointer can hold - 5");

    printf("\nEnter 2 more numbers - \n");
    for(i = 3; i<5; i++){
        scanf("%d", ptr_2+i);
    }

    printf("\nStored Values in 2nd Pointer - ");
    for(i = 0; i<5; i++){
        printf("\n%p - %d", (ptr_2+i), *(ptr_2+i));
    }

    free(ptr_2);
    free(ptr_1);
    printf("\nFree-ed Allocated Memory");
}
