//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define MAX_SKILLS 10
#define MAX_SKILL_LENGTH 50

typedef struct {
    char name[BUFFER_SIZE];
    char email[BUFFER_SIZE];
    char phone[BUFFER_SIZE];
    char skills[MAX_SKILLS][MAX_SKILL_LENGTH];
    int skill_count;
} Resume;

// Function prototypes
void parse_resume(const char *filename, Resume *resume);
void extract_info(char *line, Resume *resume);
void print_resume(const Resume *resume);
void trim_whitespace(char *str);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Resume resume;
    memset(&resume, 0, sizeof(Resume));
    parse_resume(argv[1], &resume);
    print_resume(&resume);

    return EXIT_SUCCESS;
}

void parse_resume(const char *filename, Resume *resume) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), file)) {
        trim_whitespace(line);
        extract_info(line, resume);
    }

    fclose(file);
}

void extract_info(char *line, Resume *resume) {
    if (strncmp(line, "Name: ", 6) == 0) {
        strcpy(resume->name, line + 6);
    } else if (strncmp(line, "Email: ", 7) == 0) {
        strcpy(resume->email, line + 7);
    } else if (strncmp(line, "Phone: ", 7) == 0) {
        strcpy(resume->phone, line + 7);
    } else if (strncmp(line, "Skills: ", 8) == 0) {
        char *token = strtok(line + 8, ",");
        while (token != NULL && resume->skill_count < MAX_SKILLS) {
            trim_whitespace(token);
            strcpy(resume->skills[resume->skill_count++], token);
            token = strtok(NULL, ",");
        }
    }
}

void print_resume(const Resume *resume) {
    printf("Resume Information:\n");
    printf("Name: %s", resume->name);
    printf("Email: %s", resume->email);
    printf("Phone: %s", resume->phone);
    printf("Skills: ");
    for (int i = 0; i < resume->skill_count; i++) {
        printf("%s", resume->skills[i]);
        if (i < resume->skill_count - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

void trim_whitespace(char *str) {
    char *end;

    // Trim leading whitespace
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing whitespace
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate the string
    end[1] = '\0';
}