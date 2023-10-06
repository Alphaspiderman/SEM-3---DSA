#include <stdio.h>
#include <stdlib.h>

// Write a Program that uses a function to perform the following operations on a circular linked list
// Creation, Insertion, Deletion and Traversal

struct N
{
    struct N *next;
    int data;
} *head;

struct N *create_N()
{
    struct N *node = (struct N *)malloc(sizeof(struct N));
    int elem;
    printf("Enter Value - ");
    scanf("%d", &elem);
    node->data = elem;
    node->next = NULL;
    return node;
}

void ins_start()
{
    if (head == NULL)
    {
        head = create_N();
        head->next = head;
    }
    else
    {
        struct N *node = create_N();
        struct N *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->next = head;
        head = node;
    }
}

void del_start()
{
    if (head == NULL)
    {
        printf("Empty List");
    }
    else
    {
        struct N *temp = head;
        struct N *prev = head;
        while (prev->next != head)
        {
            prev = prev->next;
        }
        prev->next = head->next;
        head = head->next;
        printf("Removing Value - %d", temp->data);
        free(temp);
    }
}

void ins_pos(int pos)
{
    if (head == NULL)
    {
        printf("Empty List, Creating as head");
        head = create_N();
    }
    else
    {
        int count = 1;
        struct N *cur = NULL;
        struct N *temp = head;
        while (temp->next != NULL && count != pos)
        {
            cur = temp;
            temp = temp->next;
            count++;
        }

        if (count != pos && count != pos - 1)
        {
            // Unable to get to position
            printf("Unable to get to position");
        }
        else if (temp->next == NULL && count == pos - 1)
        {
            // Reached Position but NULL
            printf("Position is empty\n");
            struct N *node = create_N();
            temp->next = node;
        }
        else
        {
            // Reached Position with VAL
            struct N *node = create_N();
            if (cur == NULL)
            {
                head = node;
            }
            else
            {
                cur->next = node;
            }
            node->next = temp;
        }
    }
}

void del_pos(int pos)
{
    if (head == NULL)
    {
        printf("Empty List");
        return;
    }
    int count = 1;
    struct N *cur = NULL;
    struct N *temp = head;
    while (temp != NULL && count != pos)
    {
        cur = temp;
        temp = temp->next;
        count++;
    }

    if (count != pos)
    {
        // Unable to get to position
        printf("Unable to get to position");
    }
    else if (temp == NULL)
    {
        // Reached Position but NULL
        printf("Position is empty");
    }
    else
    {
        // Reached Position with VAL
        if (cur == NULL)
        {
            head = temp->next;
        }
        else
        {
            cur->next = temp->next;
        }
        printf("Removing Value - %d", temp->data);
        free(temp);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("Empty List");
    }
    else
    {
        struct N *temp = head;
        while (temp->next != head)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
        printf("\n%d", temp->data);
    }
}

void main()
{
    head = NULL;
    int pos;
    printf("List Operations \n1) Insert Front \n2) Insert Given");
    printf("\n3) Remove Front  \n4) Remove Given  \n5) Display \n6) Quit");
    while (1)
    {
        int choice;
        printf("\nEnter Choice - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ins_start();
            break;
        case 2:
            printf("Enter Position - ");
            scanf("%d", &pos);
            ins_pos(pos);
            break;
        case 3:
            del_start();
            break;
        case 4:
            printf("Enter Position - ");
            scanf("%d", &pos);
            del_pos(pos);
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice!");
            break;
        }
    }
}