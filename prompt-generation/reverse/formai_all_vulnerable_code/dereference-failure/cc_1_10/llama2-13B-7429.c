//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Structure to hold person data
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} person_t;

// Function to read name and age from user
void read_person_info(person_t* person) {
    printf("Enter your name: ");
    fgets(person->name, MAX_NAME_LENGTH, stdin);
    printf("Enter your age: ");
    scanf("%d", &person->age);
}

// Function to print person information
void print_person_info(const person_t* person) {
    printf("Hello, my name is %s and I am %d years old.\n", person->name, person->age);
}

// Function to calculate and print the person's birthday
void print_birthday(const person_t* person) {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    char birthday_string[20];

    // Calculate the person's birthday based on their age and current time
    int birthday_age = person->age + current_time->tm_mday;
    char* birthday_month = "January";
    char* birthday_day = "1st";

    if (birthday_age > current_time->tm_mday) {
        birthday_month = "February";
        birthday_day = "14th";
    } else if (birthday_age > current_time->tm_mday + 28) {
        birthday_month = "March";
        birthday_day = "15th";
    } else {
        birthday_month = "January";
        birthday_day = "1st";
    }

    sprintf(birthday_string, "%s %s", birthday_month, birthday_day);
    printf("Happy birthday! Your birthday is %s.\n", birthday_string);
}

int main() {
    person_t person;

    // Read person information
    read_person_info(&person);

    // Print person information
    print_person_info(&person);

    // Print the person's birthday
    print_birthday(&person);

    return 0;
}