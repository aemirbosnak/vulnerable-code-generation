//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_resume(char *resume)
{
    char **sections = NULL;
    char *section_start = NULL;
    char *section_end = NULL;
    int sections_count = 0;

    // Find the start and end of each section
    section_start = strstr(resume, "Section:");
    while (section_start)
    {
        section_end = strstr(section_start, ":");
        sections_count++;

        // Allocate memory for the sections
        sections = realloc(sections, sections_count * sizeof(char *));
        sections[sections_count - 1] = malloc(section_end - section_start);
        memcpy(sections[sections_count - 1], section_start, section_end - section_start);
        section_start = strstr(section_end, "Section:");
    }

    // Print the sections
    for (int i = 0; i < sections_count; i++)
    {
        printf("Section %d:\n", i + 1);
        printf("%s\n", sections[i]);
    }

    // Free the memory
    for (int i = 0; i < sections_count; i++)
    {
        free(sections[i]);
    }
    free(sections);
}

int main()
{
    char resume[] = "Section: Personal Information\n"
                        "John Doe\n"
                        "123 Main St.\n"
                        "New York, NY 10001\n\n"
                        "Section: Education\n"
                        "Bachelor of Arts in English, Columbia University\n"
                        "Master of Arts in Literature, University of Oxford\n\n"
                        "Section: Work Experience\n"
                        "Software Engineer, Google\n"
                        "New York, NY\n"
                        "2012-2015\n"
                        "Senior Software Engineer, Microsoft\n"
                        "Redwood City, CA\n"
                        "2008-2012\n";

    parse_resume(resume);

    return 0;
}