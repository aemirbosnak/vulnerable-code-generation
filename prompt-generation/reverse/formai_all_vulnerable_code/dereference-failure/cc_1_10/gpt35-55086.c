//FormAI DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_ANSWER_LENGTH 20

typedef struct {
    char question[100];
    char answers[4][MAX_ANSWER_LENGTH];
    int correct_answer;
} Question;

void print_question(Question *q) {
    printf("%s\n", q->question);
    for (int i = 0; i < 4; i++) {
        printf("%c) %s\n", 'A' + i, q->answers[i]);
    }
}

int main() {
    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);
    getchar();  // consume newline
    
    Question *questions = malloc(num_questions * sizeof(Question));
    
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i+1);
        printf("Enter the question: ");
        fgets(questions[i].question, sizeof(questions[i].question), stdin);
        questions[i].question[strlen(questions[i].question)-1] = '\0';  // remove newline
        for (int j = 0; j < 4; j++) {
            printf("Enter answer %c: ", 'A'+j);
            fgets(questions[i].answers[j], MAX_ANSWER_LENGTH, stdin);
            questions[i].answers[j][strlen(questions[i].answers[j])-1] = '\0';  // remove newline
        }
        printf("Enter the correct answer (A, B, C, or D): ");
        char answer;
        scanf("%c", &answer);
        getchar();  // consume newline
        switch (answer) {
            case 'A': questions[i].correct_answer = 0; break;
            case 'B': questions[i].correct_answer = 1; break;
            case 'C': questions[i].correct_answer = 2; break;
            case 'D': questions[i].correct_answer = 3; break;
            default: printf("Invalid answer. Setting correct answer to A.\n");
                     questions[i].correct_answer = 0;
        }
        
        printf("\n");
    }
    
    // Write questions to file
    FILE *fptr;
    if ((fptr = fopen("questions.txt", "w")) == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fprintf(fptr, "%d\n", num_questions);
    for (int i = 0; i < num_questions; i++) {
        fprintf(fptr, "%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            fprintf(fptr, "%s\n", questions[i].answers[j]);
        }
        fprintf(fptr, "%d\n", questions[i].correct_answer);
    }
    fclose(fptr);
    printf("Questions saved.\n");
    
    // Read questions from file
    if ((fptr = fopen("questions.txt", "r")) == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fscanf(fptr, "%d", &num_questions);
    Question *loaded_questions = malloc(num_questions * sizeof(Question));
    for (int i = 0; i < num_questions; i++) {
        fgets(loaded_questions[i].question, sizeof(loaded_questions[i].question), fptr);
        loaded_questions[i].question[strlen(loaded_questions[i].question)-1] = '\0';  // remove newline
        for (int j = 0; j < 4; j++) {
            fgets(loaded_questions[i].answers[j], MAX_ANSWER_LENGTH, fptr);
            loaded_questions[i].answers[j][strlen(loaded_questions[i].answers[j])-1] = '\0'; //remove newline
        }
        fscanf(fptr, "%d", &loaded_questions[i].correct_answer);
    }
    fclose(fptr);
    
    // Print the questions
    printf("Loaded questions:\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i+1);
        print_question(&loaded_questions[i]);
        printf("\n");
    }
    
    free(questions);
    free(loaded_questions);
    return 0;
}