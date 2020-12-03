#include <stdio.h>
#include <stdlib.h>

struct node
{
    char name[25];
    int df;
    struct node *fp;
    struct node *dp;
};

struct node *A[20];
int c = 0;

void create(struct node *p, int n)
{
    struct node *temp, *t;
    temp = p;
    for (int i = 0; i < n; i++)
    {
        t = malloc(sizeof(struct node));
        printf("Enter Name:");
        scanf("%s", t->name);
        printf("Enter whether dir(1)/file(0):");
        scanf("%d", &t->df);
        if (t->df)
        {
            A[c] = t;
            c++;
        }
        t->fp = NULL;
        t->dp = NULL;
        if (i == 0)
        {
            temp->dp = t;
            temp = t;
        }
        else
        {
            temp->fp = t;
            temp = t;
        }
    }
}

void display(struct node *p)
{
    int i;
    p = p->dp;
    do
    {
        printf("\n%s (%d)", p->name, p->df);
        if (p->df == 1 && p->dp != NULL)
            display(p);
        p = p->fp;
    } while (p != NULL);
}

void main()
{
    int i, j, k, num;
    struct node *root;
    root = malloc(sizeof(struct node));
    root->df = 1;
    root->fp = NULL;
    root->dp = NULL;
    printf("Enter no. of users:");
    scanf("%d", &num);
    create(root, num);
    for (i = 0; i < c; i++)
    {
        printf("\nEnter no. of child nodes of %s:", A[i]->name);
        scanf("%d", &num);
        create(A[i], num);
    }
    printf("\nHierarchical Directory Structure\n");
    display(root);
}