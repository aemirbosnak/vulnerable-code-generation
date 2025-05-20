//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parse_resume(char *resume) {
    // Allocate memory for the parsed resume
    char *parsed_resume = malloc(strlen(resume) * 2);

    // Copy the resume into the parsed resume
    strcpy(parsed_resume, resume);

    // Iterate over the parsed resume and parse the sections
    char *section_start = parsed_resume;
    while (section_start) {
        // Find the end of the section
        char *section_end = strstr(section_start, ":");

        // Extract the section name
        char *section_name = section_start;
        printf("Section: %s\n", section_name);

        // Iterate over the section and parse the subsections
        char *subsection_start = section_end + 1;
        while (subsection_start) {
            // Find the end of the subsection
            char *subsection_end = strstr(subsection_start, ";");

            // Extract the subsection name
            char *subsection_name = subsection_start;
            printf("Subsection: %s\n", subsection_name);

            // Print the subsection content
            printf("Content: %s\n", subsection_end);

            // Move to the next subsection
            subsection_start = subsection_end + 1;
        }

        // Move to the next section
        section_start = section_end + 1;
    }

    // Free the memory allocated for the parsed resume
    free(parsed_resume);
}

int main() {
    // Get the resume from the user
    char *resume = malloc(100);
    printf("Enter your resume: ");
    fgets(resume, 100, stdin);

    // Parse the resume
    parse_resume(resume);

    // Free the memory allocated for the resume
    free(resume);

    return 0;
}