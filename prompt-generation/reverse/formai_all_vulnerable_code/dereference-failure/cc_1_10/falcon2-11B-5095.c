//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item
{
	char name[100];
	int quantity;
};

struct item *items[100];
int size;

void add_item(char name[], int quantity)
{
	struct item *temp;
	temp = (struct item*)malloc(sizeof(struct item));
	strcpy(temp->name, name);
	temp->quantity = quantity;
	items[size] = temp;
	size++;
}

void print_items()
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%s : %d\n", items[i]->name, items[i]->quantity);
	}
}

int main()
{
	int choice, index;

	do
	{
		printf("1. Add an item\n");
		printf("2. Print the items\n");
		printf("3. Quit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Enter the item name : ");
				gets(items[size]->name);
				printf("Enter the quantity : ");
				scanf("%d", &items[size]->quantity);
				break;

			case 2:
				print_items();
				break;

			case 3:
				printf("Goodbye!\n");
				return 0;

			default:
				printf("Invalid choice!\n");
				break;
		}
	}while(choice!=3);

	return 0;
}