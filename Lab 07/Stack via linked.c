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
    struct N *node = (struct N *)malloc(sizeof(struct N));

    printf("Enter element - ");
    scanf("%d", &elem);
    node->data = elem;
    node->next = NULL;

    return node;
}

void push()
{
    if (head == NULL)
    {
        head = create_N();
    }
    else
    {
        struct N *node;
        node = create_N();
        node->next = head;
        head = node;  
    }
}

void pop()
{
    if (head == NULL)
    {
        printf("Empty Stack");
    }
    else
    {
        struct N *temp = head;
        if (head->next == NULL)
        {
            printf("Removed Element - %d", head->data);
            head = NULL;
            free(temp);
        }
        else
        {
            head = temp->next;
            printf("Removed Element - %d", temp->data);
            free(temp);
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("Empty Stack");
    }
    else
    {
        printf("Values in Stack - ");
        struct N *temp = head;
        do
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        } while (temp != NULL);
    }
}

void peek(){
    if (head == NULL){
        printf("Empty Stack");
    } 
    else{
        printf("Topmost element - %d", head->data);
    }
}

void main()
{
    head = NULL;
    printf("Stack Operations \n1)Push\n2)Pop\n3)Display\n4)Quit\n5)Peek");
    while (1)
    {
        printf("\nEnter Choice - ");
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
        case 5:
            peek();
            break;
        default:
            printf("Invalid Choice");
            break;
        }
    }
}