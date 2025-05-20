//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

struct person {
    char name[MAX_NAME_LEN];
    int age;
};

int main() {
    struct person p;
    char input[100];

    // Set up the person structure with some default values
    strcpy(p.name, "Alice");
    p.age = 25;

    // Get the user's input
    printf("Enter your name: ");
    fgets(input, 100, stdin);

    // Check if the input is valid
    if (input[0] == '\0' || strlen(input) > MAX_NAME_LEN) {
        printf("Error: Input must not be empty or longer than %d characters\n", MAX_NAME_LEN);
        return 1;
    }

    // Set the person's name to the user's input
    strcpy(p.name, input);

    // Get the user's age
    printf("Enter your age: ");
    int age = atoi(stdin);

    // Check if the age is valid
    if (age < 0 || age > MAX_AGE) {
        printf("Error: Age must be non-negative and less than or equal to %d\n", MAX_AGE);
        return 1;
    }

    // Set the person's age
    p.age = age;

    // Print the person's information
    printf("Your name is %s, and you are %d years old.\n", p.name, p.age);

    return 0;
}