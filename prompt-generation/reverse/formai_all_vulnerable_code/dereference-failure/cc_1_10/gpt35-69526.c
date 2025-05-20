//FormAI DATASET v1.0 Category: Mailing list manager ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char name[50];
    char email[50];
    struct person* next;
} person;

person* create_person(char* name, char* email) {
    person* new_person = (person*) malloc(sizeof(person));
    strcpy(new_person->name, name);
    strcpy(new_person->email, email);
    new_person->next = NULL;
    return new_person;
}

void add_person(person** head, char* name, char* email) {
    person* new_person = create_person(name, email);
    new_person->next = *head;
    *head = new_person;
}

void print_list(person* head) {
    while(head) {
        printf("%s <%s>\n", head->name, head->email);
        head = head->next;
    }
}

void delete_list(person** head) {
    person* current = *head;
    while(current) {
        person* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    person* mailing_list = NULL;
    printf("Welcome to the Retro Mailing List Manager!\n\n");

    while(1) {
        printf("Please choose an option:\n");
        printf("1. Add a person to the mailing list\n");
        printf("2. Print the entire mailing list\n");
        printf("3. Quit\n");

        char input[10];
        fgets(input, 10, stdin);
        int choice = atoi(input);

        switch(choice) {
            case 1: {
                char name[50];
                char email[50];
                printf("\nEnter the person's name: ");
                fgets(name, 50, stdin);
                printf("Enter the person's email: ");
                fgets(email, 50, stdin);
                add_person(&mailing_list, name, email);
                printf("\n%s has been added to the mailing list.\n\n", name);
                break;
            }
            case 2: {
                printf("\nMailing List:\n");
                print_list(mailing_list);
                printf("\n");
                break;
            }
            case 3: {
                printf("\nGoodbye!\n");
                delete_list(&mailing_list);
                return 0;
            }
            default: {
                printf("Invalid option. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}