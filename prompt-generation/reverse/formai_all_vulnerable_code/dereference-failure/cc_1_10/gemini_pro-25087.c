//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char *name;
    char *email;
    char *password;
} User;

typedef struct {
    int id;
    char *title;
    char *description;
    int duration;
    int difficulty;
    char **questions;
    char **answers;
} Exam;

typedef struct {
    int id;
    User *user;
    Exam *exam;
    int score;
} Result;

void create_user(User **user, char *name, char *email, char *password) {
    *user = malloc(sizeof(User));
    (*user)->id = rand();
    (*user)->name = strdup(name);
    (*user)->email = strdup(email);
    (*user)->password = strdup(password);
}

void create_exam(Exam **exam, char *title, char *description, int duration, int difficulty, char **questions, char **answers) {
    *exam = malloc(sizeof(Exam));
    (*exam)->id = rand();
    (*exam)->title = strdup(title);
    (*exam)->description = strdup(description);
    (*exam)->duration = duration;
    (*exam)->difficulty = difficulty;
    (*exam)->questions = questions;
    (*exam)->answers = answers;
}

void create_result(Result **result, User *user, Exam *exam, int score) {
    *result = malloc(sizeof(Result));
    (*result)->id = rand();
    (*result)->user = user;
    (*result)->exam = exam;
    (*result)->score = score;
}

void print_user(User *user) {
    printf("User ID: %d\n", user->id);
    printf("User Name: %s\n", user->name);
    printf("User Email: %s\n", user->email);
    printf("User Password: %s\n", user->password);
}

void print_exam(Exam *exam) {
    printf("Exam ID: %d\n", exam->id);
    printf("Exam Title: %s\n", exam->title);
    printf("Exam Description: %s\n", exam->description);
    printf("Exam Duration: %d\n", exam->duration);
    printf("Exam Difficulty: %d\n", exam->difficulty);

    for (int i = 0; i < exam->duration; i++) {
        printf("Question %d: %s\n", i + 1, exam->questions[i]);
        printf("Answer %d: %s\n", i + 1, exam->answers[i]);
    }
}

void print_result(Result *result) {
    printf("Result ID: %d\n", result->id);
    printf("User ID: %d\n", result->user->id);
    printf("Exam ID: %d\n", result->exam->id);
    printf("Score: %d\n", result->score);
}

int main() {
    // Create a user
    User *user;
    create_user(&user, "John Doe", "johndoe@example.com", "password123");

    // Create an exam
    Exam *exam;
    char *questions[] = {"What is the capital of France?", "What is the largest country in the world?", "What is the name of the largest ocean in the world?"};
    char *answers[] = {"Paris", "Russia", "Pacific Ocean"};
    create_exam(&exam, "World Geography Exam", "This exam will test your knowledge of world geography.", 60, 3, questions, answers);

    // Create a result
    Result *result;
    create_result(&result, user, exam, 100);

    // Print the user, exam, and result
    printf("User:\n");
    print_user(user);
    printf("\nExam:\n");
    print_exam(exam);
    printf("\nResult:\n");
    print_result(result);

    // Free the allocated memory
    free(user->name);
    free(user->email);
    free(user->password);
    free(user);
    free(exam->title);
    free(exam->description);
    for (int i = 0; i < exam->duration; i++) {
        free(exam->questions[i]);
        free(exam->answers[i]);
    }
    free(exam->questions);
    free(exam->answers);
    free(exam);
    free(result);

    return 0;
}