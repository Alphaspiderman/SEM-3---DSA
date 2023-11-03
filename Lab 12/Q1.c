#include <stdio.h>
#include <stdlib.h>

// Find minimum and maximum in a Binary Search Tree

struct N
{
    int data;
    struct N *l;
    struct N *r;
} *root;

struct N *create_N()
{
    struct N *node = (struct N *)malloc(sizeof(struct N));
    printf("Enter data - ");
    scanf("%d", &node->data);
    node->l = NULL;
    node->r = NULL;
    return node;
}

void insert()
{
    // Binary Tree
    struct N *node = create_N();
    if (root == NULL)
    {
        root = node;
        return;
    }
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

void find_min()
{
    struct N *ptr = root;
    while (ptr->l != NULL)
    {
        ptr = ptr->l;
    }
    printf("Minimum value = %d\n", ptr->data);
}

void find_max()
{
    struct N *ptr = root;
    while (ptr->r != NULL)
    {
        ptr = ptr->r;
    }
    printf("Maximum value = %d\n", ptr->data);
}

void main()
{
    root = NULL;
    // Start
    int ch;
    printf("Menu \n1) Insert\n2) Find Minimum\n3) Find Maximum\n4) Exit");
    while (1)
    {
        printf("\nEnter choice - ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            inorder(root);
            break;
        case 2:
            find_min();
            break;
        case 3:
            find_max();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}