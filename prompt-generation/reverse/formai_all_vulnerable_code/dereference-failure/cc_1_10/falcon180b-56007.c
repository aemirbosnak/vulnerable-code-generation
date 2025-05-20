//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Parsing function prototypes
int parse_name(char *line, char *name);
int parse_contact(char *line, char *contact);
int parse_education(char *line, char *education);
int parse_experience(char *line, char *experience);

// Structs for holding data
typedef struct {
    char name[MAX_LINE_SIZE];
    char contact[MAX_LINE_SIZE];
    char education[MAX_LINE_SIZE];
    char experience[MAX_LINE_SIZE];
} Resume;

int main() {
    char line[MAX_LINE_SIZE];
    Resume resume;

    printf("Enter your name:\n");
    fgets(line, MAX_LINE_SIZE, stdin);
    parse_name(line, resume.name);

    printf("Enter your contact information:\n");
    fgets(line, MAX_LINE_SIZE, stdin);
    parse_contact(line, resume.contact);

    printf("Enter your education:\n");
    fgets(line, MAX_LINE_SIZE, stdin);
    parse_education(line, resume.education);

    printf("Enter your work experience:\n");
    fgets(line, MAX_LINE_SIZE, stdin);
    parse_experience(line, resume.experience);

    printf("Name: %s\n", resume.name);
    printf("Contact: %s\n", resume.contact);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}

int parse_name(char *line, char *name) {
    char *token = strtok(line, " ");
    strcpy(name, token);
    return 1;
}

int parse_contact(char *line, char *contact) {
    char *token = strtok(line, " ");
    strcpy(contact, token);
    return 1;
}

int parse_education(char *line, char *education) {
    char *token = strtok(line, " ");
    strcpy(education, token);
    return 1;
}

int parse_experience(char *line, char *experience) {
    char *token = strtok(line, " ");
    strcpy(experience, token);
    return 1;
}