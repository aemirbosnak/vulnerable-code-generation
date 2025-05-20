//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure to hold the parsed data
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char skills[500];
} Resume;

//Function to parse the resume
Resume parseResume(char* fileName) {
    Resume parsedResume;
    FILE* file = fopen(fileName, "r");

    //Check if file exists
    if (file == NULL) {
        perror("Error: ");
        exit(EXIT_FAILURE);
    }

    char line[100];
    while(fgets(line, 100, file) != NULL) {
        //Split the line into tokens
        char* token = strtok(line, ":");

        //Extract data based on the token
        if (strcmp(token, "Name") == 0) {
            token = strtok(NULL, ":");
            strcpy(parsedResume.name, token);
        }
        else if (strcmp(token, "Email") == 0) {
            token = strtok(NULL, ":");
            strcpy(parsedResume.email, token);
        }
        else if (strcmp(token, "Phone") == 0) {
            token = strtok(NULL, ":");
            strcpy(parsedResume.phone, token);
        }
        else if (strcmp(token, "Skills") == 0) {
            token = strtok(NULL, ":");
            strcpy(parsedResume.skills, token);
        }
    }

    fclose(file);
    return parsedResume;
}

int main() {
    char fileName[] = "resume.txt";
    Resume parsedResume = parseResume(fileName);

    printf("Name: %s\n", parsedResume.name);
    printf("Email: %s\n", parsedResume.email);
    printf("Phone: %s\n", parsedResume.phone);
    printf("Skills: %s\n", parsedResume.skills);

    return 0;
}