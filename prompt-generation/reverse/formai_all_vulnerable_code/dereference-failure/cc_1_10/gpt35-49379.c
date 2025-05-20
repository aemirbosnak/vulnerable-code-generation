//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define resume struct
typedef struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char workExp[100];
} Resume;

// Function to parse resume and fill the struct
void parseResume(char *resumeInfo, Resume *resume) {
    char *token;
    char *delim = ",\n";
    int count = 0;
    while ((token = strtok_r(resumeInfo, delim, &resumeInfo))) {
        switch (count) {
            case 0:
                strcpy(resume->name, token);
                break;
            case 1:
                strcpy(resume->email, token);
                break;
            case 2:
                strcpy(resume->phone, token);
                break;
            case 3:
                strcpy(resume->education, token);
                break;
            case 4:
                strcpy(resume->workExp, token);
                break;
            default:
                break;
        }
        count++;
    }
}

int main() {
    // Input Resume Information
    char resumeInfo[500] = "John Doe,johndoe@email.com,123-456-7890,Bachelor's Degree in Computer Science,3 years of experience in software development";
    Resume resume;
    parseResume(resumeInfo, &resume);

    // Output Resume Struct Information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Work Experience: %s\n", resume.workExp);

    return 0;
}