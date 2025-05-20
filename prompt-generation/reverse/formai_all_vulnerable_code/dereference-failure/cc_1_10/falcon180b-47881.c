//Falcon-180B DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

struct Person {
    char name[50];
    int age;
    char city[50];
};

int main(int argc, char *argv[]) {
    FILE *file;
    struct Person person;
    char line[MAX_LINE_SIZE];
    char *token;

    // Open the file in read mode
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the first line (header)
    fgets(line, MAX_LINE_SIZE, file);

    // Parse each line of data
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        // Tokenize the line
        token = strtok(line, ",");
        strcpy(person.name, token);

        token = strtok(NULL, ",");
        person.age = atoi(token);

        token = strtok(NULL, ",");
        strcpy(person.city, token);

        // Print the person's information
        printf("Name: %s\n", person.name);
        printf("Age: %d\n", person.age);
        printf("City: %s\n", person.city);
        printf("\n");
    }

    // Close the file
    fclose(file);

    return 0;
}