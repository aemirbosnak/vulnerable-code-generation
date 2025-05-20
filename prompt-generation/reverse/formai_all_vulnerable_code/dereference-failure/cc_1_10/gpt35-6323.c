//FormAI DATASET v1.0 Category: Mailing list manager ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct email_node {
    char email[50];
    struct email_node* next;
};

struct mailing_list {
    char name[50];
    struct email_node* head;
};

struct mailing_list* create_list(char name[]) {
    struct mailing_list* list = (struct mailing_list*) malloc(sizeof(struct mailing_list));
    strcpy(list->name, name);
    list->head = NULL;
    return list;
}

void add_email(struct mailing_list* list, char email[]) {
    struct email_node* node = (struct email_node*) malloc(sizeof(struct email_node));
    strcpy(node->email, email);
    node->next = list->head;
    list->head = node;
}

void remove_email(struct mailing_list* list, char email[]) {
    struct email_node* current = list->head;
    struct email_node* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->email, email) == 0) {
            if (previous == NULL)
                list->head = current->next;
            else
                previous->next = current->next;

            free(current);
            printf("Email removed successfully.\n");
            return;
        }
        
        previous = current;
        current = current->next;
    }

    printf("Email not found in the list.\n");
}

void print_list(struct mailing_list* list) {
    printf("Mailing List: %s\n", list->name);

    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct email_node* current = list->head;
    int count = 0;

    while (current != NULL) {
        printf("%d. %s\n", ++count, current->email);
        current = current->next;
    }
}

int main() {
    struct mailing_list* list = create_list("My List");

    while (1) {
        printf("\n1. Add Email\n2. Remove Email\n3. Print List\n4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char email[50];
                printf("Enter email: ");
                scanf("%s", email);
                add_email(list, email);
                printf("Email added successfully.\n");
                break;
            }
            case 2: {
                char email[50];
                printf("Enter email: ");
                scanf("%s", email);
                remove_email(list, email);
                break;
            }
            case 3: {
                print_list(list);
                break;
            }
            case 4: {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}