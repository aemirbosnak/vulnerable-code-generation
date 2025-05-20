//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant MAX_LENGTH to limit the input length
#define MAX_LENGTH 512

// Define a constant SEARCH_TERMS_NUM to represent the number of search terms
#define SEARCH_TERMS_NUM 5

// Define an array of search terms to be parsed from the resume
const char *search_terms[SEARCH_TERMS_NUM] = { "education", "experience", "skills", "projects", "awards" };

// Define a struct to store the parsed resume information
typedef struct {
    char *education;
    char *experience;
    char *skills;
    char *projects;
    char *awards;
} Resume;

// Define a function to initialize a Resume struct
Resume *init_resume() {
    Resume *resume = malloc(sizeof(Resume));
    resume->education = NULL;
    resume->experience = NULL;
    resume->skills = NULL;
    resume->projects = NULL;
    resume->awards = NULL;
    return resume;
}

// Define a function to free the memory used by a Resume struct
void free_resume(Resume *resume) {
    if (resume) {
        if (resume->education) {
            free(resume->education);
        }
        if (resume->experience) {
            free(resume->experience);
        }
        if (resume->skills) {
            free(resume->skills);
        }
        if (resume->projects) {
            free(resume->projects);
        }
        if (resume->awards) {
            free(resume->awards);
        }
        free(resume);
    }
}

// Define a function to parse the resume and store the information in the Resume struct
void parse_resume(const char *resume_text, Resume *resume) {
    char *search_term_start, *search_term_end, *section_start, *section_end;
    int term_length, section_length, i;

    // Loop through each search term
    for (i = 0; i < SEARCH_TERMS_NUM; i++) {
        // Find the start and end positions of the search term
        search_term_start = strstr(resume_text, search_terms[i]);
        if (search_term_start) {
            search_term_end = strstr(search_term_start + strlen(search_terms[i]), "\n");
        } else {
            search_term_end = NULL;
        }

        // Check if the search term exists in the resume text
        if (search_term_start && search_term_end) {
            // Find the start and end positions of the section after the search term
            section_start = search_term_end + 1;
            section_end = (i == SEARCH_TERMS_NUM - 1) ? strstr(resume_text, "\0") : strstr(search_term_end, search_terms[i+1]);
            section_end = section_end ? section_end : strstr(section_start, "\0");

            // Calculate the lengths of the search term and section text
            term_length = search_term_end - search_term_start + 1;
            section_length = section_end - section_start;

            // Allocate memory for the section text and copy the text into the Resume struct
            switch (i) {
                case 0:
                    resume->education = malloc(section_length + 1);
                    strncpy(resume->education, section_start, section_length);
                    break;
                case 1:
                    resume->experience = malloc(section_length + 1);
                    strncpy(resume->experience, section_start, section_length);
                    break;
                case 2:
                    resume->skills = malloc(section_length + 1);
                    strncpy(resume->skills, section_start, section_length);
                    break;
                case 3:
                    resume->projects = malloc(section_length + 1);
                    strncpy(resume->projects, section_start, section_length);
                    break;
                case 4:
                    resume->awards = malloc(section_length + 1);
                    strncpy(resume->awards, section_start, section_length);
                    break;
            }
        } else {
            // If the search term does not exist in the resume text, set the section text to NULL
            switch (i) {
                case 0:
                    resume->education = NULL;
                    break;
                case 1:
                    resume->experience = NULL;
                    break;
                case 2:
                    resume->skills = NULL;
                    break;
                case 3:
                    resume->projects = NULL;
                    break;
                case 4:
                    resume->awards = NULL;
                    break;
            }
        }
    }
}

int main() {
    char resume_text[MAX_LENGTH];
    Resume *resume;

    // Prompt the user to input the resume text
    printf("Please enter your resume text:\n");
    fgets(resume_text, MAX_LENGTH, stdin);

    // Initialize the Resume struct
    resume = init_resume();

    // Parse the resume and store the information in the Resume struct
    parse_resume(resume_text, resume);

    // Print the parsed information for debugging purposes
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);
    printf("Skills: %s\n", resume->skills);
    printf("Projects: %s\n", resume->projects);
    printf("Awards: %s\n", resume->awards);

    // Free the memory used by the Resume struct
    free_resume(resume);

    return 0;
}