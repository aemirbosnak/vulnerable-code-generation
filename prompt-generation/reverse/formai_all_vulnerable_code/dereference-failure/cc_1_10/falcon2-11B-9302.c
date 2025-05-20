//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CALORIES 3000
#define MAX_EXERCISES 10

// Define a struct to hold user data
typedef struct {
    int calories;
    int exercises;
    int exerciseCount;
    int lastExerciseDate;
    int lastExerciseTime;
} User;

// Function to initialize a new user
User* initUser() {
    User* user = (User*)malloc(sizeof(User));
    user->calories = 0;
    user->exercises = 0;
    user->exerciseCount = 0;
    user->lastExerciseDate = 0;
    user->lastExerciseTime = 0;
    return user;
}

// Function to add calories to the user's daily intake
void addCalories(User* user, int calories) {
    user->calories += calories;
    printf("Added %d calories to the user's daily intake\n", calories);
}

// Function to add an exercise to the user's routine
void addExercise(User* user, int exercise) {
    user->exercises++;
    printf("Added %d exercise to the user's routine\n", exercise);
}

// Function to track the user's last exercise date and time
void trackExercise(User* user, int exercise, int date, int time) {
    user->lastExerciseDate = date;
    user->lastExerciseTime = time;
    printf("Last exercise date: %d\nLast exercise time: %d\n", date, time);
}

// Function to calculate the user's daily calorie intake
int calculateCalories(User* user) {
    int calories = user->calories;
    printf("Daily calorie intake: %d\n", calories);
    return calories;
}

// Function to calculate the user's daily exercise routine
int calculateExerciseRoutine(User* user) {
    int exerciseRoutine = user->exercises;
    printf("Daily exercise routine: %d\n", exerciseRoutine);
    return exerciseRoutine;
}

// Function to calculate the user's total calories burned
int calculateTotalCaloriesBurned(User* user) {
    int totalCaloriesBurned = user->calories - MAX_CALORIES;
    printf("Total calories burned: %d\n", totalCaloriesBurned);
    return totalCaloriesBurned;
}

// Function to calculate the user's total exercise count
int calculateTotalExerciseCount(User* user) {
    int totalExerciseCount = user->exerciseCount;
    printf("Total exercise count: %d\n", totalExerciseCount);
    return totalExerciseCount;
}

// Function to display user data
void displayUserData(User* user) {
    printf("User Data:\n");
    printf("Calories: %d\n", user->calories);
    printf("Exercises: %d\n", user->exercises);
    printf("Exercise Count: %d\n", user->exerciseCount);
    printf("Last Exercise Date: %d\n", user->lastExerciseDate);
    printf("Last Exercise Time: %d\n", user->lastExerciseTime);
}

// Function to free user memory
void freeUserMemory(User* user) {
    free(user);
}

int main() {
    srand(time(NULL));
    User* user = initUser();

    // Add calories to user's daily intake
    addCalories(user, 500);
    addCalories(user, 200);
    addCalories(user, 300);

    // Add exercises to user's routine
    addExercise(user, 1);
    addExercise(user, 2);
    addExercise(user, 3);
    addExercise(user, 4);
    addExercise(user, 5);

    // Track user's last exercise date and time
    trackExercise(user, 1, 10, 11);
    trackExercise(user, 2, 20, 21);
    trackExercise(user, 3, 30, 31);

    // Calculate user's daily calorie intake
    int dailyCalories = calculateCalories(user);

    // Calculate user's daily exercise routine
    int dailyExerciseRoutine = calculateExerciseRoutine(user);

    // Calculate user's total calories burned
    int totalCaloriesBurned = calculateTotalCaloriesBurned(user);

    // Calculate user's total exercise count
    int totalExerciseCount = calculateTotalExerciseCount(user);

    // Display user data
    displayUserData(user);

    // Free user memory
    freeUserMemory(user);

    return 0;
}