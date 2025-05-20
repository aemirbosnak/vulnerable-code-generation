//GEMINI-pro DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *occupation;
} person_t;

int main(void) {
    // Open a file for writing
    FILE *fp = fopen("people.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Create a few people
    person_t people[] = {
        {"John Doe", 30, "Software Engineer"},
        {"Jane Doe", 25, "Teacher"},
        {"Bob Smith", 40, "Doctor"},
    };

    // Write the people to the file
    for (int i = 0; i < 3; i++) {
        fprintf(fp, "%s,%d,%s\n", people[i].name, people[i].age, people[i].occupation);
    }

    // Close the file
    fclose(fp);

    // Open the file for reading
    fp = fopen("people.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the people from the file
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Parse the line
        char *name = strtok(line, ",");
        char *age_str = strtok(NULL, ",");
        char *occupation = strtok(NULL, ",");

        // Convert the age to an integer
        int age = atoi(age_str);

        // Print the person's information
        printf("Name: %s\n", name);
        printf("Age: %d\n", age);
        printf("Occupation: %s\n\n", occupation);
    }

    // Close the file
    fclose(fp);

    return EXIT_SUCCESS;
}