//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

struct Exam
{
    int id;
    char* name;
    char* question;
    char* answer;
    char* options[5];
};

int main()
{
    struct Exam exam;
    int option;

    printf("Enter Exam ID: ");
    scanf("%d", &exam.id);
    scanf("\n");

    printf("Enter Exam Name: ");
    scanf("%s", exam.name);
    scanf("\n");

    printf("Enter Exam Question: ");
    scanf("%s", exam.question);
    scanf("\n");

    printf("Enter Exam Answer: ");
    scanf("%s", exam.answer);
    scanf("\n");

    printf("Enter Exam Options (comma-separated): ");
    scanf("%s", exam.options[0]);
    scanf("\n");
    for(int i = 1; i < 5; i++)
    {
        scanf("%s", exam.options[i]);
        if(strlen(exam.options[i]) > MAX_LEN)
        {
            printf("Option too long, please enter a shorter option.\n");
            return 1;
        }
    }

    printf("Enter Exam Option: ");
    scanf("%d", &option);

    if(option >= 0 && option <= 4)
    {
        printf("Correct Answer!\n");
    }
    else
    {
        printf("Incorrect Answer!\n");
    }

    return 0;
}