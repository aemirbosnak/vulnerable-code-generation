//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} person_t;

int compare_name(const void *a, const void *b) {
    person_t *p1 = (person_t *)a;
    person_t *p2 = (person_t *)b;

    return strcmp(p1->name, p2->name);
}

int compare_age(const void *a, const void *b) {
    person_t *p1 = (person_t *)a;
    person_t *p2 = (person_t *)b;

    return p1->age - p2->age;
}

void print_person(person_t *p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

int main() {
    person_t *people = NULL;
    int num_people = 0;
    int choice;

    do {
        printf("Enter choice:\n");
        printf("1. Add person\n");
        printf("2. Search by name\n");
        printf("3. Search by age\n");
        printf("4. Print all\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (num_people == MAX_SIZE) {
                    printf("Maximum number of people reached.\n");
                } else {
                    person_t *new_person = malloc(sizeof(person_t));
                    printf("Enter name: ");
                    scanf("%s", new_person->name);
                    printf("Enter age: ");
                    scanf("%d", &new_person->age);
                    people = realloc(people, sizeof(person_t) * (num_people + 1));
                    people[num_people] = *new_person;
                    num_people++;
                }
                break;
            }
            case 2: {
                printf("Enter name to search: ");
                char *search_name = malloc(strlen(gets()) + 1);
                strcpy(search_name, gets());
                people = bsearch(search_name, people, num_people, sizeof(person_t), compare_name);
                if (people == NULL) {
                    printf("Person not found.\n");
                } else {
                    print_person(people);
                }
                free(search_name);
                break;
            }
            case 3: {
                printf("Enter age to search: ");
                int search_age;
                scanf("%d", &search_age);
                people = bsearch(&search_age, people, num_people, sizeof(person_t), compare_age);
                if (people == NULL) {
                    printf("Person not found.\n");
                } else {
                    print_person(people);
                }
                break;
            }
            case 4: {
                for (int i = 0; i < num_people; i++) {
                    print_person(&people[i]);
                }
                break;
            }
            case 5: {
                free(people);
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while (1);

    return 0;
}