//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int age, gender, weight, height, activity_level, fitness_goal, progress;
    double bmi, bmr, target_calories, burned_calories, steps, distance, heart_rate;
    char name[50];

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your personal details:\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", &age);
    printf("Gender (1 for Male, 2 for Female): ");
    scanf("%d", &gender);
    printf("Weight (in kg): ");
    scanf("%d", &weight);
    printf("Height (in cm): ");
    scanf("%d", &height);
    printf("Activity Level (1 for Sedentary, 2 for Lightly Active, 3 for Moderately Active, 4 for Very Active, 5 for Extra Active): ");
    scanf("%d", &activity_level);
    printf("Fitness Goal (1 for Weight Loss, 2 for Weight Gain, 3 for Weight Maintenance): ");
    scanf("%d", &fitness_goal);
    printf("Progress (in %): ");
    scanf("%d", &progress);

    bmi = (weight / (height * height)) * 703;
    bmr = (10 * weight) + (6.25 * height) - (5 * age) + (gender * 5);
    target_calories = bmr * (activity_level + 1);

    if (fitness_goal == 1) {
        target_calories -= 500;
    } else if (fitness_goal == 2) {
        target_calories += 500;
    }

    if (progress == 0) {
        burned_calories = 0;
    } else {
        burned_calories = (progress / 100) * target_calories;
    }

    printf("BMI: %.2f\n", bmi);
    printf("BMR: %.2f\n", bmr);
    printf("Target Calories: %.2f\n", target_calories);
    printf("Burned Calories: %.2f\n", burned_calories);

    return 0;
}