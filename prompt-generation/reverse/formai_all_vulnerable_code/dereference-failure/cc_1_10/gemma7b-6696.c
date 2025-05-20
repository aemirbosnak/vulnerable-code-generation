//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[255];
    int answer;
    struct Question* next;
} Question;

void createQuestion(Question** head) {
    *head = malloc(sizeof(Question));
    (*head)->question[0] = '\0';
    (*head)->answer = 0;
    (*head)->next = NULL;
}

void addQuestion(Question* head, char* question, int answer) {
    Question* newQuestion = malloc(sizeof(Question));
    newQuestion->question[0] = '\0';
    newQuestion->answer = answer;
    newQuestion->next = NULL;

    if (head == NULL) {
        createQuestion(&head);
    }

    Question* currentQuestion = head;
    while (currentQuestion->next) {
        currentQuestion = currentQuestion->next;
    }

    currentQuestion->next = newQuestion;
}

int main() {
    Question* head = NULL;

    addQuestion(head, "What is the meaning of life?", 42);
    addQuestion(head, "Who is the president of the United States?", 46);
    addQuestion(head, "What is the capital of France?", 14);

    int numQuestions = 0;
    Question* currentQuestion = head;
    while (currentQuestion) {
        numQuestions++;
        currentQuestion = currentQuestion->next;
    }

    printf("Number of questions: %d\n", numQuestions);

    currentQuestion = head;
    while (currentQuestion) {
        printf("Question: %s\n", currentQuestion->question);
        printf("Answer: %d\n", currentQuestion->answer);
        printf("\n");
        currentQuestion = currentQuestion->next;
    }

    return 0;
}