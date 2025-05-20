//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    char *email;
    char *phone;
    char *skills[10];
    int skillsCount;
} Resume;

int main() {
    // Create a resume
    Resume resume = {
        .name = "John Doe",
        .email = "john.doe@example.com",
        .phone = "123-456-7890",
        .skills = {"C", "C++", "Java", "Python", "SQL"},
        .skillsCount = 5
    };

    // Print the resume
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);

    printf("Skills:\n");
    for (int i = 0; i < resume.skillsCount; i++) {
        printf("- %s\n", resume.skills[i]);
    }

    // Parse the resume
    char *resumeText = "John Doe\njohn.doe@example.com\n123-456-7890\nC, C++, Java, Python, SQL";

    // Tokenize the resume text
    char *tokens[10];
    int tokenCount = 0;

    char *token = strtok(resumeText, "\n");
    while (token != NULL) {
        tokens[tokenCount++] = token;
        token = strtok(NULL, "\n");
    }

    // Parse the tokens
    resume.name = tokens[0];
    resume.email = tokens[1];
    resume.phone = tokens[2];

    resume.skillsCount = 0;
    for (int i = 3; i < tokenCount; i++) {
        resume.skills[resume.skillsCount++] = tokens[i];
    }

    // Print the parsed resume
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);

    printf("Skills:\n");
    for (int i = 0; i < resume.skillsCount; i++) {
        printf("- %s\n", resume.skills[i]);
    }

    return 0;
}