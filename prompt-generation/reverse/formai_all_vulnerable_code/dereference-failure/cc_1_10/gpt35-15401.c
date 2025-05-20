//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_USERNAME_LENGTH 20
#define MAX_EXERCISE_NAME_LENGTH 20
#define MAX_EXERCISES 10

// User-defined data types
typedef struct {
    char name[MAX_EXERCISE_NAME_LENGTH];
    int sets;
    int reps;
    int weight;
} Exercise;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    Exercise exercises[MAX_EXERCISES];
    int numExercises;
} User;

// Function prototypes
void addExercise(User* user);
void viewHistory(User user);
void printWelcomeMessage();
void printMenu();
void printGoodbyeMessage();
int getIntegerInput();
char* getStringInput();

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));
    
    // Create a new User
    User user;
    printf("Please enter your username: ");
    strcpy(user.username, getStringInput());
    user.numExercises = 0;
    
    // Print welcome message and menu
    printWelcomeMessage();
    printMenu();
    
    // Handle user input
    int choice = getIntegerInput();
    while (choice != 4) {
        switch (choice) {
            case 1:
                addExercise(&user);
                break;
            case 2:
                viewHistory(user);
                break;
            case 3:
                printMenu();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        printf("\n");
        choice = getIntegerInput();
    }
    
    // Print goodbye message
    printGoodbyeMessage();
    
    return 0;
}

// Function definitions
void addExercise(User* user) {
    // Check if user has already added maximum number of exercises
    if (user->numExercises == MAX_EXERCISES) {
        printf("You have already added the maximum number of exercises (%d).\n", MAX_EXERCISES);
        return;
    }
    
    // Prompt user for exercise information
    printf("Please enter the name of the exercise: ");
    strcpy(user->exercises[user->numExercises].name, getStringInput());
    
    printf("Please enter the number of sets: ");
    user->exercises[user->numExercises].sets = getIntegerInput();
    
    printf("Please enter the number of reps: ");
    user->exercises[user->numExercises].reps = getIntegerInput();
    
    printf("Please enter the weight (in pounds): ");
    user->exercises[user->numExercises].weight = getIntegerInput();
    
    // Increment the number of exercises added by the user
    user->numExercises++;
    
    // Print confirmation message
    printf("\nExercise added successfully.\n");
}

void viewHistory(User user) {
    // Check if user has added any exercises
    if (user.numExercises == 0) {
        printf("You have not added any exercises yet.\n");
        return;
    }
    
    // Print exercises in reverse chronological order
    printf("Exercise History:\n");
    for (int i = user.numExercises - 1; i >= 0; i--) {
        printf("%s (Sets: %d, Reps: %d, Weight: %d lbs)\n", user.exercises[i].name, user.exercises[i].sets, user.exercises[i].reps, user.exercises[i].weight);
    }
}

void printWelcomeMessage() {
    printf("Welcome to Retro Fitness Tracker!\n\n");
}

void printMenu() {
    printf("Please choose an option:\n");
    printf("1. Add an exercise\n");
    printf("2. View exercise history\n");
    printf("3. Print menu\n");
    printf("4. Quit\n");
}

void printGoodbyeMessage() {
    printf("Thank you for using Retro Fitness Tracker!\n");
}

int getIntegerInput() {
    int num;
    scanf("%d", &num);
    while (getchar() != '\n');
    return num;
}

char* getStringInput() {
    char* str = (char*) malloc(MAX_EXERCISE_NAME_LENGTH * sizeof(char));
    fgets(str, MAX_EXERCISE_NAME_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0';
    return str;
}