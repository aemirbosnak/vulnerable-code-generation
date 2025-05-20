//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char skills[200];
};

void parseResume(struct Resume *r, char *input) {
    char delimiter[] = " \t\n";
    char *token;
    char *remainingText;

    // Extract name
    token = strtok_r(input, delimiter, &remainingText);
    strcpy(r->name, token);

    // Extract email
    token = strtok_r(NULL, delimiter, &remainingText);
    strcpy(r->email, token);

    // Extract phone
    token = strtok_r(NULL, delimiter, &remainingText);
    strcpy(r->phone, token);

    // Extract education
    token = strtok_r(NULL, delimiter, &remainingText);
    strcpy(r->education, token);

    // Extract skills
    strcpy(r->skills, "");
    while ((token = strtok_r(NULL, delimiter, &remainingText)) != NULL) {
        strcat(r->skills, token);
        strcat(r->skills, " ");
    }
}

int main() {
    char input[] = "John Doe john.doe@example.com (555)555-5555 B.S. Computer Science C++ Java Python";
    struct Resume r;

    parseResume(&r, input);

    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Education: %s\n", r.education);
    printf("Skills: %s\n", r.skills);

    return 0;
}