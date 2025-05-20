//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 50
#define MAX_ARRAY_SIZE 1000000

// Define a struct to represent a person
typedef struct Person {
    int id;
    char name[MAX_STRING_LENGTH];
    int age;
} Person;

// Define an array of Person structs
Person people[MAX_ARRAY_SIZE];

// Define a function to generate a random string of uppercase letters
char* random_string(int length) {
    char* string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'A' + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Define a function to initialize the array with random data
void initialize_array(int num_people) {
    for (int i = 0; i < num_people; i++) {
        people[i].id = i;
        strncpy(people[i].name, random_string(10), sizeof(people[i].name));
        people[i].age = rand() % 100;
    }
}

// Define a function to sort the array by age using bubble sort algorithm
void sort_by_age(int num_people) {
    for (int i = 0; i < num_people - 1; i++) {
        for (int j = 0; j < num_people - i - 1; j++) {
            if (people[j].age > people[j + 1].age) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Initialize the array with random data
    initialize_array(MAX_ARRAY_SIZE);

    // Sort the array by age
    sort_by_age(MAX_ARRAY_SIZE);

    // Print the 10 youngest people
    printf("The 10 youngest people are:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d %s %d\n", people[i].id, people[i].name, people[i].age);
    }

    return 0;
}