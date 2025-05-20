//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for resume information
typedef struct {
    char *name;
    char *email;
    char *phone_num;
    char *skills[10]; // store up to 10 skills
    char *work_exp[5]; // store up to 5 work experiences
} Resume;

// function to parse resume and store information in struct
Resume *parse_resume(char *filename) {
    FILE *resume_file;
    char line[100];
    Resume *resume = malloc(sizeof(Resume));

    // open the resume file
    resume_file = fopen(filename, "r");
    if (resume_file == NULL) {
        printf("Error: Could not open resume file.\n");
        return NULL;
    }

    // read each line and store information in struct
    while (fgets(line, sizeof(line), resume_file)) {
        char *token = strtok(line, ":"); // use colon as delimiter

        if (strcmp(token, "Name") == 0) {
            resume->name = strtok(NULL, "\n"); // get the rest of the line
        }
        else if (strcmp(token, "Email") == 0) {
            resume->email = strtok(NULL, "\n");
        }
        else if (strcmp(token, "Phone") == 0) {
            resume->phone_num = strtok(NULL, "\n");
        }
        else if (strcmp(token, "Skills") == 0) {
            char *skill = strtok(NULL, ",\n"); // use comma as delimiter
            int i = 0;

            while (skill != NULL && i < 10) {
                resume->skills[i] = skill;
                i++;
                skill = strtok(NULL, ",\n");
            }
        }
        else if (strcmp(token, "Experience") == 0) {
            char *exp = strtok(NULL, ",\n"); // use comma as delimiter
            int i = 0;

            while (exp != NULL && i < 5) {
                resume->work_exp[i] = exp;
                i++;
                exp = strtok(NULL, ",\n");
            }
        }
        else {
            printf("Error: Invalid resume format.\n");
            return NULL;
        }
    }

    fclose(resume_file);
    return resume;
}

int main() {
    Resume *resume = parse_resume("resume.txt");

    if (resume != NULL) {
        printf("Name: %s\n", resume->name);
        printf("Email: %s\n", resume->email);
        printf("Phone Number: %s\n", resume->phone_num);
        printf("Skills: ");
        for (int i = 0; i < 10 && resume->skills[i] != NULL; i++) {
            printf("%s, ", resume->skills[i]);
        }
        printf("\nWork Experience:\n");
        for (int i = 0; i < 5 && resume->work_exp[i] != NULL; i++) {
            printf("%d. %s\n", i+1, resume->work_exp[i]);
        }
    }

    free(resume);
    return 0;
}