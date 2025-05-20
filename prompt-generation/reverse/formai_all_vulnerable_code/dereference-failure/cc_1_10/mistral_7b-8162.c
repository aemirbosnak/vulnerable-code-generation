//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 50
#define MAX_CONTACT_LENGTH 100
#define MAX_SKILL_LENGTH 30
#define MAX_LINES 10
#define FILE_MODE "r"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char contact[MAX_CONTACT_LENGTH];
    char skills[MAX_LINES][MAX_SKILL_LENGTH];
} resume_t;

bool is_file_valid(const char *file_path) {
    struct stat file_stat;
    if (stat(file_path, &file_stat) < 0) {
        perror("Error while checking file existence");
        return false;
    }
    if (S_ISREG(file_stat.st_mode) == 0) {
        fprintf(stderr, "%s is not a regular file\n", file_path);
        return false;
    }
    return true;
}

void parse_resume(const char *file_path, resume_t *resume) {
    FILE *file = fopen(file_path, FILE_MODE);
    char line[MAX_NAME_LENGTH + MAX_CONTACT_LENGTH + MAX_SKILL_LENGTH + 50];
    int line_number = 0;

    if (file == NULL) {
        perror("Error while opening file");
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;
        if (line_number == 1) {
            strcpy(resume->name, line);
            continue;
        }
        if (line_number > 1 && line_number <= MAX_LINES + 1) {
            strcpy(resume->skills[line_number - 2], line);
            continue;
        }
        if (line_number > MAX_LINES + 1) {
            strcpy(resume->contact, line);
            break;
        }
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <resume_file_path>\n", argv[0]);
        return 1;
    }

    resume_t resume;
    char file_path[MAX_NAME_LENGTH];

    strcpy(file_path, argv[1]);

    if (!is_file_valid(file_path)) {
        fprintf(stderr, "Invalid resume file\n");
        return 1;
    }

    parse_resume(file_path, &resume);

    printf("Name: %s\n", resume.name);
    printf("Contact: %s\n", resume.contact);
    for (int i = 0; i < MAX_LINES; i++) {
        if (resume.skills[i][0] != '\0') {
            printf("Skill %d: %s\n", i + 1, resume.skills[i]);
        }
    }

    return 0;
}