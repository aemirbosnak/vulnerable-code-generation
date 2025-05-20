//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RESUMES 100
#define MAX_SKILLS 50

typedef struct {
    char name[50];
    char address[100];
    char email[50];
    char skills[MAX_SKILLS][20];
    int num_skills;
} Resume;

Resume *parse_resume(char *text);
void print_resume(Resume *r);

int main() {
    char *resume_text = "Name: John Smith\n"
                        "Address: 123 Main St.\n"
                        "Email: johnsmith@email.com\n"
                        "Skills: C programming, Java programming, Python programming\n";
    Resume *resume = parse_resume(resume_text);
    print_resume(resume);
    free(resume);

    return 0;
}

Resume *parse_resume(char *text) {
    Resume *resume = (Resume*)malloc(sizeof(Resume));
    resume->num_skills = 0;

    char *ptr = strtok(text, "\n");
    while (ptr != NULL) {
        if (strstr(ptr, "Name: ") != NULL) {
            strcpy(resume->name, ptr + 6);
        } else if (strstr(ptr, "Address: ") != NULL) {
            strcpy(resume->address, ptr + 9);
        } else if (strstr(ptr, "Email: ") != NULL) {
            strcpy(resume->email, ptr + 7);
        } else if (strstr(ptr, "Skills: ") != NULL) {
            ptr += 8;
            while (*ptr != '\0') {
                if (*ptr == ',') {
                    ptr++;
                }
                char skill[20];
                int i = 0;
                while (isalpha(*ptr)) {
                    skill[i++] = *ptr++;
                }
                skill[i] = '\0';
                strcpy(resume->skills[resume->num_skills++], skill);
            }
        }
        ptr = strtok(NULL, "\n");
    }

    return resume;
}

void print_resume(Resume *r) {
    printf("Name: %s\n", r->name);
    printf("Address: %s\n", r->address);
    printf("Email: %s\n", r->email);
    printf("Skills: ");
    for (int i = 0; i < r->num_skills; i++) {
        printf("%s", r->skills[i]);
        if (i < r->num_skills - 1) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
}