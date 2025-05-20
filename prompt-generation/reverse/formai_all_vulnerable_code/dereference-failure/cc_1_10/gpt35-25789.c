//FormAI DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char email[MAX_EMAIL_LENGTH];
} Person;

int main() {
    // Open a new file pointer
    FILE *fp = fopen("people.txt", "r");

    // Check if file pointer is null, exit program if null
    if (fp == NULL) {
        perror("Error opening file.");
        exit(-1);
    }

    // Initialize empty array of People
    Person people[10];
    int count = 0;

    // Read each line of the file and add to People array
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        // Split line into separate values
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        char *email = strtok(NULL, ",");

        // Add person to array
        Person newPerson;
        strcpy(newPerson.name, name);
        newPerson.age = age;
        strcpy(newPerson.email, email);
        people[count++] = newPerson;
    }

    // Close file pointer
    fclose(fp);

    // Query for people with certain age
    int queryAge;
    printf("Enter age to search for: ");
    scanf("%d", &queryAge);

    // Print out people with matching age
    printf("\nPeople with age %d:\n", queryAge);
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (people[i].age == queryAge) {
            printf("%s, %s\n", people[i].name, people[i].email);
            found = true;
        }
    }

    // If no people were found, print error message
    if (!found) {
        printf("No people with age %d found.\n", queryAge);
    }

    return 0;
}