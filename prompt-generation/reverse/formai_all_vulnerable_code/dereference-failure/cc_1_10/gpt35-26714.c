//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the structure of resume */
struct Resume {
    char name[30];
    char email[30];
    char phone[15];
    char education[30];
    char experience[50];
};

/* Parse the resume data */
void parseResumeData(struct Resume *res, char *inputLine) {
    char *token;
    char delim[] = ",";
    token = strtok(inputLine, delim);

    /* Set the name */
    strcpy(res->name, token);
    token = strtok(NULL, delim);

    /* Set the email */
    strcpy(res->email, token);
    token = strtok(NULL, delim);

    /* Set the phone */
    strcpy(res->phone, token);
    token = strtok(NULL, delim);

    /* Set the education */
    strcpy(res->education, token);
    token = strtok(NULL, delim);

    /* Set the experience */
    strcpy(res->experience, token);
}

/* Display the resume data */
void displayResumeData(struct Resume *res) {
    printf("%s\n", res->name);
    printf("%s\n", res->email);
    printf("%s\n", res->phone);
    printf("%s\n", res->education);
    printf("%s\n", res->experience);
}

/* Main function */
int main() {
    /* Declare variables */
    struct Resume res;
    char inputLine[1000];

    printf("Enter name, email, phone, education, and experience (separated by commas):\n");

    /* Get the input from the user and parse the data */
    fgets(inputLine, 1000, stdin);
    parseResumeData(&res, inputLine);

    /* Display the resume data */
    printf("\nResume Data:\n");
    displayResumeData(&res);

    return 0;
}