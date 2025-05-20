//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *name;
    int experience;
    char *education;
} Resume;

Resume *parse_resume(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    Resume *result = NULL;

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        if (strncmp(line, "Name:", 5) == 0) {
            if (sscanf(line, "Name: %s", word) == 1) {
                result = (Resume*) malloc(sizeof(Resume));
                result->name = strdup(word);
            }
        } else if (strncmp(line, "Experience:", 10) == 0) {
            if (sscanf(line, "Experience: %d", &result->experience) == 1) {
                result->education = NULL;
            }
        } else if (strncmp(line, "Education:", 9) == 0) {
            if (sscanf(line, "Education: %s", word) == 1) {
                result->education = strdup(word);
            }
        }
    }

    return result;
}

void print_resume(Resume *resume) {
    if (resume == NULL) {
        printf("No resume found.\n");
        return;
    }

    printf("Name: %s\n", resume->name);
    printf("Experience: %d\n", resume->experience);
    if (resume->education!= NULL) {
        printf("Education: %s\n", resume->education);
    }
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    Resume *resume = parse_resume(fp);
    fclose(fp);

    print_resume(resume);

    if (resume!= NULL) {
        free(resume->name);
        if (resume->education!= NULL) {
            free(resume->education);
        }
        free(resume);
    }

    return 0;
}