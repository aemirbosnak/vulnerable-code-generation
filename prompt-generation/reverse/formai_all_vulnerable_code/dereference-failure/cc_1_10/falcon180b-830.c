//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

void print_person(Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Email: %s\n", p->email);
}

int compare_names(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return strcmp(p1->name, p2->name);
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    // Read in data from file
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    char line[1000];
    while (fgets(line, sizeof(line), file)!= NULL) {
        Person *p = malloc(sizeof(Person));
        if (p == NULL) {
            printf("Error: could not allocate memory for person.\n");
            return 1;
        }
        char *name = strtok(line, ",");
        p->name = strdup(name);
        p->age = atoi(strtok(NULL, ","));
        p->email = strdup(strtok(NULL, ","));
        people[num_people++] = p;
    }
    fclose(file);

    // Sort people by name
    qsort(people, num_people, sizeof(Person *), compare_names);

    // Search for person by name
    char name_to_search[100];
    printf("Enter name to search for: ");
    scanf("%s", name_to_search);
    Person *result = NULL;
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i]->name, name_to_search) == 0) {
            result = people[i];
            break;
        }
    }
    if (result == NULL) {
        printf("Person not found.\n");
    } else {
        print_person(result);
    }

    // Free memory
    for (int i = 0; i < num_people; i++) {
        free(people[i]->name);
        free(people[i]->email);
        free(people[i]);
    }
    return 0;
}