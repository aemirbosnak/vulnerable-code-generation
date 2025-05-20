//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_beginning(struct node** head, int data) {
    struct node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void insert_end(struct node** head, int data) {
    if (*head == NULL) {
        insert_beginning(head, data);
        return;
    }

    struct node* new_node = create_node(data);
    new_node->next = NULL;

    struct node* current = *head;

    while (current->next!= NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void print_list(struct node* head) {
    struct node* current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete_beginning(struct node** head) {
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_end(struct node** head) {
    if (*head == NULL) {
        return;
    }

    struct node* current = *head;
    struct node* prev = NULL;

    while (current->next!= NULL) {
        prev = current;
        current = current->next;
    }

    if (prev!= NULL) {
        prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(current);
}

int search_list(struct node* head, int data) {
    struct node* current = head;

    while (current!= NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void destroy_list(struct node** head) {
    struct node* current = *head;

    while (current!= NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    *head = NULL;
}

int main() {
    struct node* head = NULL;

    insert_beginning(&head, 'a');
    insert_end(&head, 'b');
    insert_end(&head, 'c');

    print_list(head);

    delete_beginning(&head);

    printf("Search for 'a': %d\n", search_list(head, 'a'));

    delete_end(&head);

    print_list(head);

    destroy_list(&head);

    return 0;
}