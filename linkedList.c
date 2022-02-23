#include <stdio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL;

int main()
{
	int choice;
	struct node *temp, *p;
	do
	{
		printf("1.Insert@Front 2:Insert@End 3:DeleteFromFront 4:DeleteFromEnd 5.DisplayLinkedList 6:Exit\t");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
		{
			int val;
			scanf("%d", &val);
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = val;
			temp->next = head;
			head = temp;
			break;
		}
		case 2:
		{
			int val;
			scanf("%d", &val);
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = val;
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
			break;
		}
		case 3:
		{
			if (head != NULL)
			{
				head = head->next;
				break;
			}
		case 4:
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
			break;
		}
		case 5:
		{
			p = head;
			while (p != NULL)
			{
				printf("%d ", p->data);
				p = p->next;
			}
			printf("\n");
			break;
		}
		case 6:
		{
			break;
		}
		default:
			printf("Wrong Choice\n");
		}
		}
	} while (choice != 6);
}