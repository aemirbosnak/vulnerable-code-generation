//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_INT 2147483647
#define MAX_STRlen 100

// Define a struct to hold a curious exercise
struct CuriousExercise {
    int num1, num2, num3;
    char op[3];
    int answer;
};

// Function to generate a curious exercise
struct CuriousExercise* generate_exercise(void) {
    struct CuriousExercise* exercise = malloc(sizeof(struct CuriousExercise));

    // Generate a random number between 1 and 100
    exercise->num1 = (int)(rand() % 100) + 1;

    // Generate a random number between 1 and 100
    exercise->num2 = (int)(rand() % 100) + 1;

    // Generate a random operator (add, sub, mul, div)
    char op[3];
    switch (rand() % 4) {
        case 0:
            strcpy(op, "+");
            break;
        case 1:
            strcpy(op, "-");
            break;
        case 2:
            strcpy(op, "*");
            break;
        case 3:
            strcpy(op, "/");
            break;
    }

    // Generate a random answer
    exercise->answer = (int)(rand() % 100) + 1;

    // Print the exercise
    printf("Curious Exercise: %d %c %d = %d\n", exercise->num1, op, exercise->num2, exercise->answer);

    return exercise;
}

// Function to solve the curious exercise
int solve_exercise(struct CuriousExercise* exercise) {
    int result;

    // Evaluate the expression
    switch (exercise->op[0]) {
        case '+':
            result = exercise->num1 + exercise->num2;
            break;
        case '-':
            result = exercise->num1 - exercise->num2;
            break;
        case '*':
            result = exercise->num1 * exercise->num2;
            break;
        case '/':
            result = exercise->num1 / exercise->num2;
            break;
    }

    // Check if the answer is correct
    if (result == exercise->answer) {
        printf("Correct! The answer is %d\n", result);
        return 1;
    } else {
        printf("Incorrect. The answer is %d\n", result);
        return 0;
    }
}

int main(void) {
    struct CuriousExercise* exercise = generate_exercise();

    // Solve the exercise
    int result = solve_exercise(exercise);

    // Free the memory
    free(exercise);

    return 0;
}