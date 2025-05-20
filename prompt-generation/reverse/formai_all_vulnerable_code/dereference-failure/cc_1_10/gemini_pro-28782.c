//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Linus Torvalds-style linked list node
struct node {
	int data;
	struct node *next;
};

// Linus Torvalds-style linked list
struct list {
	struct node *head;
	struct node *tail;
};

// Linus Torvalds-style linked list operations

// Insert a new node at the beginning of the list
void list_insert_head(struct list *list, int data)
{
	struct node *new_node = malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = list->head;
	list->head = new_node;
	if (list->tail == NULL)
		list->tail = new_node;
}

// Insert a new node at the end of the list
void list_insert_tail(struct list *list, int data)
{
	struct node *new_node = malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	if (list->tail == NULL)
		list->head = new_node;
	else
		list->tail->next = new_node;
	list->tail = new_node;
}

// Delete the first node from the list
void list_delete_head(struct list *list)
{
	if (list->head == NULL)
		return;
	struct node *old_head = list->head;
	list->head = list->head->next;
	if (list->head == NULL)
		list->tail = NULL;
	free(old_head);
}

// Delete the last node from the list
void list_delete_tail(struct list *list)
{
	if (list->tail == NULL)
		return;
	struct node *new_tail = list->head;
	while (new_tail->next != list->tail)
		new_tail = new_tail->next;
	free(list->tail);
	list->tail = new_tail;
	if (list->tail == NULL)
		list->head = NULL;
}

// Print the list
void list_print(struct list *list)
{
	struct node *current = list->head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

// Free the list
void list_free(struct list *list)
{
	struct node *current = list->head;
	while (current != NULL) {
		struct node *next = current->next;
		free(current);
		current = next;
	}
	list->head = NULL;
	list->tail = NULL;
}

// Main function
int main(void)
{
	// Create a new list
	struct list list = { NULL, NULL };

	// Insert some nodes into the list
	list_insert_head(&list, 1);
	list_insert_head(&list, 2);
	list_insert_head(&list, 3);
	list_insert_tail(&list, 4);
	list_insert_tail(&list, 5);
	list_insert_tail(&list, 6);

	// Print the list
	list_print(&list);

	// Delete some nodes from the list
	list_delete_head(&list);
	list_delete_tail(&list);

	// Print the list
	list_print(&list);

	// Free the list
	list_free(&list);

	return 0;
}