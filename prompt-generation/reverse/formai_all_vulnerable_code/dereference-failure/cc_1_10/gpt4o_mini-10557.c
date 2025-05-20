//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_SKILLS 10
#define SKILL_BUFFER 50

typedef struct {
    char name[100];
    char email[100];
    char phone[20];
    char skills[MAX_SKILLS][SKILL_BUFFER];
    int skill_count;
} Resume;

// Function declarations
void parseResume(FILE *file, Resume *resume);
void printResume(const Resume *resume);
void trimWhitespace(char *str);
int isCompleteResume(const Resume *resume);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Thank you for using the Resume Parsing System!\n");
        printf("Please provide the resume file as an argument.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    Resume resume = { .skill_count = 0 };
    parseResume(file, &resume);
    fclose(file);

    if (isCompleteResume(&resume)) {
        printResume(&resume);
    } else {
        printf("The resume appears to be incomplete. Please ensure that it includes a name, email, and phone number.\n");
    }

    return 0;
}

void parseResume(FILE *file, Resume *resume) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        trimWhitespace(line);
        if (strncmp(line, "Name:", 5) == 0) {
            strncpy(resume->name, line + 5, sizeof(resume->name) - 1);
        } else if (strncmp(line, "Email:", 6) == 0) {
            strncpy(resume->email, line + 6, sizeof(resume->email) - 1);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            strncpy(resume->phone, line + 6, sizeof(resume->phone) - 1);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            char *skill = strtok(line + 7, ",");
            while (skill != NULL && resume->skill_count < MAX_SKILLS) {
                trimWhitespace(skill);
                strncpy(resume->skills[resume->skill_count++], skill, SKILL_BUFFER - 1);
                skill = strtok(NULL, ",");
            }
        }
    }
}

void printResume(const Resume *resume) {
    printf("=== Parsed Resume ===\n");
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills:\n");
    for (int i = 0; i < resume->skill_count; i++) {
        printf("  - %s\n", resume->skills[i]);
    }
    printf("======================\n");
    printf("Thank you for using the Resume Parsing System!\n");
}

void trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate
    *(end + 1) = '\0';
}

int isCompleteResume(const Resume *resume) {
    return strlen(resume->name) > 0 && strlen(resume->email) > 0 && strlen(resume->phone) > 0;
}