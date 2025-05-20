//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_SKILLS 10

// Struct for storing Resume data
struct Resume {
    char name[MAX_WORD_LENGTH];
    char email[MAX_WORD_LENGTH];
    char skills[MAX_SKILLS][MAX_WORD_LENGTH];
};

// Function to split text into words & store them in an array
int split_text_into_words(char text[], char words[][MAX_WORD_LENGTH]) {
    int i = 0, j = 0, k = 0, word_count = 0;
    while (text[i] != '\0') {
        if (text[i] == ' ' || text[i] == '\n') {
            if (j > 0) {
                words[word_count][k] = '\0';
                k = 0;
                word_count++;
            }
        } else {
            words[word_count][k] = text[i];
            j++;
            k++;
        }

        i++;
    }

    return word_count;
}

// Function to parse a resume and return Resume object
struct Resume parse_resume(char path[]) {
    FILE *file_pointer;
    char resume_string[MAX_RESUME_LENGTH];

    // Open and read resume file as a string
    file_pointer = fopen(path, "r");
    fgets(resume_string, sizeof(resume_string), file_pointer);
    fclose(file_pointer);

    struct Resume parsed_resume;
    // Parse name from resume
    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    int word_count = split_text_into_words(resume_string, words);
    strcpy(parsed_resume.name, words[0]);

    // Parse email from resume
    for (int i = 0; i < word_count; i++) {
        if (strstr(words[i], "@") != NULL) {
            strcpy(parsed_resume.email, words[i]);
        }
    }

    // Parse skills from resume
    int skill_count = 0;
    for (int i = 0; i < word_count; i++) {
        if (strcmp(words[i], "Skills:") == 0) {
            i++;
            while (i < word_count && skill_count < MAX_SKILLS) {
                if (strlen(words[i]) > 1) {
                    strcpy(parsed_resume.skills[skill_count], words[i]);
                    skill_count++;
                }

                i++;
            }

            break;
        }
    }

    return parsed_resume;
}

int main() {
    char file_path[] = "resume.txt";
    struct Resume parsed_resume = parse_resume(file_path);

    printf("Resume Parsed Successfully!\n");
    printf("Name: %s\n", parsed_resume.name);
    printf("Email: %s\n", parsed_resume.email);

    printf("\nSkills: \n");
    for (int i = 0; i < MAX_SKILLS; i++) {
        if (strlen(parsed_resume.skills[i]) > 0) {
            printf("%d) %s\n", i + 1, parsed_resume.skills[i]);
        }
    }

    return 0;
}