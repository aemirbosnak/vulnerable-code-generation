//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char firstName[20];
    char lastName[20];
    char email[50];
    char phone[15];
    char address[100];
    char experience[1000];
    char education[500];
} Resume;

void parseResume(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("The file %s does not exist.\n", filename);
        return;
    }

    Resume newResume;

    char line[100];
    char* token;

    while (fgets(line, 100, file) != NULL) {
        token = strtok(line, ":");

        if (strcmp(token, "First Name") == 0) {
            token = strtok(NULL, "\n");
            strcpy(newResume.firstName, token);
        }
        else if (strcmp(token, "Last Name") == 0) {
            token = strtok(NULL, "\n");
            strcpy(newResume.lastName, token);
        }
        else if (strcmp(token, "Email") == 0) {
            token = strtok(NULL, "\n");
            strcpy(newResume.email, token);
        }
        else if (strcmp(token, "Phone") == 0) {
            token = strtok(NULL, "\n");
            strcpy(newResume.phone, token);
        }
        else if (strcmp(token, "Address") == 0) {
            token = strtok(NULL, "\n");
            strcpy(newResume.address, token);
        }
        else if (strcmp(token, "Experience") == 0) {
            token = strtok(NULL, "\n");
            strcpy(newResume.experience, token);
        }
        else if (strcmp(token, "Education") == 0) {
            token = strtok(NULL, "\n");
            strcpy(newResume.education, token);
        }
    }

    fclose(file);

    printf("First Name: %s\n", newResume.firstName);
    printf("Last Name: %s\n", newResume.lastName);
    printf("Email: %s\n", newResume.email);
    printf("Phone: %s\n", newResume.phone);
    printf("Address: %s\n", newResume.address);
    printf("Experience: %s\n", newResume.experience);
    printf("Education: %s\n", newResume.education);
}

int main() {
    char* filename = "resume.txt";
    parseResume(filename);

    return 0;
}