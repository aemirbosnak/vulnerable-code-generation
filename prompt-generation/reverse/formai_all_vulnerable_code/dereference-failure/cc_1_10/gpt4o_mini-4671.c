//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_NAME_LENGTH 50
#define MAX_SKILLS 10
#define MAX_SKILL_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int years_of_experience;
    char skills[MAX_SKILLS][MAX_SKILL_LENGTH];
    int skill_count;
} Resume;

void parseResume(char *line, Resume *resume) {
    char *token;

    // Extract name - First token
    token = strtok(line, ",");
    strcpy(resume->name, token);

    // Extract years of experience - second token
    token = strtok(NULL, ",");
    resume->years_of_experience = atoi(token);

    // Extract skills - remaining tokens
    resume->skill_count = 0;
    while ((token = strtok(NULL, ",")) != NULL) {
        strcpy(resume->skills[resume->skill_count++], token);
    }
}

void printResume(const Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Experience: %d years\n", resume->years_of_experience);
    printf("Skills: ");
    for (int i = 0; i < resume->skill_count; i++) {
        printf("%s", resume->skills[i]);
        if (i < resume->skill_count - 1) {
            printf(", ");
        }
    }
    printf("\n\n");
}

void calculateStatistics(Resume resumes[], int count) {
    int totalExperience = 0;
    int totalSkills = 0;

    for (int i = 0; i < count; i++) {
        totalExperience += resumes[i].years_of_experience;
        totalSkills += resumes[i].skill_count;
    }

    printf("Total number of resumes: %d\n", count);
    printf("Total years of experience: %d\n", totalExperience);
    printf("Average years of experience: %.2f\n", (count > 0) ? (float)totalExperience / count : 0);
    printf("Total number of skills listed: %d\n", totalSkills);
    printf("Average skills per resume: %.2f\n", (count > 0) ? (float)totalSkills / count : 0);
}

int main() {
    Resume resumes[MAX_RESUMES];
    char line[256];
    int resume_count = 0;

    FILE *file = fopen("resumes.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open resumes.txt\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file) && resume_count < MAX_RESUMES) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        parseResume(line, &resumes[resume_count++]);
    }

    fclose(file);

    // Print all resumes
    printf("Parsed Resumes:\n\n");
    for (int i = 0; i < resume_count; i++) {
        printResume(&resumes[i]);
    }

    // Calculate statistics
    calculateStatistics(resumes, resume_count);

    return 0;
}