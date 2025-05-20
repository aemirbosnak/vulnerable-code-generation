//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure for a question
typedef struct {
    char question[200];
    char option1[200];
    char option2[200];
    char option3[200];
    char option4[200];
    char answer[10];
} Question;

// Function to read questions from a file
void readQuestions(Question questions[], FILE *fp) {
    int i = 0;
    while (fscanf(fp, "%s %s %s %s %s %s", questions[i].question, questions[i].option1, questions[i].option2, questions[i].option3, questions[i].option4, questions[i].answer)!= EOF) {
        i++;
    }
}

// Function to display a question
void displayQuestion(Question question) {
    printf("Question: %s\n", question.question);
    printf("Options:\n");
    printf("1. %s\n", question.option1);
    printf("2. %s\n", question.option2);
    printf("3. %s\n", question.option3);
    printf("4. %s\n", question.option4);
}

// Function to check the answer
int checkAnswer(char answer[], char correctAnswer[]) {
    if (strcmp(answer, correctAnswer) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to calculate the score
int calculateScore(int correctAnswers) {
    int score = (correctAnswers * 100) / 5;
    return score;
}

// Main function
int main() {
    FILE *fp;
    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }
    
    int numQuestions;
    scanf("%d", &numQuestions);
    
    Question questions[numQuestions];
    readQuestions(questions, fp);
    
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        char answer[10];
        printf("Enter your answer: ");
        scanf("%s", answer);
        if (checkAnswer(answer, questions[i].answer)) {
            score += 1;
        }
    }
    
    int finalScore = calculateScore(score);
    printf("Your final score is: %d\n", finalScore);
    
    return 0;
}