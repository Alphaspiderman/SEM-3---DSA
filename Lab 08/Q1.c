#include <stdio.h>
#include <stdlib.h>

// Write a Program that uses functions to perform the following functions on a double linked list.
// Creation, Traversal as well as Insertion, Deletion at Start, End and given position

struct N
{
    struct N *prev, *next;
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
    node->prev = NULL;
    return node;
}

void del_start()
{
    if (head == NULL)
    {
        printf("Empty List");
        return;
    }
    else
    {
        struct N *temp = head;
        head = head->next;
        printf("Removing Value - %d", temp->data);
        head->prev = NULL;
        free(temp);
    }
}

void ins_start()
{
    if (head == NULL)
    {
        head = create_N();
    }
    else
    {
        struct N *node = create_N();
        head->prev = node;
        node->next = head;
        head = node;
    }
}

void del_given(int pos)
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
            temp->prev = cur;
        }
        printf("Removing Value - %d", temp->data);
        free(temp);
    }
}

void ins_given(int pos)
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
            printf("Unable to get to position"); // , inserting at end
            // struct N *node = create_N();
            // cur->next = node;
        }
        else if (temp->next == NULL && count == pos - 1)
        {
            // Reached Position but NULL
            printf("Position is empty\n");
            struct N *node = create_N();
            temp->next = node;
            node->prev = temp;
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
                node->prev = cur;
            }
            node->next = temp;
            temp->prev = node;
        }
    }
}

void del_end()
{
    if (head == NULL)
    {
        printf("Empty List");
        return;
    }
    // else if (head->next == NULL)
    // {
    //     printf("Removed Element - %d", head->data);
    //     free(head);
    //     head = NULL;
    // }
    else
    {
        struct N *temp = head;
        struct N *cur;
        while (temp->next != NULL)
        {
            cur = temp;
            temp = temp->next;
        }
        cur->next = NULL;
        printf("Removing Value - %d", temp->data);
        free(temp);
    }
}

void ins_end()
{
    if (head == NULL)
    {
        printf("Empty List, Creating as head");
        head = create_N();
    }
    // else if (head->next == NULL)
    // {
    //     head->next = create_N();
    // }
    else
    {
        struct N *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = create_N();
    }
}

void display()
{
    if (head == NULL)
    {
        printf("Empty List");
        return;
    }
    else
    {
        struct N *temp = head;
        printf("Values in List - ");
        do
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        } while (temp != NULL);
    }
}

void main()
{
    // Start
    head = NULL;
    int pos;
    printf("List Operations \n1) Insert Front \n2) Insert Given \n3) Insert End");
    printf("\n4) Remove Front  \n5) Remove Given  \n6) Remove End \n7) Display \n8) Quit");
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
            ins_given(pos);
            break;
        case 3:
            ins_end();
            break;
        case 4:
            del_start();
            break;
        case 5:
            printf("Enter Position - ");
            scanf("%d", &pos);
            del_given(pos);
            break;
        case 6:
            del_end();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid Choice!");
            break;
        }
    }
}