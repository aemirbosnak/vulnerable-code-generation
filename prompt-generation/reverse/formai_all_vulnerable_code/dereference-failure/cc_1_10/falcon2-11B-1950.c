//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the student has answered all the questions
int checkAllQuestionsAnswered(char *studentAnswers) {
    int numQuestions = 10; // Number of questions in the exam
    int i;
    for (i = 0; i < numQuestions; i++) {
        if (strcmp(studentAnswers[i], " ") == 0) {
            return 0; // Student has not answered all questions
        }
    }
    return 1; // Student has answered all questions
}

// Function to calculate the student's score
int calculateScore(char *studentAnswers) {
    int score = 0;
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(studentAnswers[i], "A") == 0) {
            score += 1;
        } else if (strcmp(studentAnswers[i], "B") == 0) {
            score += 2;
        } else if (strcmp(studentAnswers[i], "C") == 0) {
            score += 3;
        } else if (strcmp(studentAnswers[i], "D") == 0) {
            score += 4;
        }
    }
    return score;
}

// Function to display the exam results
void displayResults(int score) {
    if (score >= 60) {
        printf("Congratulations! You have passed the exam.\n");
    } else {
        printf("Sorry! You have failed the exam.\n");
    }
}

int main() {
    char studentAnswers[10][10] = {
        " ", "A", " ", "B", " ", "C", " ", "D", " ", "A"
    };
    int score = calculateScore(studentAnswers);
    if (checkAllQuestionsAnswered(studentAnswers)) {
        displayResults(score);
    }
    return 0;
}