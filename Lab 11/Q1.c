#include <stdio.h>
#include <stdlib.h>

// Write a program to implement the following on a Binary Search tree
// Insert, Delete, Search for key

struct N
{
    struct N *l;
    struct N *r;
    int data;
} *root;

struct N *create_N()
{
    struct N *node = (struct N *)malloc(sizeof(struct N));
    int data;
    printf("Enter Data - ");
    scanf("%d", &data);
    node->data = data;
    node->l = NULL;
    node->r = NULL;
}

void delete()
{
    struct N *parent = NULL;
    struct N *cur = root;
    int val;
    printf("Enter Value to Delete - ");
    scanf("%d", &val);
    while (1)
    {
        if (cur == NULL)
        {
            printf("\nNot Found");
            return;
        }
        if (cur->data == val)
        {
            break;
        }
        else if (cur->data > val)
        {
            parent = cur;
            cur = cur->l;
        }
        else
        {
            parent = cur;
            cur = cur->r;
        }
    }
    if (parent == NULL)
    {
        // Root node pain
        if (cur->r != NULL)
        {
            struct N *ptr = cur->r;
            while (ptr->l != NULL)
            {
                ptr = ptr->l;
            }
            ptr->l = cur->l;
            root = cur->r;
        }
        else{
            root = cur->l;
        }
        return;
    }
    if (cur->l == NULL && cur->r == NULL)
    {
        printf("\nLeaf Node");
        if (parent->l == cur)
        {
            parent->l = NULL;
        }
        else
        {
            parent->r = NULL;
        }
    }
    else if (cur->l == NULL)
    {
        printf("\nNo Left Chile");
        if (parent->l == cur)
        {
            parent->l = cur->r;
        }
        else
        {
            parent->r = cur->r;
        }
    }
    else if (cur->r == NULL)
    {
        printf("\nNo Right Chile");
        if (parent->l == cur)
        {
            parent->l = cur->l;
        }
        else
        {
            parent->r = cur->l;
        }
    }
    else
    {
        printf("\nBoth Children present");
        struct N *ptr = cur->r;
        while (ptr->l != NULL)
        {
            ptr = ptr->l;
        }
        ptr->l = cur->l;
        if (parent->l == cur)
        {
            parent->l = cur->r;
        }
        else
        {
            parent->r = cur->r;
        }
    }
    printf("\nRemoved Value\n");
    free(cur);
}

void search()
{
    struct N *parent;
    struct N *cur = root;
    int val;
    printf("Enter Value to Check for - ");
    scanf("%d", &val);
    while (1)
    {
        if (cur == NULL)
        {
            printf("\nNot Found");
            return;
        }
        if (cur->data == val)
        {
            break;
        }
        else if (cur->data > val)
        {
            parent = cur;
            cur = cur->l;
        }
        else
        {
            parent = cur;
            cur = cur->r;
        }
    }
    printf("Found Value");
}

void inorder(struct N *node)
{
    if (node == NULL)
    {
        return;
    }
    inorder(node->l);
    printf("%d  ", node->data);
    inorder(node->r);
}

void insert()
{
    // Binary Tree
    struct N *node = create_N();
    if (root == NULL)
    {
        root = node;
    }
    else
    {
        struct N *ptr = root;
        while (1)
        {
            if (node->data <= ptr->data)
            {
                if (ptr->l == NULL)
                {
                    ptr->l = node;
                    break;
                }
                else
                {
                    ptr = ptr->l;
                }
            }
            else
            {
                if (ptr->r == NULL)
                {
                    ptr->r = node;
                    break;
                }
                else
                {
                    ptr = ptr->r;
                }
            }
        }
    }
}

void main()
{
    // Start
    root = NULL;
    //
    printf("Menu \n1) Insert \n2) Delete \n3) Search \n4) Quit");
    while (1)
    {
        int choice;
        printf("\nEnter Choice - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            inorder(root);
            break;
        case 2:
            delete ();
            inorder(root);
            break;
        case 3:
            search();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice");
            break;
        }
    }
}