//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
    char name[100];
    char email[100];
    char phone[20];
    char education[100];
    char skills[500];
};

struct resume* parseResume(char *fileName);

int main() {
    char fileName[100];
    printf("Enter the name of the resume file: ");
    scanf("%s", fileName);

    struct resume *myResume = parseResume(fileName);

    // Print out the parsed resume information
    printf("Name: %s\n", myResume->name);
    printf("Email: %s\n", myResume->email);
    printf("Phone: %s\n", myResume->phone);
    printf("Education: %s\n", myResume->education);
    printf("Skills: %s\n", myResume->skills);

    free(myResume); // Free the dynamically allocated memory

    return 0;
}

struct resume* parseResume(char *fileName) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    struct resume *myResume = (struct resume*) malloc(sizeof(struct resume)); // Dynamically allocate memory for the resume

    char tempString[300];

    // Get name
    fgets(tempString, 300, fp);
    strncpy(myResume->name, tempString, strlen(tempString) - 1); // Remove newline character
    myResume->name[strlen(tempString) - 1] = '\0';

    // Get email
    fgets(tempString, 300, fp);
    strncpy(myResume->email, tempString, strlen(tempString) - 1); // Remove newline character
    myResume->email[strlen(tempString) - 1] = '\0';

    // Get phone
    fgets(tempString, 300, fp);
    strncpy(myResume->phone, tempString, strlen(tempString) - 1); // Remove newline character
    myResume->phone[strlen(tempString) - 1] = '\0';

    // Get education
    fgets(tempString, 300, fp);
    strncpy(myResume->education, tempString, strlen(tempString) - 1); // Remove newline character
    myResume->education[strlen(tempString) - 1] = '\0';

    // Get skills
    fgets(tempString, 300, fp);
    strncpy(myResume->skills, tempString, strlen(tempString) - 1); // Remove newline character
    myResume->skills[strlen(tempString) - 1] = '\0';

    fclose(fp);

    return myResume;
}