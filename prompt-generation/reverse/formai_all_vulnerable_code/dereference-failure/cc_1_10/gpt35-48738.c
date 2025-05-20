//FormAI DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

struct Person {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

void addPerson(struct Person* list, int* count) {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    printf("Enter name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    printf("Enter email: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);

    // Remove new line at the end of the input
    name[strcspn(name, "\n")] = '\0';
    email[strcspn(email, "\n")] = '\0';

    // Add the person to the list
    strcpy(list[*count].name, name);
    strcpy(list[*count].email, email);
    (*count)++;

    printf("Added person to the list!\n");
}

void printList(struct Person* list, int count) {
    printf("Mailing list:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", list[i].name, list[i].email);
    }
}

int main() {
    int count = 0;
    struct Person* list = malloc(sizeof(struct Person) * 100);

    printf("Welcome to the Mailing List Manager!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a person to the list\n");
        printf("2. Print the mailing list\n");
        printf("3. Exit\n");
        printf("Your choice: ");

        char choice[10];
        fgets(choice, 10, stdin);

        if (strcmp(choice, "1\n") == 0) {
            addPerson(list, &count);
        } else if (strcmp(choice, "2\n") == 0) {
            printList(list, count);
        } else if (strcmp(choice, "3\n") == 0) {
            printf("Goodbye!\n");
            free(list);
            exit(0);
        } else {
            printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}