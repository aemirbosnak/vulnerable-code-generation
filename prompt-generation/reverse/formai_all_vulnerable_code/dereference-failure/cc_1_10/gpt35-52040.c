//FormAI DATASET v1.0 Category: Online Examination System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//node structure for holding exam questions and answers
typedef struct node{
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correct_option;
    struct node* next;
}Node;

//function to add a new question to the exam list
void addQuestion(Node** head_ref, char question[100], char option1[50], char option2[50], char option3[50], char option4[50], int correct_option)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->question, question);
    strcpy(new_node->option1, option1);
    strcpy(new_node->option2, option2);
    strcpy(new_node->option3, option3);
    strcpy(new_node->option4, option4);
    new_node->correct_option = correct_option;

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//function to display all the questions in the exam list
void displayQuestions(Node* node)
{
    while(node!=NULL)
    {
        printf("%s\n", node->question);
        printf("1. %s\n", node->option1);
        printf("2. %s\n", node->option2);
        printf("3. %s\n", node->option3);
        printf("4. %s\n", node->option4);
        printf("Answer: ");
        node = node->next;
    }
}

//function to take the exam by displaying all the questions and accepting user inputs as answers
void takeExam(Node* node)
{
    int answer, score=0;
    while(node!=NULL)
    {
        printf("%s\n", node->question);
        printf("1. %s\n", node->option1);
        printf("2. %s\n", node->option2);
        printf("3. %s\n", node->option3);
        printf("4. %s\n", node->option4);
        printf("Answer: ");
        scanf("%d", &answer);
        if(answer==node->correct_option)
            score++;
        node = node->next;
    }
    printf("Your score: %d\n", score);
}

//main function to test the program
int main()
{
    Node* head = NULL;

    //adding questions to the exam list
    addQuestion(&head, "What is the capital of India?", "Mumbai", "Delhi", "Kolkata", "Chennai", 2);
    addQuestion(&head, "What is the national animal of India?", "Lion", "Tiger", "Leopard", "Elephant", 2);
    addQuestion(&head, "Which is the largest state in India?", "Maharashtra", "Rajasthan", "Madhya Pradesh", "Uttar Pradesh", 2);

    printf("Welcome to the online exam system!\n");

    //displaying the questions
    printf("\nQuestions:\n");
    displayQuestions(head);

    //taking the exam
    printf("\nPlease answer all the questions:\n");
    takeExam(head);

    printf("Thank you for taking the online exam!\n");

    return 0;
}