//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char* name;
    char* email;
    char* phone;
    char* skills[10];
    char* experience[10];
    char* education[10];   
};

void parse_resume(struct Resume* resume, char* file_name) {
    FILE* file = fopen(file_name, "r");
    char line[100];
    int line_num = 0;
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, ":");
        char* value = strtok(NULL, ":");
        if (strcmp(token, "name") == 0) {
            resume->name = strdup(value);
        } else if (strcmp(token, "email") == 0) {
            resume->email = strdup(value);
        } else if (strcmp(token, "phone") == 0) {
            resume->phone = strdup(value);
        } else if (strcmp(token, "skills") == 0) {
            resume->skills[line_num] = strdup(value);
            line_num++;
        } else if (strcmp(token, "experience") == 0) {
            resume->experience[line_num] = strdup(value);
            line_num++;
        } else if (strcmp(token, "education") == 0) {
            resume->education[line_num] = strdup(value);
            line_num++;
        }
    }
    fclose(file);
}

void print_resume(struct Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills:\n");
    for (int i = 0; i < 10; i++) {
        if (resume->skills[i] != NULL) {
            printf("  - %s\n", resume->skills[i]);
        }
    }
    printf("Experience:\n");
    for (int i = 0; i < 10; i++) {
        if (resume->experience[i] != NULL) {
            printf("  - %s\n", resume->experience[i]);
        }
    }
    printf("Education:\n");
    for (int i = 0; i < 10; i++) {
        if (resume->education[i] != NULL) {
            printf("  - %s\n", resume->education[i]);
        }
    }
}

int main() {
    struct Resume res;
    parse_resume(&res, "sample_resume.txt");
    print_resume(&res);
    return 0;
}