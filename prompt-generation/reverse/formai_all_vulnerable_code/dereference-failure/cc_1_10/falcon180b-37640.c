//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int main() {
    Person *people = NULL;
    int num_people = 0;
    char input[MAX_SIZE];
    char *search_name;
    int search_age;

    printf("Enter the number of people: ");
    scanf("%d", &num_people);

    people = (Person *)malloc(num_people * sizeof(Person));

    printf("Enter the name and age of each person:\n");
    for (int i = 0; i < num_people; i++) {
        scanf("%s %d", people[i].name, &people[i].age);
    }

    printf("Enter the name to search for: ");
    scanf("%s", input);
    search_name = strdup(input);

    printf("Enter the minimum age to search for: ");
    scanf("%d", &search_age);

    int found_count = 0;
    for (int i = 0; i < num_people; i++) {
        if (strcasecmp(people[i].name, search_name) == 0 && people[i].age >= search_age) {
            printf("%s, %d years old\n", people[i].name, people[i].age);
            found_count++;
        }
    }

    if (found_count == 0) {
        printf("No results found.\n");
    } else {
        printf("%d results found.\n", found_count);
    }

    free(people);
    free(search_name);

    return 0;
}