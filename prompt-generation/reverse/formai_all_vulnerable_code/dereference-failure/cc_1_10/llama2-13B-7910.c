//LLAMA2-13B DATASET v1.0 Category: Database querying ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_LENGTH 1024
#define BUFFER_SIZE 1024

struct student {
    int roll_no;
    char name[50];
    char address[100];
    int age;
};

int main() {
    // Create a database with 5 students
    struct student students[5] = {
        {1, "John", "Avenue", 25},
        {2, "Jane", "Street", 30},
        {3, "Bob", "Lane", 35},
        {4, "Alice", "Place", 28},
        {5, "Mike", "Drive", 38}
    };

    // Query the database to find the student with the highest age
    struct student *max_age = NULL;
    int max_age_found = 0;

    for (int i = 0; i < 5; i++) {
        if (students[i].age > max_age_found) {
            max_age_found = students[i].age;
            max_age = &students[i];
        }
    }

    // Print the student with the highest age
    printf("The student with the highest age is: %s (%d years old)\n", max_age->name, max_age->age);

    // Query the database to find the student with the lowest age
    struct student *min_age = NULL;
    int min_age_found = 0;

    for (int i = 0; i < 5; i++) {
        if (students[i].age < min_age_found) {
            min_age_found = students[i].age;
            min_age = &students[i];
        }
    }

    // Print the student with the lowest age
    printf("The student with the lowest age is: %s (%d years old)\n", min_age->name, min_age->age);

    // Query the database to find the student with the longest name
    struct student *longest_name = NULL;
    int longest_name_found = 0;

    for (int i = 0; i < 5; i++) {
        if (strlen(students[i].name) > longest_name_found) {
            longest_name_found = strlen(students[i].name);
            longest_name = &students[i];
        }
    }

    // Print the student with the longest name
    printf("The student with the longest name is: %s\n", longest_name->name);

    // Query the database to find the student with the shortest name
    struct student *shortest_name = NULL;
    int shortest_name_found = 0;

    for (int i = 0; i < 5; i++) {
        if (strlen(students[i].name) < shortest_name_found) {
            shortest_name_found = strlen(students[i].name);
            shortest_name = &students[i];
        }
    }

    // Print the student with the shortest name
    printf("The student with the shortest name is: %s\n", shortest_name->name);

    return 0;
}