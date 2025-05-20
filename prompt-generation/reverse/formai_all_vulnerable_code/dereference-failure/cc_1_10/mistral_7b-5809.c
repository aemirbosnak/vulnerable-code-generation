//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char name[100];
    char address[200];
    char phone[20];
    char email[50];
} Candidate;

void extract_info(char *line, Candidate *candidate) {
    char *token;
    int state = 0;

    token = strtok(line, ":\n ");
    if (token && strcmp(token, "Name") == 0) {
        state = 1;
        token = strtok(NULL, ",\n");
        strcpy(candidate->name, token);
    }

    if (strcmp(token, "Address") == 0) {
        state = 2;
        token = strtok(NULL, ",\n");
        strcpy(candidate->address, token);
    }

    if (strcmp(token, "Phone") == 0) {
        state = 3;
        token = strtok(NULL, ",\n");
        strcpy(candidate->phone, token);
    }

    if (strcmp(token, "Email") == 0) {
        state = 4;
        token = strtok(NULL, "\n");
        strcpy(candidate->email, token);
    }

    if (state == 4) {
        printf("Found candidate:\n");
        printf("Name: %s\n", candidate->name);
        printf("Address: %s\n", candidate->address);
        printf("Phone: %s\n", candidate->phone);
        printf("Email: %s\n", candidate->email);
        exit(0);
    }
}

int main() {
    char line[500];
    char resume[10000];
    int len = 0;
    FILE *fp;
    Candidate candidate;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        extract_info(line, &candidate);
        memset(line, 0, sizeof(line));
    }

    fclose(fp);

    printf("No candidate found.\n");
    return 0;
}