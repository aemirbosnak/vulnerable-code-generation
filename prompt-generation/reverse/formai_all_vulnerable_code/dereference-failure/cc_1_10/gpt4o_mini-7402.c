//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_SKILLS 10
#define MAX_SKILL_LENGTH 30

typedef struct {
    char name[100];
    char email[50];
    char phone[20];
    char skills[MAX_SKILLS][MAX_SKILL_LENGTH];
    int skill_count;
} Resume;

// Function to trim whitespace from the start and end of a string
char* trim_whitespace(char* str) {
    char* end;

    while (isspace((unsigned char)*str)) str++;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    return str;
}

// Function to parse the resume text
void parse_resume(const char* filename, Resume* resume) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    resume->skill_count = 0;

    while (fgets(line, sizeof(line), file)) {
        // Trim the line to remove unnecessary whitespaces
        char* trimmed_line = trim_whitespace(line);

        if (strncmp(trimmed_line, "Name:", 5) == 0) {
            strcpy(resume->name, trimmed_line + 5);
        } else if (strncmp(trimmed_line, "Email:", 6) == 0) {
            strcpy(resume->email, trimmed_line + 6);
        } else if (strncmp(trimmed_line, "Phone:", 6) == 0) {
            strcpy(resume->phone, trimmed_line + 6);
        } else if (strncmp(trimmed_line, "Skills:", 7) == 0) {
            char* skill = strtok(trimmed_line + 7, ",");
            while (skill != NULL && resume->skill_count < MAX_SKILLS) {
                strcpy(resume->skills[resume->skill_count++], trim_whitespace(skill));
                skill = strtok(NULL, ",");
            }
        }
    }

    fclose(file);
}

// Function to display the parsed resume information
void display_resume(const Resume* resume) {
    printf("Parsed Resume Information:\n");
    printf("Name: %s", resume->name);
    printf("Email: %s", resume->email);
    printf("Phone: %s", resume->phone);
    printf("Skills:\n");
    for (int i = 0; i < resume->skill_count; i++) {
        printf("  - %s\n", resume->skills[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume_file>\n", argv[0]);
        return 1;
    }

    Resume resume;
    parse_resume(argv[1], &resume);
    display_resume(&resume);

    return 0;
}