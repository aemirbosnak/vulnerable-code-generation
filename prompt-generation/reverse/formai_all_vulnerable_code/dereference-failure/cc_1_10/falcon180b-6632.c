//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove whitespace from a string
void remove_whitespace(char* str) {
    int i = 0;
    int j = 0;

    while (str[i]) {
        if (!isspace(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

// Function to split a string into an array of strings
int split_string(char* str, char** tokens) {
    int count = 0;
    char* token = strtok(str, " ");

    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to print a resume in a medieval style
void print_resume(char* name, int experience, char* skills[]) {
    printf("Hear ye, hear ye! Presenting the resume of Sir/Madam %s:\n", name);
    printf("Experience: %d years\n", experience);
    printf("Skills:\n");

    for (int i = 0; skills[i]!= NULL; i++) {
        printf("\t%s\n", skills[i]);
    }
}

// Main function
int main() {
    FILE* resume_file = fopen("resume.txt", "r");

    if (resume_file == NULL) {
        printf("Error: Could not open resume file.\n");
        return 1;
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, resume_file))!= -1) {
        char* name = NULL;
        int experience = 0;
        char* skills[100];
        int skill_count = 0;

        remove_whitespace(line);

        if (sscanf(line, "Name: %s Experience: %d Skills: %s", name, &experience, skills[0]) == 3) {
            int token_count = split_string(skills[0], skills);

            for (int i = 1; i < token_count; i++) {
                strcpy(skills[i], skills[i - 1]);
                skills[i - 1] = NULL;
            }

            print_resume(name, experience, skills);
        } else {
            printf("Invalid resume format.\n");
        }

        free(line);
    }

    fclose(resume_file);

    return 0;
}