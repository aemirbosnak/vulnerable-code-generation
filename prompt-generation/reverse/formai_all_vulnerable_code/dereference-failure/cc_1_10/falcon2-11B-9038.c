//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int age;
    char *occupation;
} Person;

int main() {
    Person *people = NULL;
    int num_people = 0;

    // Prompt user to enter number of people to add
    printf("Enter number of people to add: ");
    if (scanf("%d", &num_people)!= 1) {
        printf("Invalid input!\n");
        return 1;
    }

    // Allocate memory for people array
    people = (Person *)malloc(num_people * sizeof(Person));
    if (people == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Prompt user to enter name, age, and occupation for each person
    for (int i = 0; i < num_people; i++) {
        printf("Enter name for person %d: ", i + 1);
        if (fgets(people[i].name, sizeof(people[i].name), stdin) == NULL) {
            printf("Input too long!\n");
            return 1;
        }
        people[i].name[strcspn(people[i].name, "\n")] = 0; // Remove trailing newline character

        printf("Enter age for person %d: ", i + 1);
        if (scanf("%d", &people[i].age)!= 1) {
            printf("Invalid age input!\n");
            return 1;
        }

        printf("Enter occupation for person %d: ", i + 1);
        if (fgets(people[i].occupation, sizeof(people[i].occupation), stdin) == NULL) {
            printf("Input too long!\n");
            return 1;
        }
        people[i].occupation[strcspn(people[i].occupation, "\n")] = 0; // Remove trailing newline character
    }

    // Print the list of people
    printf("List of people:\n");
    for (int i = 0; i < num_people; i++) {
        printf("Name: %s, Age: %d, Occupation: %s\n", people[i].name, people[i].age, people[i].occupation);
    }

    // Free memory
    free(people);

    return 0;
}