//Falcon-180B DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a person's name and age
typedef struct {
    char name[50];
    int age;
} Person;

// Define a function to compare two people based on their age
int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;

    if (personA->age > personB->age) {
        return 1;
    } else if (personA->age < personB->age) {
        return -1;
    } else {
        return 0;
    }
}

// Define a function to print a person's name and age
void printPerson(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

// Define a function to read in a list of people from a file
void readPeople(FILE *file, Person *people, int numPeople) {
    int i = 0;
    while (fscanf(file, "%s %d", people[i].name, &people[i].age)!= EOF) {
        i++;
        if (i == numPeople) {
            break;
        }
    }
}

// Define a function to write a list of people to a file
void writePeople(FILE *file, Person *people, int numPeople) {
    int i = 0;
    while (i < numPeople) {
        fprintf(file, "%s %d\n", people[i].name, people[i].age);
        i++;
    }
}

// Define a function to sort a list of people based on their age
void sortPeople(Person *people, int numPeople) {
    qsort(people, numPeople, sizeof(Person), compare);
}

int main() {
    int numPeople = 0;

    // Read in the number of people from the user
    printf("Enter the number of people: ");
    scanf("%d", &numPeople);

    // Allocate memory for the list of people
    Person *people = (Person *)malloc(numPeople * sizeof(Person));

    // Read in the list of people from a file
    FILE *file = fopen("people.txt", "r");
    readPeople(file, people, numPeople);
    fclose(file);

    // Sort the list of people based on their age
    sortPeople(people, numPeople);

    // Print the sorted list of people
    printf("Sorted list of people:\n");
    for (int i = 0; i < numPeople; i++) {
        printPerson(&people[i]);
    }

    // Write the sorted list of people to a file
    FILE *outputFile = fopen("sorted_people.txt", "w");
    writePeople(outputFile, people, numPeople);
    fclose(outputFile);

    free(people);

    return 0;
}