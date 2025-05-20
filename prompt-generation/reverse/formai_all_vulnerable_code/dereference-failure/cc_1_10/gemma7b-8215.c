//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 100

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
    struct Question* next;
} Question;

Question* createQuestion(char* question, char* answer, int marks) {
    Question* newQuestion = (Question*)malloc(sizeof(Question));
    strcpy(newQuestion->question, question);
    strcpy(newQuestion->answer, answer);
    newQuestion->marks = marks;
    newQuestion->next = NULL;
    return newQuestion;
}

void addQuestion(Question** head, char* question, char* answer, int marks) {
    Question* newQuestion = createQuestion(question, answer, marks);
    if (*head == NULL) {
        *head = newQuestion;
    } else {
        (*head)->next = newQuestion;
    }
}

void startExam(Question* head) {
    time_t start = time(NULL);
    printf("Time started: %s\n", ctime(&start));

    while (head) {
        printf("Question: %s\n", head->question);
        printf("Answer: ");
        char answer[256];
        scanf("%s", answer);

        if (strcmp(answer, head->answer) == 0) {
            printf("Marks: %d\n", head->marks);
        } else {
            printf("Incorrect answer. Marks: 0\n");
        }

        head = head->next;
    }

    time_t end = time(NULL);
    printf("Time ended: %s\n", ctime(&end));
    printf("Total marks: %d\n", head->marks);
}

int main() {
    Question* head = NULL;
    addQuestion(&head, "What is the meaning of life?", "To be happy", 10);
    addQuestion(&head, "What is the sound of one hand clapping?", "Silence", 5);
    addQuestion(&head, "Who invented the telephone?", "Alexander Graham Bell", 7);

    startExam(head);

    return 0;
}