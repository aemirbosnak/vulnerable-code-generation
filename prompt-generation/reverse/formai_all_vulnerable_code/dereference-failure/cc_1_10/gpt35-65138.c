//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

#define MAX_RESUME_LENGTH 1000 // Maximum length of the resume
#define MAX_KEYWORD_LENGTH 20 // Maximum length of a keyword
#define MAX_SKILLS_COUNT 10 // Maximum number of skills to look for

// Sample skills to look for in a resume
char skills[MAX_SKILLS_COUNT][MAX_KEYWORD_LENGTH] = {
    "C",
    "Java",
    "Python",
    "HTML",
    "CSS",
    "JavaScript",
    "PHP",
    "MySQL",
    "Linux",
    "Git"
};

/**
 * Returns 1 if the skill is found in the text; else returns 0.
 */
int contains_skill(char *text, char *skill) {
    // Case-insensitively find the index of the skill.
    char *index = strcasestr(text, skill);

    // If the index is NULL, skill is not found in the text.
    if(index == NULL) {
        return 0;
    }

    return 1;
}

/**
 * Returns number of times the skill is found in the text.
 */
int count_skill_occurrences(char *text, char *skill) {
    int count = 0;
    char *index = text;

    // Loop through the text to find all occurrences of skill.
    while(1) {
        index = strcasestr(index, skill);

        // If the index is NULL, skill is not found anymore. Exit loop.
        if(index == NULL) {
            break;
        }

        count++;
        index++; // Move forward for checking next match.
    }

    return count;
}

/**
 * Extracts the text from the resume file.
 */
char* extract_resume_text(char *filename) {
    FILE *fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    // Allocate memory for the text buffer.
    char *buffer = (char*) malloc(MAX_RESUME_LENGTH * sizeof(char));
    if(buffer == NULL) {
        printf("Error: Could not allocate memory\n");
        return NULL;
    }

    // Read from the file and store in the buffer.
    int length = 0;
    while(1) {
        char c = fgetc(fp);

        // If EOF is reached or buffer is full, exit loop.
        if(c == EOF || length == MAX_RESUME_LENGTH - 1) {
            break;
        }

        buffer[length++] = c;
    }

    buffer[length] = '\0'; // Terminate with NUL character.

    fclose(fp); 
    return buffer;
}

/**
 * Main function to parse the resume and find skills.
 */
int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s <resume_file>\n", argv[0]);
        return 0;
    }

    // Extract the resume text from the file.
    char *text = extract_resume_text(argv[1]);

    if(text == NULL) {
        return 0;
    }

    printf("Parsing resume: %s\n\n", argv[1]);

    // Loop through the skills to find their occurrences in the text.
    for(int i = 0; i < MAX_SKILLS_COUNT; i++) {
        int count = count_skill_occurrences(text, skills[i]);

        if(count > 0) {
            printf("%s: %d\n", skills[i], count);
        }
    }

    free(text); // Deallocate memory of the text buffer.
    return 0;
}