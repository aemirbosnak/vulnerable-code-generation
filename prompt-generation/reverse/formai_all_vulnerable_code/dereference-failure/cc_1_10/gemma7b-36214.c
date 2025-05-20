//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DisplayMenu(void)
{
    system("cls");
    printf("----------------------------------------\n");
    printf("Electronic Voting System\n");
    printf("----------------------------------------\n");
    printf("1. Register Voter\n");
    printf("2. Vote\n");
    printf("3. View Results\n");
    printf("4. Exit\n");
    printf("Please enter your choice: ");
}

void RegisterVoter(char **name, int *age)
{
    printf("Enter your full name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", age);

    if (*age < 18)
    {
        printf("Sorry, you are not eligible to vote.\n");
    }
    else
    {
        printf("You have been successfully registered to vote.\n");
    }
}

void Vote(char **name, int *age)
{
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your age: ");
    scanf("%d", age);

    if (*name != **name)
    {
        printf("Sorry, you are not registered to vote.\n");
    }
    else if (*age < 18)
    {
        printf("Sorry, you are not eligible to vote.\n");
    }
    else
    {
        printf("You have successfully voted.\n");
    }
}

void ViewResults(void)
{
    system("cls");
    printf("----------------------------------------\n");
    printf("Electronic Voting System Results\n");
    printf("----------------------------------------\n");
    printf("The results are not yet available.\n");
}

int main()
{
    char **name;
    int *age;
    int choice;

    DisplayMenu();
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            RegisterVoter(name, age);
            break;
        case 2:
            Vote(name, age);
            break;
        case 3:
            ViewResults();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid input.\n");
    }

    main();
}