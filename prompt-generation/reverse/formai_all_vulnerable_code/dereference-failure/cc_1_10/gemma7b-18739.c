//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Resume
{
    char name[MAX];
    char email[MAX];
    char phone[MAX];
    char address[MAX];
    struct Resume *next;
} Resume;

int main()
{
    Resume *head = NULL;
    char ch, name[MAX], email[MAX], phone[MAX], address[MAX];

    printf("Enter the number of resumes you want to enter: ");
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter the name of the candidate: ");
        scanf("%s", name);

        printf("Enter the email address of the candidate: ");
        scanf("%s", email);

        printf("Enter the phone number of the candidate: ");
        scanf("%s", phone);

        printf("Enter the address of the candidate: ");
        scanf("%s", address);

        Resume *new_resume = malloc(sizeof(Resume));
        new_resume->next = NULL;
        strcpy(new_resume->name, name);
        strcpy(new_resume->email, email);
        strcpy(new_resume->phone, phone);
        strcpy(new_resume->address, address);

        if (head == NULL)
        {
            head = new_resume;
        }
        else
        {
            new_resume->next = head;
            head = new_resume;
        }
    }

    printf("The resumes have been successfully entered.\n");

    return 0;
}