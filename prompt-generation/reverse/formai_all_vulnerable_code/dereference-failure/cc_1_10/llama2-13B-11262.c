//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100
#define MAX_CITY_LENGTH 30

// Structure to store user information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char city[MAX_CITY_LENGTH];
} user_info;

// Function to print a welcome message
void welcome(void) {
    printf("Welcome to the user information management system!\n");
}

// Function to print a farewell message
void farewell(void) {
    printf("Goodbye! Please come again.\n");
}

// Function to handle user input and store it in a structure
user_info get_user_info(void) {
    user_info user;
    printf("Enter your name: ");
    fgets(user.name, MAX_NAME_LENGTH, stdin);
    user.age = atoi(stdin);
    printf("Enter your city: ");
    fgets(user.city, MAX_CITY_LENGTH, stdin);
    return user;
}

// Function to print the user information
void print_user_info(user_info user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("City: %s\n", user.city);
}

// Function to calculate and print the user's age in years
void print_age(user_info user) {
    int age_years = user.age;
    printf("Age in years: %d\n", age_years);
}

// Function to calculate and print the user's age in months
void print_age_months(user_info user) {
    int age_months = user.age * 12;
    printf("Age in months: %d\n", age_months);
}

// Function to calculate and print the user's age in days
void print_age_days(user_info user) {
    int age_days = user.age * 365;
    printf("Age in days: %d\n", age_days);
}

int main(void) {
    srand(time(NULL)); // seed the random number generator

    // Call the welcome function to print a welcome message
    welcome();

    // Get the user's information
    user_info user = get_user_info();

    // Print the user's information
    print_user_info(user);

    // Calculate and print the user's age in years
    print_age(user);

    // Calculate and print the user's age in months
    print_age_months(user);

    // Calculate and print the user's age in days
    print_age_days(user);

    // Call the farewell function to print a farewell message
    farewell();

    return 0;
}