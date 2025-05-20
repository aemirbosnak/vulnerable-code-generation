//FormAI DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    char email[50];
} Person;

void add_person(Person* db[], int* count) {
    Person* person = (Person*)malloc(sizeof(Person));
    printf("Enter name: ");
    scanf("%s", person->name);
    printf("Enter email: ");
    scanf("%s", person->email);
    person->id = *count;
    db[*count] = person;
    *count += 1;
    printf("\nAdded %s to the database with ID %d!\n\n", person->name, person->id);
}

void delete_person(Person* db[], int* count) {
    int id;
    printf("Enter ID of person to delete: ");
    scanf("%d", &id);
    if (id < 0 || id >= *count) {
        printf("\nInvalid ID!\n");
        return;
    }
    free(db[id]);
    for (int i = id; i < *count - 1; i++) {
        db[i] = db[i + 1];
        db[i]->id--;
    }
    *count -= 1;
    printf("\nDeleted person with ID %d!\n\n", id);
}

void print_person(Person* person) {
    printf("ID: %d\nName: %s\nEmail: %s\n\n", person->id, person->name, person->email);
}

void print_database(Person* db[], int* count) {
    if (*count == 0) {
        printf("\nThe database is empty.\n\n");
        return;
    }
    printf("\n---Database---\n");
    for (int i = 0; i < *count; i++) {
        print_person(db[i]);
    }
    printf("---------------\n\n");
}

int main() {
    int count = 0;
    Person* db[100];
    printf("Welcome to the crazy database simulation program!\n\n");
    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add a person to the database\n");
        printf("2. Delete a person from the database\n");
        printf("3. Print the database\n");
        printf("4. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_person(db, &count);
                break;
            case 2:
                delete_person(db, &count);
                break;
            case 3:
                print_database(db, &count);
                break;
            case 4:
                printf("Thanks for using the crazy database simulation program!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please choose 1-4.\n\n");
        }
    }
}