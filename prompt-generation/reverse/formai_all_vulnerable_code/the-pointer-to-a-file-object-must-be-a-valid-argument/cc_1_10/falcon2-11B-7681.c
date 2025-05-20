//Falcon2-11B DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char address[100];
    char summary[1000];
    char experience[1000];
    char education[1000];
};

void parseResume(char* fileName) {
    FILE* file = fopen(fileName, "r");
    struct Resume resume;
    char line[1000];

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name:") == line) {
            strcpy(resume.name, &line[7]);
        } else if (strstr(line, "Email:") == line) {
            strcpy(resume.email, &line[8]);
        } else if (strstr(line, "Phone:") == line) {
            strcpy(resume.phone, &line[8]);
        } else if (strstr(line, "Address:") == line) {
            strcpy(resume.address, &line[9]);
        } else if (strstr(line, "Summary:") == line) {
            strcpy(resume.summary, &line[9]);
        } else if (strstr(line, "Experience:") == line) {
            strcpy(resume.experience, &line[11]);
        } else if (strstr(line, "Education:") == line) {
            strcpy(resume.education, &line[10]);
        }
    }

    printf("Parsed Resume:\n");
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Summary: %s\n", resume.summary);
    printf("Experience: %s\n", resume.experience);
    printf("Education: %s\n", resume.education);

    fclose(file);
}

int main() {
    char fileName[100];
    printf("Enter the name of the resume file: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = '\0';

    struct Resume resume;
    parseResume(fileName);

    return 0;
}