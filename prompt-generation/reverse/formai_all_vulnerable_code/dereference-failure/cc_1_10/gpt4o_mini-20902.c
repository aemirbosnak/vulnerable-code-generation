//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define NAME_FIELD "Name:"
#define EMAIL_FIELD "Email:"
#define SKILLS_FIELD "Skills:"

// Struct to hold parsed resume data
typedef struct {
    char *name;
    char *email;
    char **skills;
    int skill_count;
} Resume;

// Function prototypes
Resume* parse_resume(const char *filename);
void free_resume(Resume *resume);
void print_resume(Resume *resume);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    Resume *resume = parse_resume(argv[1]);
    if (resume) {
        print_resume(resume);
        free_resume(resume);
    } else {
        printf("Error parsing resume from file: %s\n", argv[1]);
    }

    return EXIT_SUCCESS;
}

Resume* parse_resume(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return NULL;
    }

    Resume *resume = malloc(sizeof(Resume));
    resume->name = NULL;
    resume->email = NULL;
    resume->skills = NULL;
    resume->skill_count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, NAME_FIELD, strlen(NAME_FIELD)) == 0) {
            resume->name = strdup(line + strlen(NAME_FIELD));
            resume->name[strcspn(resume->name, "\n")] = 0; // Remove newline
        } else if (strncmp(line, EMAIL_FIELD, strlen(EMAIL_FIELD)) == 0) {
            resume->email = strdup(line + strlen(EMAIL_FIELD));
            resume->email[strcspn(resume->email, "\n")] = 0; // Remove newline
        } else if (strncmp(line, SKILLS_FIELD, strlen(SKILLS_FIELD)) == 0) {
            char *skills_str = strdup(line + strlen(SKILLS_FIELD));
            skills_str[strcspn(skills_str, "\n")] = 0; // Remove newline
            
            char *token = strtok(skills_str, ", ");
            while (token != NULL) {
                resume->skills = realloc(resume->skills, sizeof(char*) * (resume->skill_count + 1));
                resume->skills[resume->skill_count] = strdup(token);
                resume->skill_count++;
                token = strtok(NULL, ", ");
            }
            free(skills_str);
        }
    }

    fclose(file);
    return resume;
}

void free_resume(Resume *resume) {
    if (resume->name) free(resume->name);
    if (resume->email) free(resume->email);
    for (int i = 0; i < resume->skill_count; i++) {
        free(resume->skills[i]);
    }
    free(resume->skills);
    free(resume);
}

void print_resume(Resume *resume) {
    printf("Parsed Resume:\n");
    if (resume->name) {
        printf("Name: %s\n", resume->name);
    } else {
        printf("Name: Not provided.\n");
    }
    
    if (resume->email) {
        printf("Email: %s\n", resume->email);
    } else {
        printf("Email: Not provided.\n");
    }
    
    printf("Skills: ");
    if (resume->skill_count > 0) {
        for (int i = 0; i < resume->skill_count; i++) {
            printf("%s", resume->skills[i]);
            if (i < resume->skill_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        printf("Not provided.\n");
    }
}