//FormAI DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 20

typedef struct contact {
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LEN];
    struct contact* next;
} Contact;

int menu(void) {
    int choice;
    printf("\nChoose an option: \n");
    printf("1. Add a new contact\n");
    printf("2. Remove a contact\n");
    printf("3. Search for a contact\n");
    printf("4. Display all contacts\n");
    printf("5. Quit\n");
    scanf("%d", &choice);
    return choice;
}

void get_name(char* name) {
    printf("Enter name: ");
    scanf(" %[^\n]s", name);
}

void get_num(char* num) {
    printf("Enter phone number: ");
    scanf(" %[^\n]s", num);
}

void add(Contact** head, char* name, char* num) {
    Contact* new_contact = (Contact*) malloc(sizeof(Contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->num, num);
    new_contact->next = NULL;

    if (*head == NULL) {
        *head = new_contact;
        return;
    }

    Contact* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_contact;
}

void remove_contact(Contact** head, char* name) {
    Contact* curr = *head;

    if (strcmp(curr->name, name) == 0) {
        *head = curr->next;
        free(curr);
        return;
    }

    Contact* prev = curr;
    curr = curr->next;

    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            prev->next = curr->next;
            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    printf("Contact not found.\n");
}

void search(Contact* head, char* name) {
    Contact* curr = head;
    int found = 0;

    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            printf("%s: %s\n", curr->name, curr->num);
            found = 1;
        }
        curr = curr->next;
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void display_all(Contact* head) {
    if (head == NULL) {
        printf("No contacts to display.\n");
        return;
    }

    Contact* curr = head;

    while (curr != NULL) {
        printf("%s: %s\n", curr->name, curr->num);
        curr = curr->next;
    }
}

void free_list(Contact* head) {
    Contact* curr = head;
    Contact* temp;

    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
}

int main() {
    Contact* head = NULL;

    int choice;
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LEN];

    do {
        choice = menu();
        switch (choice) {
            case 1:
                get_name(name);
                get_num(num);
                add(&head, name, num);
                printf("Contact added.\n");
                break;
            case 2:
                get_name(name);
                remove_contact(&head, name);
                break;
            case 3:
                get_name(name);
                search(head, name);
                break;
            case 4:
                display_all(head);
                break;
            case 5:
                free_list(head);
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}