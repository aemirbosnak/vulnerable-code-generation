//GPT-4o-mini DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024
#define MAX_SKILLS 10
#define MAX_RESUMES 50

typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char skills[MAX_SKILLS][MAX_LENGTH];
    int skill_count;
} Resume;

void to_lowercase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int parse_skills(char *skills_str, char skills[MAX_SKILLS][MAX_LENGTH]) {
    char *token;
    int count = 0;
    
    token = strtok(skills_str, ",");
    while(token != NULL && count < MAX_SKILLS) {
        strcpy(skills[count], token);
        count++;
        token = strtok(NULL, ",");
    }
    return count;
}

void trim_whitespace(char *str) {
    char *end;

    while(isspace(*str)) str++;

    if(*str == 0) return;

    end = str + strlen(str) - 1;
    while(end > str && isspace(*end)) end--;

    end[1] = '\0';
}

void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: ");
    for(int i = 0; i < resume.skill_count; i++) {
        printf("%s%s", resume.skills[i], (i < resume.skill_count - 1) ? ", " : "\n");
    }
    printf("=========================\n");
}

void parse_resume(const char *resume_text, Resume *resume) {
    char temp[MAX_LENGTH];
    char *line = strtok((char*)resume_text, "\n");
    
    while(line != NULL) {
        trim_whitespace(line);
        if(strncmp(line, "Name:", 5) == 0) {
            strcpy(resume->name, line + 5);
        } else if(strncmp(line, "Email:", 6) == 0) {
            strcpy(resume->email, line + 6);
        } else if(strncmp(line, "Phone:", 6) == 0) {
            strcpy(resume->phone, line + 6);
        } else if(strncmp(line, "Skills:", 7) == 0) {
            strcpy(temp, line + 7);
            resume->skill_count = parse_skills(temp, resume->skills);
        }
        line = strtok(NULL, "\n");
    }
}

void load_resumes(const char *filename, Resume *resumes, int *count) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_LENGTH * 10]; // Assume each resume will not exceed this size
    char *resume_text;
    *count = 0;

    if(file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    while(fgets(buffer, sizeof(buffer), file)) {
        if(strncmp(buffer, "=====", 5) == 0) {
            if(*count < MAX_RESUMES) {
                parse_resume(resume_text, &resumes[*count]);
                (*count)++;
            }
            resume_text = NULL; // Reset for the next resume
        } else {
            if(resume_text == NULL) {
                resume_text = strdup(buffer);
            } else {
                strcat(resume_text, buffer);
            }
        }
    }

    if(resume_text != NULL) {
        parse_resume(resume_text, &resumes[*count]);
        (*count)++;
        free(resume_text);
    }

    fclose(file);
}

int main() {
    Resume resumes[MAX_RESUMES];
    int count = 0;
    
    load_resumes("resumes.txt", resumes, &count);
    
    printf("Parsed resumes:\n");
    for(int i = 0; i < count; i++) {
        print_resume(resumes[i]);
    }
    
    return 0;
}