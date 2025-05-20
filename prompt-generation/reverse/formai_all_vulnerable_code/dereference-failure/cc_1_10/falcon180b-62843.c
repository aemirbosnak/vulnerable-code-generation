//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct contact {
    char name[30];
    char number[20];
};

void add_contact(struct contact *book[], int *size) {
    char name[30], number[20];
    printf("Enter the name of the contact: ");
    scanf("%s", name);
    printf("Enter the phone number of the contact: ");
    scanf("%s", number);

    strcpy(book[*size]->name, name);
    strcpy(book[*size]->number, number);

    (*size)++;
}

void search_contact(struct contact *book, int size) {
    char search_name[30], search_number[20];
    printf("Enter the name of the contact to search: ");
    scanf("%s", search_name);

    int i;
    for(i = 0; i < size; i++) {
        if(strcmp(book[i].name, search_name) == 0) {
            printf("Name: %s\n", book[i].name);
            printf("Phone number: %s\n", book[i].number);
        }
    }
}

void delete_contact(struct contact *book, int *size) {
    char name[30];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);

    int i;
    for(i = 0; i < *size; i++) {
        if(strcmp(book[i].name, name) == 0) {
            memset(&book[i], 0, sizeof(struct contact));
            (*size)--;
            return;
        }
    }

    printf("Contact not found!\n");
}

int main() {
    struct contact *book[MAX] = {NULL};
    int size = 0;

    int choice, flag = 1;
    while(flag) {
        system("clear");
        printf("\n\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact(book, &size);
                break;
            case 2:
                search_contact(book, size);
                break;
            case 3:
                delete_contact(book, &size);
                break;
            case 4:
                flag = 0;
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}