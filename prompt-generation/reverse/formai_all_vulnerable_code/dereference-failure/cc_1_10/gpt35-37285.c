//FormAI DATASET v1.0 Category: Phone Book ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact {
    char name[100];
    long int number;
    char email[100];
    struct contact *next;
};
struct contact *start = NULL;

void add_contact() {
    struct contact *temp, *ptr;
    temp = (struct contact*)malloc(sizeof(struct contact));
    printf("\nEnter name of the contact\n");
    scanf("%s", temp->name);
    printf("\nEnter the phone number of the contact\n");
    scanf("%ld", &temp->number);
    printf("\nEnter the email address of the contact\n");
    scanf("%s", temp->email);
    temp->next = NULL;
    if (start == NULL) {
        start = temp;
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    printf("\nContact added successfully!\n");
}

void search_contact() {
    struct contact *ptr;
    char name[100];
    printf("\nEnter the name to search\n");
    scanf("%s", name);
    ptr = start;
    while (ptr != NULL) {
        if (strcmp(ptr->name, name) == 0) {
            printf("\nDetails of %s are:\n", name);
            printf("Phone number: %ld\n", ptr->number);
            printf("Email address: %s\n", ptr->email);
            return;
        }
        ptr = ptr->next;
    }
    printf("\n%s is not in your contact book\n", name);
}

void delete_contact() {
    struct contact *temp, *ptr;
    char name[100];
    printf("\nEnter the name to delete\n");
    scanf("%s", name);
    if (start == NULL) {
        printf("\n%s is not in your contact book\n", name);
        return;
    }
    if (strcmp(start->name, name) == 0) {
        temp = start;
        start = start->next;
        free(temp);
        printf("\n%s has been deleted from your contact book\n", name);
        return;
    }
    ptr = start;
    while (ptr->next != NULL && strcmp(ptr->next->name, name) != 0) {
        ptr = ptr->next;
    }
    if (ptr->next == NULL) {
        printf("\n%s is not in your contact book\n", name);
        return;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    printf("\n%s has been deleted from your contact book\n", name);
}

void display_all_contacts() {
    struct contact *ptr;
    if (start == NULL) {
        printf("\nYour contact book is empty\n");
        return;
    }
    ptr = start;
    printf("\nYour contact book:\n");
    while (ptr != NULL) {
        printf("%s\t%ld\t%s\n", ptr->name, ptr->number, ptr->email);
        ptr = ptr->next;
    }
}

int main() {
    int choice;
    printf("\nWelcome to the C Phone Book!\n");
    do {
        printf("\n\n-------------Menu-------------\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                display_all_contacts();
                break;
            case 5:
                printf("\nThank you for using the C Phone Book!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again\n");
                break;
        }
    } while (1);
    return 0;
}