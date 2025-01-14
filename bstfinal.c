#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *newnode;
struct node *root = NULL;
void insert();
void delete();
void search();
void display();
void preorder();
void postorder();
void inorder();
int main()
{
    int choice;

    while (1)
    {
        printf("enter 1.insert \n 2.delete \n 3.display\n 4.search \n 5.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid");
        }
    }
    return 0;
}
struct node *insertion(struct node *root, struct node *newnode)
{
    if (root == NULL)
    {
        root = newnode;
    }
    else if (root->data < newnode->data)
    {
        root->right = insertion(root->right, newnode);
    }
    else
    {
        root->left = insertion(root->left, newnode);
    }
    return root;
}
void insert()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d", &newnode->data);
    newnode->left = NULL;
    newnode->right = NULL;
    root = insertion(root, newnode);
}
struct node *findmin(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
struct node *deletion(struct node *root, int value)
{
    if (root == NULL)
    {
        printf("tree empty");
        return root;
    }
    else if (value < root->data)
    {
        root = deletion(root->left, value);
    }
    else if (value > root->data)
    {
        root = deletion(root->right, value);
    }
    else
    {
        struct node *temp;
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            root->data = findmin(root->right)->data;
            root->right = deletion(root->right, root->data);
        }
    }
    return root;
}
void delete()
{
    int val;
    printf("enter val:");
    scanf("%d", &val);
    root = deletion(root, val);
}
void display()
{
    printf("Inorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\n");
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return ;
    }
    else
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {

        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void search()
{
    int value;
    printf("enter value: ");
    scanf("%d", &value);
    struct node *current = root;
    while (current != NULL)
    {
        if (current->data == value)
        {
            printf("eleennt found");
            break;
        }
        else if (current->data < value)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
       printf("element not found");
    } 
}