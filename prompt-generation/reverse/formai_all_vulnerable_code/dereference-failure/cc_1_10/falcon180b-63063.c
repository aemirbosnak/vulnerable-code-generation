//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct contact {
    char name[MAX_SIZE];
    char phone[MAX_SIZE];
    struct contact *next;
};

void add_contact(struct contact *head, char *name, char *phone) {
    struct contact *new_contact = (struct contact *)malloc(sizeof(struct contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->phone, phone);
    new_contact->next = NULL;

    if (head == NULL) {
        head = new_contact;
    } else {
        struct contact *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_contact;
    }
}

void print_contacts(struct contact *head) {
    struct contact *temp = head;
    while (temp!= NULL) {
        printf("Name: %s\nPhone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

void search_contact(struct contact *head, char *name) {
    struct contact *temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", temp->name, temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

void delete_contact(struct contact *head, char *name) {
    struct contact *temp = head;
    struct contact *prev = NULL;

    while (temp!= NULL && strcmp(temp->name, name)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Contact not found.\n");
    } else {
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
    }
}

int main() {
    struct contact *head = NULL;

    add_contact(head, "John", "1234567890");
    add_contact(head, "Jane", "0987654321");
    add_contact(head, "Bob", "5555555555");

    print_contacts(head);

    search_contact(head, "John");
    search_contact(head, "Dave");

    delete_contact(head, "John");

    print_contacts(head);

    return 0;
}