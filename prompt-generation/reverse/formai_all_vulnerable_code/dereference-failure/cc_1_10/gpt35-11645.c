//FormAI DATASET v1.0 Category: Phone Book ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[25];
    char phone_number[15];
};

struct list_node {
    struct contact value;
    struct list_node *next;
};

typedef struct list_node ListNode;

void print_menu() {
    printf("\n");
    printf("1. Add contact\n");
    printf("2. Remove contact\n");
    printf("3. Search contact\n");
    printf("4. Print contacts\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
}

void clear_input() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void add_contact(ListNode **head, struct contact new_contact) {
    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->value = new_contact;
    new_node->next = *head;
    *head = new_node;
}

void remove_contact(ListNode **head, char* name_to_remove) {
    ListNode *curr = *head;
    ListNode *prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->value.name, name_to_remove) == 0) {
            if (prev == NULL) {
                *head = curr->next;
                free(curr);
            }
            else {
                prev->next = curr->next;
                free(curr);
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void search_contact(ListNode *head, char* name_to_search) {
    ListNode *curr = head;
    while (curr != NULL) {
        if (strcmp(curr->value.name, name_to_search) == 0) {
            printf("\n%s: %s\n", curr->value.name, curr->value.phone_number);
            return;
        }
        curr = curr->next;
    }
    printf("\nContact not found\n");
}

void print_contacts(ListNode *head) {
    ListNode *curr = head;
    if (curr == NULL) {
        printf("\nNo contacts in phone book\n");
        return;
    }
    while (curr != NULL) {
        printf("\n%s: %s\n", curr->value.name, curr->value.phone_number);
        curr = curr->next;
    }
}

int main() {
    ListNode *phone_book_head = NULL;
    int choice;
    struct contact new_contact;
    char name_to_remove[25];
    char name_to_search[25];

    do {
        print_menu();
        scanf("%d", &choice);
        clear_input();

        switch(choice) {
            case 1:
                printf("\nEnter name: ");
                fgets(new_contact.name, 25, stdin);
                printf("\nEnter phone number: ");
                fgets(new_contact.phone_number, 15, stdin);
                add_contact(&phone_book_head, new_contact);
                printf("\nContact added\n");
                break;
            case 2:
                printf("\nEnter name to remove: ");
                fgets(name_to_remove, 25, stdin);
                remove_contact(&phone_book_head, name_to_remove);
                printf("\nContact removed\n");
                break;
            case 3:
                printf("\nEnter name to search: ");
                fgets(name_to_search, 25, stdin);
                search_contact(phone_book_head, name_to_search);
                break;
            case 4:
                print_contacts(phone_book_head);
                break;
            case 5:
                printf("\nExiting program\n");
                break;
            default:
                printf("\nInvalid choice, please try again\n");
        }
    }
    while (choice != 5);

    return 0;
}