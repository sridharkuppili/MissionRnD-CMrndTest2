#include <stdio.h>
#include<conio.h>
#include <malloc.h>
//#pragma warning(disable:4996)
struct oddevennode {
	int data;
	struct oddevennode *next;
	struct oddevennode *random;
};
int * oddeven_sll(struct oddevennode *head)
{
	int *a;
	a = (int*)malloc(2 * sizeof(int));
	a[0] = 0;
	a[1] = 0;
	struct oddevennode  *temp, *todd, *teven;
	temp = head;
	while (temp != NULL)
	{
		if ((temp->data) % 2 != 0)
		{
			a[0]++;
			todd = temp;
			if (todd->next != NULL)
			{
				while (((todd->next)->data) % 2 == 0 && (todd->next)->next != NULL)
				{
					todd = todd->next;
				}
				temp->random = todd->next;
			}
		}
		else
		{
			a[1]++;
			teven = temp;
			if (teven->next != NULL)
			{
				while (((teven->next)->data) % 2 != 0 && (teven->next)->next != NULL)
				{
					teven = teven->next;
				}
				temp->random = teven->next;
			}
		}
		temp = temp->next;
	}
	return a;
}
void main()
{
	int i, n, len, K, *a;
	a = (int*)malloc(2 * sizeof(int));
	struct oddevennode *head, *temp, *newnode;
	temp = (struct oddevennode*)malloc(sizeof(struct oddevennode));
	head = (struct oddevennode*)malloc(sizeof(struct oddevennode));
	printf("enter lenth");
	scanf("%d", &len);
	printf("enter node");
	scanf("%d", &(head->data));
	head->next = NULL;
	temp = head;
	for (i = 1; i < len; i++)
	{
		printf("enter data");
		newnode = (struct oddevennode*)malloc(sizeof(struct oddevennode));
		scanf("%d", &(newnode->data));
		newnode->next = NULL;
		temp->next = newnode;
		temp = temp->next;;
	}
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	a = oddeven_sll(head);
	printf("%d\t%d", a[0], a[1]);
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	getche();
}
