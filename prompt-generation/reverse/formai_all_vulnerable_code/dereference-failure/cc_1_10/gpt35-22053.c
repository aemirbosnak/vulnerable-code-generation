//FormAI DATASET v1.0 Category: Database querying ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for storing data from the database
typedef struct {
    int id;
    char name[20];
    int age;
    char gender[10];
} Person;

int main() {
    // Open the database file
    FILE *file = fopen("people.db", "r");

    // Check if file exists and can be opened
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read from the database and store data into array of Person structs
    Person people[100];
    int num_people = 0;
    char line[50];

    while (fgets(line, sizeof(line), file)) {
        char *token;
        token = strtok(line, ",");
        people[num_people].id = atoi(token);
        token = strtok(NULL, ",");
        strcpy(people[num_people].name, token);
        token = strtok(NULL, ",");
        people[num_people].age = atoi(token);
        token = strtok(NULL, ",");
        strcpy(people[num_people].gender, token);
        num_people++;
    }

    // Close the database file
    fclose(file);

    // Query the database for persons aged 30 and above
    printf("The following persons are aged 30 and above:\n");
    for (int i = 0; i < num_people; i++) {
        if (people[i].age >= 30) {
            printf("Id: %d\nName: %s\nAge: %d\nGender: %s\n", people[i].id, people[i].name, 
                   people[i].age, people[i].gender);
        }
    }

    // Query the database for male persons
    printf("The following persons are male:\n");
    for (int i = 0; i < num_people; i++) {
        if (strcmp(people[i].gender, "male") == 0) {
            printf("Id: %d\nName: %s\nAge: %d\nGender: %s\n", people[i].id, people[i].name, 
                   people[i].age, people[i].gender);
        }
    }

    return 0;
}