//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_NAME_LENGTH 20
#define MAX_MSG_LENGTH 100

// Define struct for user
struct user {
    char name[MAX_NAME_LENGTH];
    int age;
    float weight;
    float height;
    char msg[MAX_MSG_LENGTH];
};

// Function to print user's details
void displayUser(struct user u) {
    printf("Name: %s\n", u.name);
    printf("Age: %d\n", u.age);
    printf("Weight: %.2f kg\n", u.weight);
    printf("Height: %.2f cm\n", u.height);
    printf("Message: %s\n", u.msg);
}

// Function to calculate BMI
float calculateBMI(float weight, float height) {
    return weight / ((height / 100) * (height / 100));
}

int main() {
    // Initialize variables
    char c;
    struct user u;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Welcome message
    printf("Welcome to the CyberFitness Tracker!\n\n");

    // Get user's name
    printf("Please enter your name: ");
    fgets(u.name, MAX_NAME_LENGTH, stdin);
    u.name[strcspn(u.name, "\n")] = 0;

    // Get user's age
    do {
        printf("Please enter your age: ");
        scanf("%d", &u.age);
    } while (u.age < 0);

    // Get user's weight
    do {
        printf("Please enter your weight (kg): ");
        scanf("%f", &u.weight);
    } while (u.weight < 0);

    // Get user's height
    do {
        printf("Please enter your height (cm): ");
        scanf("%f", &u.height);
    } while (u.height < 0);

    // Show user's details
    printf("\nYour details:\n");
    displayUser(u);

    // Calculate BMI and give message
    float bmi = calculateBMI(u.weight, u.height);
    if (bmi < 18.5) {
        strcpy(u.msg, "You are underweight");
    } else if (bmi >= 18.5 && bmi < 25) {
        strcpy(u.msg, "You are within the healthy weight range");
    } else if (bmi >= 25 && bmi < 30) {
        strcpy(u.msg, "You are overweight");
    } else {
        strcpy(u.msg, "You are obese");
    }

    // Show new message
    printf("\nBased on your BMI of %.2f, %s\n", bmi, u.msg);

    // Show current date and time
    printf("\nCurrent date and time: %d-%02d-%02d %02d:%02d:%02d\n", 
        tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 
        tm.tm_hour, tm.tm_min, tm.tm_sec);

    // Exit program
    printf("\nPress any key to exit...");
    scanf(" %c", &c);
    return 0;
}