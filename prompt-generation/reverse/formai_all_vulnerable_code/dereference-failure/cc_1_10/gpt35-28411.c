//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *position;
    int years_of_experience;
} Resume;

Resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_num = 1;
    Resume *resume = malloc(sizeof(Resume));

    while ((read = getline(&line, &len, fp)) != -1) {
        switch(line_num) {
            case 1: // name
                resume->name = strdup(line);
                break;
            case 2: // position
                resume->position = strdup(line);
                break;
            case 3: // years of experience
                resume->years_of_experience = atoi(line);
                break;
            default:
                printf("Invalid file format.");
                exit(1);
        }

        line_num++;
    }

    free(line);
    fclose(fp);

    return resume;
}

int main() {
    char *filename = "resume.txt";
    Resume *my_resume = parse_resume(filename);

    printf("Name: %s", my_resume->name);
    printf("Position: %s", my_resume->position);
    printf("Years of Experience: %d", my_resume->years_of_experience);

    free(my_resume->name);
    free(my_resume->position);
    free(my_resume);

    return 0;
}