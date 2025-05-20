//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_resume(char *resume_text)
{
    char *key_words[] = {"Skills", "Experience", "Education", "References"};
    int i = 0;
    char **sections = NULL;

    // Allocate memory for sections
    sections = malloc(10 * sizeof(char *));
    for (i = 0; i < 10; i++)
    {
        sections[i] = NULL;
    }

    // Parse the resume text and identify sections
    char *section_start = strtok(resume_text, " ");
    int section_count = 0;
    while (section_start)
    {
        for (i = 0; i < 4; i++)
        {
            if (strcmp(section_start, key_words[i]) == 0)
            {
                sections[section_count] = malloc(100 * sizeof(char));
                strcpy(sections[section_count], section_start);
                section_count++;
            }
        }

        section_start = strtok(NULL, " ");
    }

    // Print the sections
    for (i = 0; i < section_count; i++)
    {
        printf("%s\n", sections[i]);
    }

    // Free memory
    for (i = 0; i < section_count; i++)
    {
        free(sections[i]);
    }
    free(sections);
}

int main()
{
    char *resume_text = "John Doe\n123 Main St.\nNew York, NY 12345\n(123) 456-7890\n\nSkills: Programming, Writing, Editing\n\nExperience: Software Engineer, Google Inc., Mountain View, CA, 2018-2022\n\nEducation: Bachelor of Arts in Computer Science, University of California, Berkeley, 2018\n\nReferences: Available upon request";

    parse_resume(resume_text);

    return 0;
}