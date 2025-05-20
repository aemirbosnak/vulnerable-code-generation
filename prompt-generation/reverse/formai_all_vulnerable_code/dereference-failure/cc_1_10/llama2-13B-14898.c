//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Structure to store information about a person
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} person;

// Function to read information about a person from the user
void read_person_info(person *person) {
    printf("Enter your name: ");
    fgets(person->name, MAX_NAME_LENGTH, stdin);
    person->age = atoi(stdin);
}

// Function to print a message based on the person's age
void print_message(person person) {
    if (person.age >= 18 && person.age <= 30) {
        printf("You are in your prime! Enjoy your youthful energy and vitality.\n");
    } else if (person.age > 30 && person.age <= 50) {
        printf("You are in your peak! Use your experience and wisdom to achieve great things.\n");
    } else {
        printf("You are a wise and seasoned individual. Share your knowledge and insights with others.\n");
    }
}

int main() {
    // Create a person structure
    person person;

    // Read information about the person from the user
    read_person_info(&person);

    // Print a message based on the person's age
    print_message(person);

    // Ask the user for their favorite hobby
    printf("What is your favorite hobby? ");
    char hobby[50];
    fgets(hobby, 50, stdin);

    // Print a message based on the person's hobby
    if (strcmp(hobby, "reading") == 0) {
        printf("Ah, a fellow bookworm! There's nothing quite like getting lost in a good book.\n");
    } else if (strcmp(hobby, "hiking") == 0) {
        printf("You must love exploring the great outdoors! There's nothing quite like the fresh air and exercise.\n");
    } else {
        printf("That's an interesting hobby! I'm sure you find joy in it, even if it's not my cup of tea.\n");
    }

    // Ask the user for their favorite color
    printf("What is your favorite color? ");
    char color[20];
    fgets(color, 20, stdin);

    // Print a message based on the person's favorite color
    if (strcmp(color, "blue") == 0) {
        printf("Ah, blue is such a soothing and calming color. It must bring you peace and tranquility.\n");
    } else if (strcmp(color, "green") == 0) {
        printf("You must love the natural world! Green is such a vibrant and life-giving color.\n");
    } else {
        printf("That's an interesting choice! I'm sure you find beauty in it, even if it's not my favorite.\n");
    }

    return 0;
}