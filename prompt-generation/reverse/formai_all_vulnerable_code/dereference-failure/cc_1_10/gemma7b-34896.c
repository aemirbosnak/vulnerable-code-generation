//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct Resume
{
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_NAME_LENGTH];
    char address[MAX_NAME_LENGTH];
    char phone_number[MAX_NAME_LENGTH];
} Resume;

int main()
{
    // Allocate memory for a Resume structure
    Resume* resume = malloc(sizeof(Resume));

    // Get the resume data from the user
    printf("Enter your name: ");
    scanf("%s", resume->name);

    printf("Enter your age: ");
    scanf("%d", &resume->age);

    printf("Enter your occupation: ");
    scanf("%s", resume->occupation);

    printf("Enter your address: ");
    scanf("%s", resume->address);

    printf("Enter your phone number: ");
    scanf("%s", resume->phone_number);

    // Print the resume data
    printf("\nName: %s\n", resume->name);

    printf("Age: %d\n", resume->age);

    printf("Occupation: %s\n", resume->occupation);

    printf("Address: %s\n", resume->address);

    printf("Phone Number: %s\n", resume->phone_number);

    // Free the memory allocated for the Resume structure
    free(resume);

    return 0;
}