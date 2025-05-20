//FormAI DATASET v1.0 Category: Phone Book ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

struct contact { 
    char name[30];
    char phone_number[15];
    struct contact *next; 
};

struct contact *head = NULL;

void add_contact() {
    struct contact *temp, *p;
    temp = (struct contact*)malloc(sizeof(struct contact));
    printf("Enter name: ");
    scanf("%s", &temp->name);
    printf("Enter phone number: ");
    scanf("%s", &temp->phone_number);
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void list_contacts() {
    struct contact *temp;
    temp = head;
    printf("Contacts List:\n");
    while (temp != NULL) {
        printf("%s - %s \n", temp -> name, temp -> phone_number);
        temp = temp -> next;
    }
}

void search_contact() {
    char name[30];
    struct contact *temp;
    temp = head;
    printf("Enter name to search: ");
    scanf("%s", &name);
    while (temp != NULL) {
        if (strcmp(name, temp -> name) == 0) {
            printf("%s - %s \n", temp -> name, temp -> phone_number);
            return;
        }
        temp = temp -> next;
    }
    printf("Contact not found!");
}

void delete_contact() {
    char name[30];
    struct contact *temp, *p;
    temp = head;
    printf("Enter name to delete: ");
    scanf("%s", &name);
    if (strcmp(name, head -> name) == 0) {
        head = temp -> next;
        free(temp);
        return;
    }
    while (temp != NULL) {
        if (strcmp(name, temp -> name) == 0) {
            p -> next = temp -> next;
            free(temp);
            return;
        } else {
            p = temp;
            temp = temp -> next;
        }
    }
    printf("Contact not found!");
}

int main() {
    int choice;
    printf("\tC Phone Book\n");
    printf("1 - add contact\n2 - list contacts\n3 - search contact\n4 - delete contact\n5 - exit\n");
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                list_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (1);

    return 0;
}