//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 4
#define MAX_ANSWER_LENGTH 100
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char question[MAX_QUESTIONS];
    char choices[MAX_QUESTIONS][MAX_CHOICES][MAX_ANSWER_LENGTH];
    char answer[MAX_QUESTIONS];
} Question;

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    int score;
} User;

void readQuestions(Question *questions) {
    FILE *file = fopen("questions.txt", "r");
    int count = 0;
    while (fscanf(file, "%s", questions[count].question) == 1 && count < MAX_QUESTIONS) {
        int choiceCount = 0;
        while (fscanf(file, "%s", questions[count].choices[choiceCount]) == 1 && choiceCount < MAX_CHOICES && count < MAX_QUESTIONS) {
            choiceCount++;
        }
        questions[count].answer[0] = '\0';
        count++;
    }
    fclose(file);
}

void readUsers(User *users, int numUsers) {
    FILE *file = fopen("users.txt", "r");
    int count = 0;
    while (fscanf(file, "%s", users[count].username) == 1 && count < numUsers) {
        users[count].score = 0;
        count++;
    }
    fclose(file);
}

void writeUsers(User *users, int numUsers) {
    FILE *file = fopen("users.txt", "w");
    int count = 0;
    while (count < numUsers) {
        fprintf(file, "%s\n", users[count].username);
        count++;
    }
    fclose(file);
}

int main() {
    int numUsers;
    printf("Enter the number of users: ");
    scanf("%d", &numUsers);
    User users[numUsers];
    readUsers(users, numUsers);

    Question questions[MAX_QUESTIONS];
    readQuestions(questions);

    int numCorrect = 0;
    int userIndex = 0;
    while (userIndex < numUsers) {
        printf("User %s's score: %d\n", users[userIndex].username, users[userIndex].score);
        userIndex++;
    }

    return 0;
}