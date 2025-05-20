//Falcon-180B DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

int main() {
    Person *people = NULL;
    int num_people = 0;

    // Allocate memory for the array of people
    people = (Person*) malloc(sizeof(Person) * 10);
    if (people == NULL) {
        printf("Error: Failed to allocate memory for people.\n");
        exit(1);
    }

    // Read in the data for each person
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: Failed to open data file.\n");
        exit(1);
    }

    char line[MAX_NAME_LENGTH];
    while (fgets(line, MAX_NAME_LENGTH, file)!= NULL) {
        // Parse the line into name and age
        char *name_ptr = strtok(line, ",");
        char *age_ptr = strtok(NULL, ",");
        if (name_ptr == NULL || age_ptr == NULL) {
            printf("Error: Invalid data format in line: %s\n", line);
            exit(1);
        }

        // Copy the name and age into the person struct
        strncpy(people[num_people].name, name_ptr, MAX_NAME_LENGTH);
        people[num_people].age = atoi(age_ptr);

        // Increment the number of people
        num_people++;
    }

    fclose(file);

    // Sort the people by age
    for (int i = 0; i < num_people; i++) {
        for (int j = i + 1; j < num_people; j++) {
            if (people[j].age < people[i].age) {
                // Swap the people
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Print the sorted list of people
    for (int i = 0; i < num_people; i++) {
        printf("%s (%d)\n", people[i].name, people[i].age);
    }

    // Free the memory for the array of people
    free(people);

    return 0;
}