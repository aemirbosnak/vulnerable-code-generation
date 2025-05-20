//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_resume(char *resume)
{
    char **sections = NULL;
    char *current_section = NULL;
    int num_sections = 0;

    // Allocate memory for the sections array
    sections = malloc(10 * sizeof(char *));

    // Iterate over the resume, section by section
    while (*resume)
    {
        // Check if the current section is the start of a new section
        if (*resume == 'H' || *resume == 'A' || *resume == 'O')
        {
            // Allocate memory for the new section
            current_section = malloc(20 * sizeof(char));

            // Copy the section header into the current section
            strcpy(current_section, resume);

            // Add the current section to the sections array
            sections[num_sections++] = current_section;
        }

        // Move to the next character in the resume
        resume++;
    }

    // Print the sections
    for (int i = 0; i < num_sections; i++)
    {
        printf("%s\n", sections[i]);
    }

    // Free the memory allocated for the sections array
    free(sections);
}

int main()
{
    char resume[] = "Henry Doe\n"
                    "123 Main St.\n"
                    "New York, NY 10001\n"
                    "\n"
                    "Summary\n"
                    "Highly motivated and experienced professional with a strong background in software engineering."
                    "\n"
                    "Skills\n"
                    "Java, C++, Python, SQL, NoSQL, DevOps\n";

    parse_resume(resume);

    return 0;
}