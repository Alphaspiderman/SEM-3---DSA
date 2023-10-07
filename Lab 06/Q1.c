#include <stdio.h>
#include <stdlib.h>

struct N
{
    int data;
    struct N *next;
} *head;

int count = 0;

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

void insert_front()
{
    struct N *temp;
    temp = create_N();
    if (head != NULL)
    {
        temp->next = head;
    }
    count++;
    head = temp;
    display(head);
}

void insert_end()
{
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

    count++;
    display(head);
}

void remove_front()
{
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
    count--;
}

void remove_end()
{
    struct N *temp, *var;
    if (head == NULL)
    {
        printf("Empty List");
        return;
    }
    else
    {
        temp = head;
        if (head->next == NULL)
        {
            
            head = NULL;
        }
        else
        {
            while (temp->next != NULL)
            {
                var = temp;
                temp = temp->next;
            }
            var->next = NULL;
        }
        printf("Element removed -  %d", temp->data);
        free(temp);
    }
    count--;
}

void main()
{
    head = NULL;
    while (1)
    {
        printf("\nList Operations");
        printf("\n1) Insert at Front");
        printf("\n2) Insert at End");
        printf("\n3) Remove from Front");
        printf("\n4) Remove from End");
        printf("\n5) Display");
        printf("\n6) Quit");
        printf("\nEnter your Choice - ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_front(head);
            break;
        case 2:
            insert_end(head);
            break;
        case 3:
            remove_front(head);
            break;
        case 4:
            remove_end(head);
            break;
        case 5:
            display(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice");
            break;
        }
    }
}