//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_SECTIONS 10

typedef struct {
    char *name;
    char *value;
} Section;

typedef struct {
    char *name;
    int num_sections;
    Section sections[MAX_SECTIONS];
} Resume;

Resume *parse_resume(FILE *fp) {
    Resume *resume = (Resume *)malloc(sizeof(Resume));
    char line[MAX_LINE_LENGTH];
    char *name = NULL;
    char *value = NULL;
    int num_sections = 0;
    Section *current_section = NULL;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (name == NULL) {
            name = strtok(line, ":");
        } else if (value == NULL) {
            value = strtok(NULL, ":");
        } else {
            if (num_sections >= MAX_SECTIONS) {
                fprintf(stderr, "Error: Too many sections.\n");
                exit(1);
            }
            current_section = &resume->sections[num_sections];
            current_section->name = strdup(name);
            current_section->value = strdup(value);
            num_sections++;
            name = NULL;
            value = NULL;
        }
    }

    if (name!= NULL || value!= NULL) {
        fprintf(stderr, "Error: Invalid resume format.\n");
        exit(1);
    }

    return resume;
}

void print_resume(Resume *resume) {
    for (int i = 0; i < resume->num_sections; i++) {
        printf("%s: %s\n", resume->sections[i].name, resume->sections[i].value);
    }
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    Resume *resume = parse_resume(fp);
    print_resume(resume);
    return 0;
}