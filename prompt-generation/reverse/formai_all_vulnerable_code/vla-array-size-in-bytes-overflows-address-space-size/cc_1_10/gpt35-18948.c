//FormAI DATASET v1.0 Category: Online Examination System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    int id;
    char text[100];
    char options[4][50];
    int answer;
};

int main() {
    int numQuestions, numOptions, correctAnswers;
    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);
    printf("Enter the number of options per question: ");
    scanf("%d", &numOptions);
    printf("Enter the number of correct answers: ");
    scanf("%d", &correctAnswers);
    
    struct Question questions[numQuestions];
    
    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d:\n", i + 1);
        printf("Enter the question text: ");
        fgets(questions[i].text, 100, stdin);
        
        for (int j = 0; j < numOptions; j++) {
            printf("Enter option %d: ", j + 1);
            fgets(questions[i].options[j], 50, stdin);
        }
        
        printf("Enter the index of the correct answer (1-%d): ", numOptions);
        scanf("%d", &questions[i].answer);
    }
    
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d:\n%s", i + 1, questions[i].text);
        
        for (int j = 0; j < numOptions; j++) {
            printf("%d. %s", j + 1, questions[i].options[j]);
        }
        
        int choice;
        printf("Enter your choice (1-%d): ", numOptions);
        scanf("%d", &choice);
        
        if (choice == questions[i].answer) {
            score++;
        }
    }
    
    printf("Your score is %d/%d\n", score, numQuestions);
    
    if (score >= correctAnswers) {
        printf("Congratulations, you have passed the exam!\n");
    }
    else {
        printf("Sorry, you have failed the exam.\n");
    }
    
    return 0;
}