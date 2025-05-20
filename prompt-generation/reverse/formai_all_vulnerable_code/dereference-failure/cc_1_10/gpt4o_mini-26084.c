//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_RESUMES 100
#define BUFFER_SIZE 1024
#define MAX_SKILLS 10

typedef struct {
    char name[100];
    char contact[100];
    char skills[MAX_SKILLS][50];
    int skill_count;
} Resume;

const char* const SKILL_KEYWORD = "Skills:";

void parse_resume(const char* filename, Resume* resume);
void extract_skills(const char* line, Resume* resume);
void display_resume(const Resume* resume);
void list_resumes(const char* directory);

int main() {
    const char* directory_path = "./resumes"; // Directory containing resumes
    list_resumes(directory_path);
    return 0;
}

void list_resumes(const char* directory) {
    struct dirent* entry;
    DIR* dp = opendir(directory);
    if (dp == NULL) {
        perror("opendir");
        return;
    }

    Resume resumes[MAX_RESUMES];
    int resume_count = 0;

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if it's a regular file
            char filepath[BUFFER_SIZE];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            parse_resume(filepath, &resumes[resume_count]);
            resume_count++;
            
            if (resume_count >= MAX_RESUMES) {
                break;
            }
        }
    }
    closedir(dp);

    for (int i = 0; i < resume_count; i++) {
        printf("\n--- Resume %d ---\n", i + 1);
        display_resume(&resumes[i]);
    }
}

void parse_resume(const char* filename, Resume* resume) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    char line[BUFFER_SIZE];
    resume->skill_count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line + 5, "%[^\n]", resume->name);
        } else if (strncmp(line, "Contact:", 8) == 0) {
            sscanf(line + 8, "%[^\n]", resume->contact);
        } else if (strncmp(line, SKILL_KEYWORD, strlen(SKILL_KEYWORD)) == 0) {
            extract_skills(line + strlen(SKILL_KEYWORD), resume);
        }
    }
    fclose(file);
}

void extract_skills(const char* line, Resume* resume) {
    const char* token = strtok((char*)line, ",");
    while (token != NULL && resume->skill_count < MAX_SKILLS) {
        sscanf(token, "%[^\n]", resume->skills[resume->skill_count++]);
        token = strtok(NULL, ",");
    }
}

void display_resume(const Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Contact: %s\n", resume->contact);
    printf("Skills: ");
    for (int i = 0; i < resume->skill_count; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%s", resume->skills[i]);
    }
    printf("\n");
}