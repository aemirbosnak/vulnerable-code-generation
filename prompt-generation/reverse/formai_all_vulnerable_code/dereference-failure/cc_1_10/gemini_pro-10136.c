//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_SKILLS 10

typedef struct {
    char name[100];
    char email[100];
    char phone[100];
    char skills[MAX_SKILLS][100];
    int num_skills;
} resume;

int main() {
    // Read resumes from file
    FILE *fp = fopen("resumes.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    resume resumes[MAX_RESUMES];
    int num_resumes = 0;

    char line[1000];
    while (fgets(line, sizeof(line), fp)) {
        // Parse resume
        char *name = strtok(line, ",");
        char *email = strtok(NULL, ",");
        char *phone = strtok(NULL, ",");

        resume resume;
        strcpy(resume.name, name);
        strcpy(resume.email, email);
        strcpy(resume.phone, phone);

        int num_skills = 0;
        char *skill = strtok(NULL, ",");
        while (skill != NULL) {
            strcpy(resume.skills[num_skills], skill);
            num_skills++;
            skill = strtok(NULL, ",");
        }

        resume.num_skills = num_skills;

        // Add resume to array
        resumes[num_resumes] = resume;
        num_resumes++;
    }

    fclose(fp);

    // Search resumes for skills
    char skill_to_search_for[100];
    printf("Enter skill to search for: ");
    scanf("%s", skill_to_search_for);

    for (int i = 0; i < num_resumes; i++) {
        int found = 0;
        for (int j = 0; j < resumes[i].num_skills; j++) {
            if (strcmp(resumes[i].skills[j], skill_to_search_for) == 0) {
                found = 1;
                break;
            }
        }

        if (found) {
            printf("Found resume for %s with skill %s\n", resumes[i].name, skill_to_search_for);
        }
    }

    return EXIT_SUCCESS;
}