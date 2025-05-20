//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_SKILLS 10
#define MAX_SKILL_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char skills[MAX_SKILLS][MAX_SKILL_LENGTH];
    int skill_count;
} Resume;

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (*str == ' ') str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && *end == ' ') end--;
    *(end + 1) = '\0';
}

void parse_resume(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open the resume file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    resume->skill_count = 0;

    while (fgets(line, sizeof(line), file)) {
        trim_whitespace(line);
        
        if (strncmp(line, "Name:", 5) == 0) {
            strcpy(resume->name, line + 5);
        } else if (strncmp(line, "Email:", 6) == 0) {
            strcpy(resume->email, line + 6);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            char *skill_token = strtok(line + 7, ",");

            while (skill_token && resume->skill_count < MAX_SKILLS) {
                trim_whitespace(skill_token);
                strcpy(resume->skills[resume->skill_count++], skill_token);
                skill_token = strtok(NULL, ",");
            }
        }
    }

    fclose(file);
}

void display_resume(const Resume *resume) {
    printf("==== Resume Details ====\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Skills:\n");
    
    for (int i = 0; i < resume->skill_count; i++) {
        printf("  - %s\n", resume->skills[i]);
    }
    printf("========================\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Resume resume;
    parse_resume(argv[1], &resume);
    display_resume(&resume);

    return EXIT_SUCCESS;
}