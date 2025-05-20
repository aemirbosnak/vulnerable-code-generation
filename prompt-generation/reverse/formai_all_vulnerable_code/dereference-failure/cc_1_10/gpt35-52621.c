//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Declare function for getting user's gender
char* getGender() {
    char* gender = malloc(sizeof(char));
    printf("\nEnter your gender (M/F): ");
    scanf(" %c", gender);
    return gender;
}

// Declare function for getting user's age
int getAge() {
    int age;
    printf("\nEnter your age: ");
    scanf("%d", &age);
    return age;
}

// Declare function for getting user's weight
float getWeight() {
    float weight;
    printf("\nEnter your weight in kg: ");
    scanf("%f", &weight);
    return weight;
}

// Declare function for getting user's height
float getHeight() {
    float height;
    printf("\nEnter your height in cm: ");
    scanf("%f", &height);
    return height;
}

int main() {
    char* gender = getGender(); // Get user's gender
    int age = getAge(); // Get user's age
    float weight = getWeight(); // Get user's weight
    float height = getHeight(); // Get user's height

    // Calculate user's BMR based on gender, age, weight, and height
    float bmr;
    if (*gender == 'M') {
        bmr = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    } else if (*gender == 'F') {
        bmr = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    }

    // Display user's BMR
    printf("\nYour Basal Metabolic Rate (BMR) is: %.2f calories/day", bmr);

    // Calculate user's TDEE based on their BMR and activity level
    float tdee;
    int activityLevel;
    printf("\n\nEnter your activity level (1-5):\n");
    printf("1. Sedentary (little or no exercise)\n2. Lightly Active (1-3 days/week of exercise)\n3. Moderately Active (3-5 days/week of exercise)\n4. Very Active (6-7 days/week of exercise)\n5. Super Active (twice/day of intense exercise)\n");
    scanf("%d", &activityLevel);
    switch (activityLevel) {
        case 1:
            tdee = bmr * 1.2;
            break;
        case 2:
            tdee = bmr * 1.375;
            break;
        case 3:
            tdee = bmr * 1.55;
            break;
        case 4:
            tdee = bmr * 1.725;
            break;
        case 5:
            tdee = bmr * 1.9;
            break;
        default:
            printf("Invalid input");
            exit(0);
    }

    // Display user's TDEE
    printf("\nYour Total Daily Energy Expenditure (TDEE) is: %.2f calories/day", tdee);

    // Declare variables for tracking user's fitness progress
    float calorieGoal = tdee - 500; // User's daily caloric intake goal for weight loss
    float caloriesConsumed; // User's daily caloric intake
    float caloriesBurned; // User's daily caloric expenditure
    float netCalories; // User's daily net caloric intake (caloriesConsumed - caloriesBurned)

    // Get user's daily caloric intake
    printf("\n\nHow many calories have you consumed today? ");
    scanf("%f", &caloriesConsumed);

    // Get user's daily caloric expenditure based on their activity today
    int activityToday;
    printf("\nHow active were you today (1-5)?\n");
    printf("1. Sedentary\n2. Lightly Active\n3. Moderately Active\n4. Very Active\n5. Super Active\n");
    scanf("%d", &activityToday);
    switch (activityToday) {
        case 1:
            caloriesBurned = bmr * 1.2;
            break;
        case 2:
            caloriesBurned = bmr * 1.375;
            break;
        case 3:
            caloriesBurned = bmr * 1.55;
            break;
        case 4:
            caloriesBurned = bmr * 1.725;
            break;
        case 5:
            caloriesBurned = bmr * 1.9;
            break;
        default:
            printf("Invalid input");
            exit(0);
    }

    // Calculate user's net caloric intake
    netCalories = caloriesConsumed - caloriesBurned;

    // Display user's net caloric intake and progress towards their weight loss goal
    if (netCalories > calorieGoal) {
        printf("\nYou consumed %.2f calories today and burned %.2f calories. Your net caloric intake is %.2f calories. You are %.2f calories over your daily goal. Keep up the good work!", caloriesConsumed, caloriesBurned, netCalories, netCalories - calorieGoal);
    } else if (netCalories < calorieGoal) {
        printf("\nYou consumed %.2f calories today and burned %.2f calories. Your net caloric intake is %.2f calories. You are %.2f calories under your daily goal. Great job, keep it up!", caloriesConsumed, caloriesBurned, netCalories, calorieGoal - netCalories);
    } else {
        printf("\nYou consumed %.2f calories today and burned %.2f calories. Your net caloric intake is %.2f calories. You met your daily goal! Way to go!", caloriesConsumed, caloriesBurned, netCalories);
    }

    // Free dynamically allocated memory for gender
    free(gender);

    return 0;
}