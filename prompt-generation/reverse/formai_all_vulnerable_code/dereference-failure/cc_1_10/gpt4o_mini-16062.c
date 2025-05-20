//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_SKILLS 10
#define MAX_SKILL_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char skills[MAX_SKILLS][MAX_SKILL_LENGTH];
    int skill_count;
} Resume;

void init_resume(Resume *resume) {
    strcpy(resume->name, "");
    strcpy(resume->email, "");
    strcpy(resume->phone, "");
    resume->skill_count = 0;
}

void print_resume(const Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: ");
    for (int i = 0; i < resume->skill_count; i++) {
        printf("%s", resume->skills[i]);
        if (i < resume->skill_count - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int parse_resume_file(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return -1; // Error opening file
    }
    
    char line[256];
    
    // Parse Name
    if (fgets(line, sizeof(line), file)) {
        strtok(line, "\n"); // Remove newline
        strcpy(resume->name, line);
    }

    // Parse Email
    if (fgets(line, sizeof(line), file)) {
        strtok(line, "\n");
        strcpy(resume->email, line);
    }

    // Parse Phone
    if (fgets(line, sizeof(line), file)) {
        strtok(line, "\n");
        strcpy(resume->phone, line);
    }

    // Parse Skills
    while (fgets(line, sizeof(line), file) && resume->skill_count < MAX_SKILLS) {
        strtok(line, "\n");
        strcpy(resume->skills[resume->skill_count], line);
        resume->skill_count++;
    }
    
    fclose(file);
    return 0; // Success
}

void print_all_resumes(Resume resumes[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\nResume %d:\n", i + 1);
        print_resume(&resumes[i]);
    }
}

int main() {
    Resume resumes[MAX_RESUMES];
    int resume_count = 0;

    // Simulate adding resumes
    char *resume_files[] = {"resume1.txt", "resume2.txt", "resume3.txt"};
    int num_files = sizeof(resume_files) / sizeof(resume_files[0]);

    for (int i = 0; i < num_files; i++) {
        if (parse_resume_file(resume_files[i], &resumes[resume_count]) == 0) {
            resume_count++;
            if (resume_count >= MAX_RESUMES) {
                printf("Maximum number of resumes reached.\n");
                break;
            }
        } else {
            printf("Error processing file: %s\n", resume_files[i]);
        }
    }

    print_all_resumes(resumes, resume_count);
    return 0;
}