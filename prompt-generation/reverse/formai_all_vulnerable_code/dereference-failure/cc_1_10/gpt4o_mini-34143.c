//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_SKILLS 10
#define MAX_SKILL_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char skills[MAX_SKILLS][MAX_SKILL_NAME_LENGTH];
    int skill_count;
} Resume;

Resume parsed_resumes[MAX_RESUMES];
int resume_count = 0;

void parse_line(const char *line) {
    Resume new_resume;
    strcpy(new_resume.name, strtok((char *)line, ","));
    strcpy(new_resume.email, strtok(NULL, ","));
    strcpy(new_resume.phone, strtok(NULL, ","));
    
    char *skill;
    int skill_idx = 0;

    while ((skill = strtok(NULL, ",")) != NULL && skill_idx < MAX_SKILLS) {
        strcpy(new_resume.skills[skill_idx++], skill);
    }
    new_resume.skill_count = skill_idx;

    parsed_resumes[resume_count++] = new_resume;
}

void display_resumes() {
    for (int i = 0; i < resume_count; i++) {
        printf("Resume %d:\n", i + 1);
        printf("Name: %s\n", parsed_resumes[i].name);
        printf("Email: %s\n", parsed_resumes[i].email);
        printf("Phone: %s\n", parsed_resumes[i].phone);
        printf("Skills: ");
        for (int j = 0; j < parsed_resumes[i].skill_count; j++) {
            printf("%s", parsed_resumes[i].skills[j]);
            if (j < parsed_resumes[i].skill_count - 1) {
                printf(", ");
            }
        }
        printf("\n\n");
    }
}

void load_resumes_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading\n", filename);
        exit(EXIT_FAILURE);
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Strip newline character at the end
        line[strcspn(line, "\n")] = 0;
        parse_line(line);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <resume_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    load_resumes_from_file(argv[1]);
    display_resumes();

    return EXIT_SUCCESS;
}