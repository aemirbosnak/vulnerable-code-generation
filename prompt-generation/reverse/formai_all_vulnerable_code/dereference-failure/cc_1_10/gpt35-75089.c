//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length for various fields in the resume
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_SKILLS_LENGTH 200

// Define a struct to hold the parsed information from the resume
typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
} Resume;

// Define a function to convert a string to lower case
void to_lower_case(char *string) {
    for (int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }
}

// Define a function to parse a name from the resume
char *parse_name(char *resume_text) {
    char *name = (char *) malloc(MAX_NAME_LENGTH * sizeof(char));
    int i = 0, j = 0;

    while (resume_text[i] != '\n' && resume_text[i + 1] != '\n') {
        if (isalpha(resume_text[i]) || resume_text[i] == ' ') {
            name[j++] = resume_text[i++];
        } else {
            i++;
        }
    }

    to_lower_case(name);

    return name;
}

// Define a function to parse an email from the resume
char *parse_email(char *resume_text) {
    char *email = (char *) malloc(MAX_EMAIL_LENGTH * sizeof(char));
    int i = 0, j = 0;

    while (resume_text[i] != '\n' && resume_text[i + 1] != '\n' && resume_text[i] != '<') {
        i++;
    }

    i++;

    while (resume_text[i] != '>' && j < MAX_EMAIL_LENGTH) {
        email[j++] = resume_text[i++];
    }

    to_lower_case(email);

    return email;
}

// Define a function to parse a phone number from the resume
char *parse_phone(char *resume_text) {
    char *phone = (char *) malloc(MAX_PHONE_LENGTH * sizeof(char));
    int i = 0, j = 0;

    while (resume_text[i] != '\n' && resume_text[i + 1] != '\n') {
        if (resume_text[i] == '(' || resume_text[i] == ')' || isdigit(resume_text[i])) {
            phone[j++] = resume_text[i];
        }
        i++;
    }

    return phone;
}

// Define a function to parse skills from the resume
char *parse_skills(char *resume_text) {
    char *skills = (char *) malloc(MAX_SKILLS_LENGTH * sizeof(char));
    int i = 0, j = 0;

    while (resume_text[i] != '\n' && resume_text[i + 1] != '\n') {
        i++;
    }

    i += 2;

    while (resume_text[i]) {
        if (isalpha(resume_text[i]) || resume_text[i] == ' ') {
            skills[j++] = resume_text[i];
        } else if (resume_text[i] == ',') {
            skills[j++] = ',';
            skills[j++] = ' ';
        }
        i++;
    }

    to_lower_case(skills);

    return skills;
}

// Define the main function
int main() {
    char resume_text[] = "John Doe\n123 Main Street\nAnytown, USA 12345\n(555) 555-5555\njohndoe@example.com\n\nSKILLS:\n C programming, Python, HTML, CSS, JavaScript";

    Resume resume;

    strcpy(resume.name, parse_name(resume_text));
    strcpy(resume.email, parse_email(resume_text));
    strcpy(resume.phone, parse_phone(resume_text));
    strcpy(resume.skills, parse_skills(resume_text));

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: %s\n", resume.skills);

    return 0;
}