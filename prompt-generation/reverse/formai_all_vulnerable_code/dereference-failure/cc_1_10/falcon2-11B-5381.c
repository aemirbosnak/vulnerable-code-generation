//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <string.h>

struct resume {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    char skills[50];
};

void parse_resume(struct resume *resume) {
    char line[100];
    char *token;
    int i = 0;

    while (fgets(line, sizeof(line), stdin)) {
        token = strtok(line, " \t");
        if (strcmp(token, "Name:") == 0) {
            strcpy(resume->name, token + 6);
            token = strtok(NULL, " \t");
        } else if (strcmp(token, "Address:") == 0) {
            strcpy(resume->address, token + 8);
            token = strtok(NULL, " \t");
        } else if (strcmp(token, "Phone:") == 0) {
            strcpy(resume->phone, token + 6);
            token = strtok(NULL, " \t");
        } else if (strcmp(token, "Email:") == 0) {
            strcpy(resume->email, token + 6);
            token = strtok(NULL, " \t");
        } else if (strcmp(token, "Skills:") == 0) {
            strcpy(resume->skills, token + 7);
            token = strtok(NULL, " \t");
        } else {
            printf("Invalid token: %s\n", token);
        }
    }
}

int main() {
    struct resume resume;
    parse_resume(&resume);

    printf("Name: %s\n", resume.name);
    printf("Address: %s\n", resume.address);
    printf("Phone: %s\n", resume.phone);
    printf("Email: %s\n", resume.email);
    printf("Skills: %s\n", resume.skills);

    return 0;
}