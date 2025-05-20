//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char *name;
    Date birthdate;
} Person;

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create an array of 10 people
    Person people[10];

    // Generate random names and birthdates for the people
    for (int i = 0; i < 10; i++) {
        // Generate a random name
        char *name = malloc(20);
        for (int j = 0; j < 19; j++) {
            name[j] = (rand() % 26) + 'a';
        }
        name[19] = '\0';

        // Generate a random birthdate
        Date birthdate;
        birthdate.year = rand() % 100 + 1900;
        birthdate.month = rand() % 12 + 1;
        birthdate.day = rand() % 28 + 1;

        // Store the name and birthdate in the person struct
        people[i].name = name;
        people[i].birthdate = birthdate;
    }

    // Print the names and birthdates of the people
    for (int i = 0; i < 10; i++) {
        printf("%s was born on %d-%d-%d.\n", people[i].name, people[i].birthdate.year, people[i].birthdate.month, people[i].birthdate.day);
    }

    // Randomly select two people to time travel
    int person1 = rand() % 10;
    int person2 = rand() % 10;

    // Generate a random destination year
    int destinationYear = rand() % 100 + 1900;

    // Send the two people to the destination year
    people[person1].birthdate.year = destinationYear;
    people[person2].birthdate.year = destinationYear;

    // Print the names and birthdates of the people after time travel
    for (int i = 0; i < 10; i++) {
        printf("%s was born on %d-%d-%d.\n", people[i].name, people[i].birthdate.year, people[i].birthdate.month, people[i].birthdate.day);
    }

    return 0;
}