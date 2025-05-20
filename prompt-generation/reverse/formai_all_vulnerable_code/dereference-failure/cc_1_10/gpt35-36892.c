//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_LENGTH 1000

struct resume {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone_no[MAX_LENGTH];
    char education[MAX_LENGTH];
    char experience[MAX_LENGTH]; 
};

int main() {
    // Array to hold resumes
    struct resume resumes[MAX_RESUMES];

    // Read resumes from a file
    FILE *fp;
    fp = fopen("resumes.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char resume_buffer[MAX_LENGTH];
    int i = 0;

    // Read up to MAX_RESUMES resumes or until end of file
    while (fgets(resume_buffer, MAX_LENGTH, fp) != NULL && i < MAX_RESUMES) {
        // Parse resume information
        char *token;
        token = strtok(resume_buffer, ",");
        strcpy(resumes[i].name, token);
        token = strtok(NULL, ",");
        strcpy(resumes[i].email, token);
        token = strtok(NULL, ",");
        strcpy(resumes[i].phone_no, token);
        token = strtok(NULL, ",");
        strcpy(resumes[i].education, token);
        token = strtok(NULL, ",");
        strcpy(resumes[i].experience, token);

        i++;
    }

    fclose(fp);

    // Search for resumes with specific education and experience keywords
    char education_keyword[MAX_LENGTH];
    printf("Enter desired education (e.g. 'Bachelor of Science in Computer Science'): ");
    fgets(education_keyword, MAX_LENGTH, stdin);
    education_keyword[strcspn(education_keyword, "\n")] = 0; // Remove newline character

    char experience_keyword[MAX_LENGTH];
    printf("Enter desired experience (e.g. '2 years of software development'): ");
    fgets(experience_keyword, MAX_LENGTH, stdin);
    experience_keyword[strcspn(experience_keyword, "\n")] = 0; // Remove newline character

    printf("\nResumes matching your criteria:\n");

    for (int j = 0; j < i; j++) {
        if (strstr(resumes[j].education, education_keyword) && strstr(resumes[j].experience, experience_keyword)) {
            printf("%s\n", resumes[j].name);
            printf("Email: %s\n", resumes[j].email);
            printf("Phone No: %s\n", resumes[j].phone_no);
            printf("Education: %s\n", resumes[j].education);
            printf("Experience: %s\n\n", resumes[j].experience);
        }
    }

    return 0;
}