//GEMINI-pro DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} person_t;

int main() {
    // Open a file for reading
    FILE *file = fopen("people.txt", "r");
    if (file == NULL) {
        printf("Couldn't open the file. Are you sure it exists? Maybe you should go check.\n");
        return EXIT_FAILURE;
    }

    // Read the first line of the file
    char line[MAX_NAME_LENGTH + 20]; // +20 for the age
    fgets(line, sizeof(line), file);

    // Check if the file is empty
    if (strcmp(line, "\n") == 0) {
        printf("The file is empty. Go add some people!\n");
        fclose(file);
        return EXIT_SUCCESS;
    }

    // Read the rest of the lines of the file
    int num_people = 0;
    person_t people[100]; // Assuming there are no more than 100 people in the file
    while (fgets(line, sizeof(line), file)) {
        // Parse the line
        char *name = strtok(line, " ");
        int age = atoi(strtok(NULL, " "));

        // Create a new person struct
        person_t person;
        strcpy(person.name, name);
        person.age = age;

        // Add the person to the array
        people[num_people++] = person;
    }

    // Close the file
    fclose(file);

    // Print the names and ages of the people
    printf("Here is the list of people in the file:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }

    return EXIT_SUCCESS;
}