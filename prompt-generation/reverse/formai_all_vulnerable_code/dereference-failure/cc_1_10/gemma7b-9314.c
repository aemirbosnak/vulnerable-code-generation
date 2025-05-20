//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

struct Question
{
    char *question;
    int answer;
    struct Question *next;
};

struct Student
{
    char *name;
    int rollNo;
    struct Student *next;
};

void insertQuestion(struct Question **head, char *question, int answer)
{
    struct Question *newQuestion = malloc(sizeof(struct Question));
    newQuestion->question = strdup(question);
    newQuestion->answer = answer;
    newQuestion->next = NULL;

    if (*head == NULL)
    {
        *head = newQuestion;
    }
    else
    {
        (*head)->next = newQuestion;
    }
}

void insertStudent(struct Student **head, char *name, int rollNo)
{
    struct Student *newStudent = malloc(sizeof(struct Student));
    newStudent->name = strdup(name);
    newStudent->rollNo = rollNo;
    newStudent->next = NULL;

    if (*head == NULL)
    {
        *head = newStudent;
    }
    else
    {
        (*head)->next = newStudent;
    }
}

int main()
{
    struct Question *questions = NULL;
    struct Student *students = NULL;

    insertQuestion(&questions, "What is the meaning of life?", 42);
    insertQuestion(&questions, "Who invented the telephone?", 10);
    insertQuestion(&questions, "What is the capital of France?", 14);

    insertStudent(&students, "John Doe", 12);
    insertStudent(&students, "Jane Doe", 13);
    insertStudent(&students, "Peter Pan", 14);

    // Conduct the exam
    for (struct Student *student = students; student; student = student->next)
    {
        printf("Student name: %s, roll no: %d\n", student->name, student->rollNo);

        for (struct Question *question = questions; question; question = question->next)
        {
            printf("Question: %s, answer: %d\n", question->question, question->answer);

            int answer = getchar();

            if (answer == question->answer)
            {
                printf("Correct!\n");
            }
            else
            {
                printf("Incorrect. The answer is: %d\n", question->answer);
            }
        }

        printf("\n");
    }

    return 0;
}