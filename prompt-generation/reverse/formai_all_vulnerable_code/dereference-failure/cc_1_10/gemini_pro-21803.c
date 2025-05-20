//GEMINI-pro DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    double height;
    double weight;
} person_t;

int main() {
    // Open the file for reading.
    FILE *fp = fopen("people.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the header line.
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("Error reading header line");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Parse the header line to get the number of people.
    char *ptr;
    int num_people = 0;
    ptr = strtok(line, ",");
    while (ptr != NULL) {
        num_people++;
        ptr = strtok(NULL, ",");
    }

    // Allocate memory for the people array.
    person_t *people = malloc(sizeof(person_t) * num_people);
    if (people == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read the data lines and populate the people array.
    int i;
    for (i = 0; i < num_people; i++) {
        if (fgets(line, sizeof(line), fp) == NULL) {
            perror("Error reading data line");
            fclose(fp);
            free(people);
            return EXIT_FAILURE;
        }

        // Parse the data line to get the person's information.
        ptr = strtok(line, ",");
        people[i].name = strdup(ptr);
        ptr = strtok(NULL, ",");
        people[i].age = atoi(ptr);
        ptr = strtok(NULL, ",");
        people[i].height = atof(ptr);
        ptr = strtok(NULL, ",");
        people[i].weight = atof(ptr);
    }

    // Close the file.
    fclose(fp);

    // Print the people array.
    for (i = 0; i < num_people; i++) {
        printf("Person %d:\n", i + 1);
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Height: %f\n", people[i].height);
        printf("Weight: %f\n", people[i].weight);
        printf("\n");
    }

    // Free the memory allocated for the people array.
    for (i = 0; i < num_people; i++) {
        free(people[i].name);
    }
    free(people);

    return EXIT_SUCCESS;
}