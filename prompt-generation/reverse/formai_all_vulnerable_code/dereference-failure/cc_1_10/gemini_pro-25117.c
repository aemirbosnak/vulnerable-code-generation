//GEMINI-pro DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int age;
} person;

int main() {
    // Open a file for reading
    FILE *fp = fopen("people.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the first line of the file
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    read = getline(&line, &len, fp);
    if (read == -1) {
        perror("Error reading file");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Parse the first line of the file
    char *name = strtok(line, ",");
    int age = atoi(strtok(NULL, ","));

    // Create a new person struct
    person *p = malloc(sizeof(person));
    if (p == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        free(line);
        return EXIT_FAILURE;
    }

    // Copy the name and age into the person struct
    p->name = strdup(name);
    p->age = age;

    // Print the person's name and age
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);

    // Free the memory allocated for the person struct
    free(p->name);
    free(p);

    // Free the memory allocated for the line buffer
    free(line);

    // Close the file
    fclose(fp);

    return EXIT_SUCCESS;
}