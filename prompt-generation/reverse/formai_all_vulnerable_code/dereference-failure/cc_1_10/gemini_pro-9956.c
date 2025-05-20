//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    int age;
    char *city;
} person;

int main() {
    int n = 10;
    person *people = malloc(sizeof(person) * n);

    for (int i = 0; i < n; i++) {
        people[i].id = i + 1;
        people[i].name = malloc(100);
        sprintf(people[i].name, "Person-%d", i + 1);
        people[i].age = rand() % 100;
        people[i].city = malloc(100);
        sprintf(people[i].city, "City-%d", i + 1);
    }

    // Print the people
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %s\n", people[i].id, people[i].name, people[i].age, people[i].city);
    }

    // Find the oldest person
    int max_age = 0;
    int max_age_index = -1;
    for (int i = 0; i < n; i++) {
        if (people[i].age > max_age) {
            max_age = people[i].age;
            max_age_index = i;
        }
    }

    // Print the oldest person
    printf("The oldest person is: %s (%d years old)\n", people[max_age_index].name, people[max_age_index].age);

    // Find the most common city
    char *most_common_city = NULL;
    int max_city_count = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(people[i].city, people[j].city) == 0) {
                count++;
            }
        }
        if (count > max_city_count) {
            max_city_count = count;
            most_common_city = people[i].city;
        }
    }

    // Print the most common city
    printf("The most common city is: %s (%d people)\n", most_common_city, max_city_count);

    // Free the memory
    for (int i = 0; i < n; i++) {
        free(people[i].name);
        free(people[i].city);
    }
    free(people);

    return 0;
}