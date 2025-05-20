//FormAI DATASET v1.0 Category: Phone Book ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[100];
    char number[20];
};

void add_contact(struct Contact *phone_book, int *size);
void print_phone_book(struct Contact *phone_book, int size);
void search_contact(struct Contact *phone_book, int size);
void remove_contact(struct Contact *phone_book, int *size);

int main() {
    int size = 0;
    struct Contact *phone_book = malloc(sizeof(struct Contact));

    printf("Welcome to the C Phone Book! \n");

    while (1) {
        printf("\n Menu \n");
        printf("1. Add Contact \n");
        printf("2. Print Phone Book \n");
        printf("3. Search Contact \n");
        printf("4. Remove Contact \n");
        printf("5. Exit \n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(phone_book, &size);
                break;

            case 2:
                print_phone_book(phone_book, size);
                break;

            case 3:
                search_contact(phone_book, size);
                break;

            case 4:
                remove_contact(phone_book, &size);
                break;

            case 5:
                printf("Thanks for using C Phone Book! \n");
                exit(0);

            default:
                printf("Please enter a valid choice. \n");
        }
    }
}

void add_contact(struct Contact *phone_book, int *size) {
    printf("\n Add Contact \n");

    printf("Enter Name: ");
    scanf("%s", phone_book[*size].name);

    printf("Enter Number: ");
    scanf("%s", phone_book[*size].number);

    *size += 1;
}

void print_phone_book(struct Contact *phone_book, int size) {
    printf("\n Phone Book \n");

    for (int i = 0; i < size; i++) {
        printf("Name: %s, Number: %s \n", phone_book[i].name, phone_book[i].number);
    }
}

void search_contact(struct Contact *phone_book, int size) {
    printf("\n Search Contact \n");

    char search_name[100];
    printf("Enter name to search: ");
    scanf("%s", &search_name);

    for (int i = 0; i < size; i++) {
        if (strcmp(search_name, phone_book[i].name) == 0) {
            printf("Name: %s, Number: %s \n", phone_book[i].name, phone_book[i].number);
            return;
        }
    }

    printf("Contact not found. \n");
}

void remove_contact(struct Contact *phone_book, int *size) {
    printf("\n Remove Contact \n");

    char remove_name[100];
    printf("Enter name to remove: ");
    scanf("%s", &remove_name);

    for (int i = 0; i < *size; i++) {
        if (strcmp(remove_name, phone_book[i].name) == 0) {
            for (int j = i; j < *size - 1; j++) {
                phone_book[j] = phone_book[j+1];
            }
            *size -= 1;
            return;
        }
    }

    printf("Contact not found. \n");
}