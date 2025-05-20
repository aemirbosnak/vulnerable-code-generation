//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Cv
{
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
    int age;
} Cv;

int main()
{
    Cv cv;
    char resume[MAX_EXPERIENCE_LENGTH];

    printf("Enter the resume text: ");
    fgets(resume, MAX_EXPERIENCE_LENGTH, stdin);

    // Parse the resume text
    char *name = strstr(resume, "Name:");
    char *email = strstr(resume, "Email:");
    char *phone = strstr(resume, "Phone:");
    char *experience = strstr(resume, "Experience:");
    char *age_str = strstr(resume, "Age:");

    // Extract the values from the parsed text
    cv.name[0] = '\0';
    strncpy(cv.name, name + 5, MAX_NAME_LENGTH - 1);

    cv.email[0] = '\0';
    strncpy(cv.email, email + 6, MAX_NAME_LENGTH - 1);

    cv.phone[0] = '\0';
    strncpy(cv.phone, phone + 7, MAX_NAME_LENGTH - 1);

    cv.experience[0] = '\0';
    strncpy(cv.experience, experience + 9, MAX_EXPERIENCE_LENGTH - 1);

    cv.age = atoi(age_str) + 1;

    // Print the parsed data
    printf("Name: %s\n", cv.name);
    printf("Email: %s\n", cv.email);
    printf("Phone: %s\n", cv.phone);
    printf("Experience: %s\n", cv.experience);
    printf("Age: %d\n", cv.age);

    return 0;
}