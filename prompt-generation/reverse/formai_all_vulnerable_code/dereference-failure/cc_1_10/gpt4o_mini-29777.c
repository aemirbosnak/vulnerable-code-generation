//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_USERS 100
#define MAX_LENGTH 100

// Structure to hold question and answer
typedef struct {
    char question[MAX_LENGTH];
    char options[4][MAX_LENGTH];
    char answer;
} Question;

// Structure to hold user information
typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int score;
} User;

// Function prototypes
void loadQuestions(Question *questions, int *totalQuestions);
void registerUser(User *users, int *userCount);
int loginUser(User *users, int userCount);
void takeExam(User *user);
void viewResults(User *user);
void saveResult(User *user);

int main() {
    User users[MAX_USERS];
    int userCount = 0, loggedInUserIndex = -1, choice;
    char continueExam = 'y';

    loadQuestions(NULL, NULL); // Load questions

    while (1) {
        printf("\n=== Online Examination System ===\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Register
                registerUser(users, &userCount);
                break;
            case 2: // Login
                loggedInUserIndex = loginUser(users, userCount);
                if (loggedInUserIndex != -1) {
                    User *currentUser = &users[loggedInUserIndex];
                    while (continueExam == 'y') {
                        takeExam(currentUser);
                        viewResults(currentUser);
                        printf("Do you want to take the exam again? (y/n): ");
                        getchar(); // Clear newline
                        scanf("%c", &continueExam);
                    }
                    continueExam = 'y'; // Reset for next login
                }
                break;
            case 3:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void loadQuestions(Question *questions, int *totalQuestions) {
    // Simple hardcoded questions for the example
    static Question loadedQuestions[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"1) Berlin", "2) Paris", "3) Rome", "4) London"}, '2'},
        {"What is 2 + 2?", {"1) 3", "2) 4", "3) 5", "4) 6"}, '2'},
        {"What programming language is this?", {"1) Python", "2) Java", "3) C", "4) C++"}, '3'},
        {"What is the tallest mountain in the world?", {"1) K2", "2) Mount Everest", "3) Kangchenjunga", "4) Lhotse"}, '2'},
        // Add more questions as needed...
    };
    *totalQuestions = 4; // Set based on hardcoded questions
    questions = loadedQuestions;
}

void registerUser(User *users, int *userCount) {
    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);
    newUser.score = 0;

    users[(*userCount)++] = newUser; // Add new user to array
    printf("User registered successfully!\n");
}

int loginUser(User *users, int userCount) {
    char username[MAX_LENGTH], password[MAX_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return i; // Return the index of the logged-in user
        }
    }
    printf("Invalid username or password.\n");
    return -1; // Login failed
}

void takeExam(User *user) {
    Question questions[MAX_QUESTIONS];
    int totalQuestions;
    loadQuestions(questions, &totalQuestions);
    char answer;
    int score = 0;

    printf("\n=== Exam Time ===\n");
    for (int i = 0; i < totalQuestions; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }
        printf("Your answer: ");
        scanf(" %c", &answer);
        if (answer == questions[i].answer) {
            score++;
        }
    }

    user->score = score;
    saveResult(user); // Save the result after taking the exam
    printf("You scored %d out of %d!\n", user->score, totalQuestions);
}

void viewResults(User *user) {
    printf("\n=== Your Results ===\n");
    printf("Username: %s\n", user->username);
    printf("Score: %d\n", user->score);
}

void saveResult(User *user) {
    FILE *file = fopen("results.txt", "a");
    if (file) {
        fprintf(file, "Username: %s, Score: %d\n", user->username, user->score);
        fclose(file);
    } else {
        printf("Failed to save results.\n");
    }
}