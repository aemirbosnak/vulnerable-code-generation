//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Let's start our C Resume Parsing System with a happy message!
int main()
{
    printf("Welcome to the C Resume Parsing System! Let's parse some resumes!\n");

    // Create an array of structs to store resume information
    struct Resume {
        char name[50];
        int age;
        char education[100];
        char experience[100];
    };

    // Prompt user to enter number of resumes to parse
    int numResumes;
    printf("\nHow many resumes would you like to parse?: ");
    scanf("%d", &numResumes);

    // Initialize an array of resume structs with user-specified size
    struct Resume resumes[numResumes];

    // Loop through each resume input by user and store in array of structs
    for (int i = 0; i < numResumes; i++) 
    {
        printf("\nEnter the Name: ");
        scanf("%s", resumes[i].name);

        printf("\nEnter Age: ");
        scanf("%d", &resumes[i].age);

        printf("\nEnter Education: ");
        scanf("%s", resumes[i].education);

        printf("\nEnter Experience: ");
        scanf("%s", resumes[i].experience);

        printf("\nResume successfully parsed and stored!\n");
    }

    // Display the parsed resumes
    printf("\n------------------------\n");
    printf("Parsed Resumes:\n");
    printf("------------------------\n");
    for (int i = 0; i < numResumes; i++) 
    {
        printf("\nName: %s\n", resumes[i].name);
        printf("Age: %d\n", resumes[i].age);
        printf("Education: %s\n", resumes[i].education);
        printf("Experience: %s\n", resumes[i].experience);
    }

    // We're all done! Let's end our program with another happy message
    printf("\nResume parsing complete! Thank you for using the C Resume Parsing System.\n");

    return 0;
}