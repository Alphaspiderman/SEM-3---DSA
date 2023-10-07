#include <stdio.h>
#include <stdlib.h>

struct N
{
    int data;
    struct N *next;
} *head;

struct N *create_N()
{
    int elem;
    struct N *node;
    printf("Enter element  - ");
    scanf("%d", &elem);
    // printf("Data  - %d", elem);

    node = (struct N *)malloc(sizeof(struct N));
    node->data = elem;
    node->next = NULL;
    
    return node;
}

void display()
{
    struct N *temp;
    if (head == NULL)
    {
        printf("Empty List");
        return;
    }
    temp = head;
    printf("Displaying List Values - ");
    do
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    } while (temp != NULL);
}

void push(){
    struct N *temp, *node;
    node = create_N();
    if (head != NULL)
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    else
    {
        head = node;
    }

}

void pop(){
    struct N *temp;
    if (head == NULL)
    {
        printf("Empty List");
        return;
    }
    temp = head;
    head = head->next;
    printf("Element removed -  %d", temp->data);
    free(temp);
}

void main()
{
    head = NULL;
    while (1)
    {
        printf("\nQueue Operations");
        printf("\n1) Push");
        printf("\n2) Pop");
        printf("\n3) Display");
        printf("\n4) Quit");
        printf("\nEnter your Choice - ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice");
            break;
        }
    }
}