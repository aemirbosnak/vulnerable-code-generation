//FormAI DATASET v1.0 Category: Linked list operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

/* Define our node structure */
struct Node
{
    int data;
    struct Node* next;
};

typedef struct Node node_t;

/* Function to create a new node with given data */
node_t* create_node(int data)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Insert a node at the beginning of the list */
void insert_node_begin(node_t** head_ref, int data)
{
    node_t* new_node = create_node(data);

    new_node->next = *head_ref;
    *head_ref = new_node;

    printf("Wow! A new node with data %d has been inserted at the beginning of the list.\n", data);
}

/* Insert a node at the end of the list */
void insert_node_end(node_t** head_ref, int data)
{
    node_t* current_node = *head_ref;
    node_t* new_node = create_node(data);

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        printf("Wow! A new node with data %d has been inserted at the end of the list.\n", data);
        return;
    }

    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = new_node;

    printf("Wow! A new node with data %d has been inserted at the end of the list.\n", data);
}

/* Insert a node after a given node */
void insert_node_after(node_t* prev_node, int data)
{
    if (prev_node == NULL)
    {
        printf("Oops! The previous node cannot be NULL.");
        return;
    }

    node_t* new_node = create_node(data);

    new_node->next = prev_node->next;
    prev_node->next = new_node;

    printf("Wow! A new node with data %d has been inserted after a given node in the list.\n", data);
}

/* Delete a node with given key */
void delete_node(node_t** head_ref, int key)
{
    node_t* current_node = *head_ref;
    node_t* prev_node = NULL;

    if (current_node != NULL && current_node->data == key)
    {
        *head_ref = current_node->next;
        free(current_node);
        printf("Wow! A node with data %d has been deleted from the list.\n", key);
        return;
    }

    while (current_node != NULL && current_node->data != key)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL)
    {
        printf("Oops! The key %d was not found in the list.", key);
        return;
    }

    prev_node->next = current_node->next;
    free(current_node);

    printf("Wow! A node with data %d has been deleted from the list.\n", key);
}

/* Find the length of the linked list */
int length(node_t* head)
{
    int count = 0;
    node_t* current_node = head;

    while (current_node != NULL)
    {
        count++;
        current_node = current_node->next;
    }

    return count;
}

/* Print the linked list */
void print_list(node_t* head)
{
    printf("The linked list is: ");

    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

/* Driver function */
int main()
{
    node_t* head = NULL;

    insert_node_begin(&head, 1);
    insert_node_end(&head, 2);
    insert_node_after(head->next, 3);
    insert_node_end(&head, 4);
    insert_node_end(&head, 5);
    insert_node_after(head->next, 6);
    insert_node_begin(&head, 7);

    print_list(head);
    printf("The length of the linked list is %d.\n", length(head));

    delete_node(&head, 5);
    delete_node(&head, 7);
    delete_node(&head, 2);
    delete_node(&head, 10);

    print_list(head);
    printf("The length of the linked list is %d.\n", length(head));

    return 0;
}