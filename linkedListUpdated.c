
#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int choice, ele, rep;
struct node *temp, *p, *ptr;
void InsertFront(int);
void InsertEnd(int);
void DeleteFront();
void DeleteEnd();
void Display();
void del(int x);
void RemoveDup(struct node *head);

int main()
{

    do
    {
        printf("1.Insert@Front 2:Insert@End 3:DeleteFromFront 4:DeleteFromEnd 5.DisplayLinkedList 6:Exit 7:Deleteevery 8:Delduplicate\t");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int val;
            scanf("%d", &val);
            InsertFront(val);
            break;
        }
        case 2:
        {
            int val;
            scanf("%d", &val);
            InsertEnd(val);
            break;
        }
        case 3:
        {
            DeleteFront();
            break;
        }
        case 4:
        {
            DeleteEnd();
            break;
        }
        case 5:
        {
            Display();
            break;
        }
        case 8:
        {
            break;
        }
        case 6:
        {
            scanf("%d", &ele);
            del(ele);
            break;
        }
        case 7:
        {
            RemoveDup(head);
            break;
        }
        default:
            printf("Wrong Choice\n");
        }
    } while (choice != 5);
}
void InsertFront(int x)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = head;
    head = temp;
}
void InsertEnd(int x)
{
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
void DeleteFront()
{
    if (head != NULL)
        head = head->next;
}
void DeleteEnd()
{
    if (head != NULL)
    {
        p = head;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        p->next = NULL;
    }
}
void Display()
{
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void del(int x)
{
    p = head;
    while (p != NULL)
    {
        if (p->data == x)
        {
            ptr = p->next;
            p->data = p->next->data;
            p->next = p->next->next;
            //p->next=ptr->next;
            free(ptr);
            ptr = NULL;
        }
        else
        {
            p = p->next;
        }
    }
}
void RemoveDup(struct node *head)
{
    p = head;
    while (p->next != NULL)
    {
        rep = p->data;
        if (p->next->data == rep)
        {
            ptr = p->next;
            p->data = p->next->data;
            p->next = p->next->next;
            free(ptr);
        }
        else
        {
            p = p->next;
        }
    }
}