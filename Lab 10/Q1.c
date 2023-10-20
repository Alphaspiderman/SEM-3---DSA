#include <stdio.h>
#include <stdlib.h>

// Write a program to implement the tree traversal techniques (Preorder, Inorder, Postorder)

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

void preorder(struct N *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%d  ", node->data);
    preorder(node->l);
    preorder(node->r);
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

void postorder(struct N *node)
{
    if (node == NULL)
    {
        return;
    }
    postorder(node->l);
    postorder(node->r);
    printf("%d  ", node->data);
}

void build_tree()
{
    // NOT a Binary Tree
    struct N *node = create_N();
    if (root == NULL)
    {
        root = node;
    }
    else
    {
        struct N *temp = root;
        char direction[10];
        printf("Enter Direction - ");
        scanf("%s", direction);
        int i = 0;
        while (direction[i] != '\0')
        {
            if (direction[i] == 'L')
            {
                if (temp->l == NULL && direction[i + 1] == '\0')
                {
                    temp->l = node;
                    return;
                }
                if (temp->l == NULL)
                {
                    printf("Unable to traverse!!\nStopping");
                    return;
                }
                else
                {
                    temp = temp->l;
                    i++;
                }
            }
            else if (direction[i] == 'R')
            {
                if (temp->r == NULL && direction[i + 1] == '\0')
                {
                    temp->r = node;
                    return;
                }
                if (temp->r == NULL)
                {
                    printf("Unable to traverse!!\nStopping");
                    return;
                }
                else
                {
                    temp = temp->r;
                    i++;
                }
            }
            else
            {
                printf("Invalid Directions!!\nStopping");
                return;
            }
        }
    }
}

void main()
{
    // Start
    root = NULL;
    //
    printf("Menu \n1) Make a Tree \n2) Print Preorder \n3) Print Inorder \n4) Print Postorder \n5) Quit");
    while (1)
    {
        int choice;
        printf("\nEnter Choice - ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            build_tree(root);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice");
            break;
        }
    }
}