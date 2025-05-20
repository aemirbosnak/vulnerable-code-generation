//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int id;
} Person;

int compare(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return strcmp(p1->name, p2->name);
}

int main() {
    Person people[MAX_ELEMENTS];
    int num_people = 0;

    // Read in the list of people
    FILE *fp = fopen("people.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line[MAX_NAME_LEN + 10];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_people >= MAX_ELEMENTS) {
            printf("Error: List is full.\n");
            exit(1);
        }

        char *name_ptr = strtok(line, " ");
        strcpy(people[num_people].name, name_ptr);

        char *id_ptr = strtok(NULL, " ");
        people[num_people].id = atoi(id_ptr);

        num_people++;
    }
    fclose(fp);

    // Sort the list by name
    qsort(people, num_people, sizeof(Person), compare);

    // Search for a name
    char search_name[MAX_NAME_LEN];
    printf("Enter a name to search for: ");
    scanf("%s", search_name);

    Person *result = bsearch(search_name, people, num_people, sizeof(Person), compare);
    if (result == NULL) {
        printf("Name not found.\n");
    } else {
        printf("ID: %d\n", result->id);
    }

    return 0;
}