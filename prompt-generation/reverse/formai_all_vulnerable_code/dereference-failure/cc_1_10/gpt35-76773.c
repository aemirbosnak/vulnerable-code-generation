//FormAI DATASET v1.0 Category: Mailing list manager ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    char name[50];
    char email[100];
    struct person* next;
};

struct list {
    char name[50];
    struct person* head;
};

void add_person(struct list* mailing_list) {
    struct person* new_person = (struct person*)malloc(sizeof(struct person));
    printf("Enter the name of the new person: ");
    fgets(new_person->name, 50, stdin);
    printf("Enter the email of the new person: ");
    fgets(new_person->email, 100, stdin);
    new_person->next = NULL;
    if(mailing_list->head == NULL) {
        mailing_list->head = new_person;
    }
    else {
        struct person* current = mailing_list->head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_person;
    }
    printf("New person added!\n");
}

void delete_person(struct list* mailing_list, char* name) {
    struct person* current = mailing_list->head;
    struct person* previous = NULL;
    while(current != NULL) {
        if(strcmp(current->name, name) == 0) {
            if(previous == NULL) {
                mailing_list->head = current->next;
            }
            else {
                previous->next = current->next;
            }
            printf("%s deleted from the list.\n", name);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("%s not found in the list.\n", name);
}

int main() {
    struct list* mailing_list = (struct list*)malloc(sizeof(struct list));
    strncpy(mailing_list->name, "My Mailing List", 50);
    mailing_list->head = NULL;
    int choice;
    char name[50];
    while(1) {
        printf("1. Add person\n2. Delete person\n3. Exit\n");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                add_person(mailing_list);
                break;
            case 2:
                printf("Enter the name of the person to delete: ");
                fgets(name, 50, stdin);
                delete_person(mailing_list, name);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}