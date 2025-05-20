//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: systematic
// Fitness Tracker Example Program

#include <stdio.h>

int main() {
    // Define variables for the user's input
    int weight, height, age, activity_level;
    float bmi;

    // Ask the user for their input
    printf("Enter your weight (in pounds): ");
    scanf("%d", &weight);
    printf("Enter your height (in inches): ");
    scanf("%d", &height);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your activity level (1-5, 1 being sedentary, 5 being very active): ");
    scanf("%d", &activity_level);

    // Calculate the user's BMI
    bmi = (float) weight / (height * height);

    // Print the user's BMI
    printf("Your BMI is: %f\n", bmi);

    // Print a message based on the user's BMI
    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("You are normal weight.\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("You are overweight.\n");
    } else if (bmi >= 30 && bmi < 35) {
        printf("You are obese.\n");
    } else if (bmi >= 35) {
        printf("You are severely obese.\n");
    }

    // Print a message based on the user's activity level
    if (activity_level == 1) {
        printf("You should aim to burn at least 500 calories per day.\n");
    } else if (activity_level == 2) {
        printf("You should aim to burn at least 600 calories per day.\n");
    } else if (activity_level == 3) {
        printf("You should aim to burn at least 700 calories per day.\n");
    } else if (activity_level == 4) {
        printf("You should aim to burn at least 800 calories per day.\n");
    } else if (activity_level == 5) {
        printf("You should aim to burn at least 1000 calories per day.\n");
    }

    return 0;
}