//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>

typedef struct Person {
    char name[50];
    int age;
    struct Person *next;
} Person;

void print_person(Person *person) {
    printf("[%s (%d years old) -> ", person->name, person->age);
    fflush(stdout);

    // Paranoid check for memory leaks
    if (person->next != NULL) {
        Person *next_person = person->next;
        free(person);
        print_person(next_person);
    } else {
        printf("END]\n");
    }
}

int main() {
    srand(time(NULL));

    Person *head = NULL;
    Person *new_person;

    // Generate some random people
    for (int i = 0; i < 10; i++) {
        new_person = (Person *)malloc(sizeof(Person));

        // Paranoid check for memory allocation errors
        if (new_person == NULL) {
            fprintf(stderr, "Error: Unable to allocate memory for new person.\n");
            exit(1);
        }

        // Set name and age randomly
        int name_length = rand() % 15 + 5;
        for (int j = 0; j < name_length; j++) {
            new_person->name[j] = 'A' + rand() % 26;
            if (isalpha(new_person->name[j])) continue;
            new_person->name[j] = '_';
        }
        new_person->name[name_length] = '\0';
        new_person->age = rand() % 100 + 1;

        // Add new person to the list
        if (head == NULL) {
            head = new_person;
            head->next = NULL;
        } else {
            Person *current = head;
            while (current->next != NULL) current = current->next;
            current->next = new_person;
            new_person->next = NULL;
        }
    }

    // Print out the list in a paranoid manner
    print_person(head);

    // Paranoid check for memory leaks before exiting
    while (head != NULL) {
        Person *next_person = head->next;
        free(head);
        head = next_person;
    }

    return 0;
}