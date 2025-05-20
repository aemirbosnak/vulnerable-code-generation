//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_EXPERIENCE_LENGTH 500

typedef struct Cv {
    char name[MAX_NAME_LENGTH];
    int experience_years;
    char experience[MAX_EXPERIENCE_LENGTH];
} Cv;

void parse_resume(Cv *cv) {
    char *resume_text;
    int i = 0;

    // Allocate memory for the resume text
    resume_text = malloc(MAX_EXPERIENCE_LENGTH);

    // Get the resume text from the user
    printf("Enter the resume text: ");
    fgets(resume_text, MAX_EXPERIENCE_LENGTH, stdin);

    // Parse the resume text
    for (i = 0; resume_text[i] != '\0'; i++) {
        // Check if the text is a name or experience
        if (resume_text[i] >= 'a' && resume_text[i] <= 'z') {
            // Extract the name
            strcpy(cv->name, resume_text + i);
        } else if (resume_text[i] >= '0' && resume_text[i] <= '9') {
            // Extract the experience years
            cv->experience_years = atoi(resume_text + i);
        } else if (resume_text[i] == ' ' || resume_text[i] == '\n') {
            // Extract the experience
            strcpy(cv->experience, resume_text + i + 1);
        }
    }

    // Free the memory allocated for the resume text
    free(resume_text);
}

int main() {
    Cv cv;

    parse_resume(&cv);

    // Print the parsed data
    printf("Name: %s\n", cv.name);
    printf("Experience years: %d\n", cv.experience_years);
    printf("Experience: %s\n", cv.experience);

    return 0;
}