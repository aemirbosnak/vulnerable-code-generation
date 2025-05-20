//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Question {
    char* question;
    char* answer1;
    char* answer2;
    char* answer3;
    char* answer4;
    char* correct_answer;
    struct Question* next;
} Question;

typedef struct QuestionList {
    Question* head;
    Question* tail;
} QuestionList;

void addQuestion(QuestionList* list, char* question, char* answer1, char* answer2, char* answer3, char* answer4, char* correct_answer) {
    Question* new_question = (Question*) malloc(sizeof(Question));
    strcpy(new_question->question, question);
    strcpy(new_question->answer1, answer1);
    strcpy(new_question->answer2, answer2);
    strcpy(new_question->answer3, answer3);
    strcpy(new_question->answer4, answer4);
    strcpy(new_question->correct_answer, correct_answer);
    new_question->next = NULL;

    if (list->head == NULL) {
        list->head = new_question;
        list->tail = new_question;
    } else {
        list->tail->next = new_question;
        list->tail = new_question;
    }
}

void printQuestions(QuestionList* list) {
    Question* current = list->head;

    while (current!= NULL) {
        printf("%s\n", current->question);
        current = current->next;
    }
}

int main() {
    QuestionList question_list;
    question_list.head = NULL;
    question_list.tail = NULL;

    // Add some questions to the list
    addQuestion(&question_list, "What is the capital of France?", "Paris", "London", "Berlin", "Paris", "Paris");
    addQuestion(&question_list, "What is the largest planet in our solar system?", "Jupiter", "Saturn", "Mars", "Jupiter", "Jupiter");
    addQuestion(&question_list, "What is the smallest country in the world?", "Vatican City", "Monaco", "San Marino", "Vatican City", "Vatican City");

    // Print the questions
    printf("Questions:\n");
    printQuestions(&question_list);

    // Add some more questions to the list
    addQuestion(&question_list, "What is the smallest continent in the world?", "Antarctica", "North America", "South America", "Antarctica", "Antarctica");
    addQuestion(&question_list, "What is the most populous country in the world?", "China", "India", "United States", "China", "China");

    // Print the updated questions
    printf("\nUpdated questions:\n");
    printQuestions(&question_list);

    return 0;
}