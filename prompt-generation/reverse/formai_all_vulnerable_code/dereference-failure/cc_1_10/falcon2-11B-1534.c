//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char *name;
    char *email;
    char *phone_number;
    char *location;
    char *skills;
};

struct Candidate* parseResume(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return NULL;
    }

    struct Candidate *candidate = NULL;
    char line[1000];

    while (fgets(line, sizeof(line), file)) {
        char *token;
        char *next_token;
        char *tmp;

        token = strtok(line, " \t\n");
        if (strcmp(token, "Name:") == 0) {
            candidate->name = strdup(strtok(NULL, " \t\n"));
        } else if (strcmp(token, "Email:") == 0) {
            candidate->email = strdup(strtok(NULL, " \t\n"));
        } else if (strcmp(token, "Phone:") == 0) {
            candidate->phone_number = strdup(strtok(NULL, " \t\n"));
        } else if (strcmp(token, "Location:") == 0) {
            candidate->location = strdup(strtok(NULL, " \t\n"));
        } else if (strcmp(token, "Skills:") == 0) {
            candidate->skills = strdup(strtok(NULL, " \t\n"));
        } else {
            next_token = strtok(NULL, " \t\n");
            while (next_token!= NULL) {
                if (strcmp(next_token, "Phone:") == 0) {
                    candidate->phone_number = strdup(strtok(NULL, " \t\n"));
                } else if (strcmp(next_token, "Location:") == 0) {
                    candidate->location = strdup(strtok(NULL, " \t\n"));
                } else {
                    tmp = strdup(strtok(NULL, " \t\n"));
                    if (strcmp(tmp, "Skills:") == 0) {
                        candidate->skills = strdup(strtok(NULL, " \t\n"));
                    } else {
                        strcat(candidate->skills, " ");
                        strcat(candidate->skills, tmp);
                    }
                }
                next_token = strtok(NULL, " \t\n");
            }
        }
    }

    return candidate;
}

int main() {
    struct Candidate *candidate = parseResume("resume.txt");
    if (candidate!= NULL) {
        printf("Name: %s\n", candidate->name);
        printf("Email: %s\n", candidate->email);
        printf("Phone Number: %s\n", candidate->phone_number);
        printf("Location: %s\n", candidate->location);
        printf("Skills: %s\n", candidate->skills);
    } else {
        printf("Error parsing resume\n");
    }
    return 0;
}