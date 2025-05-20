//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_resume(char *resume_text)
{
    char **sections = NULL;
    char *section_name = NULL;
    char *section_content = NULL;

    // Allocate memory for sections array
    sections = malloc(10 * sizeof(char *));

    // Parse resume text into sections
    section_name = strtok(resume_text, ":");
    sections[0] = strdup(section_name);

    // Iterate over sections and extract content
    for (int i = 1; sections[i - 1] != NULL; i++)
    {
        section_content = strtok(NULL, ":");
        sections[i] = strdup(section_content);
    }

    // Print sections
    for (int i = 0; sections[i] != NULL; i++)
    {
        printf("%s\n", sections[i]);
    }

    // Free memory
    free(sections);
    free(section_name);
    free(section_content);
}

int main()
{
    char *resume_text = "John Doe:\n"
                           "123 Main St.\n"
                           "New York, NY 10001\n"
                           "Phone: (123) 456-7890\n"
                           "Email: john.doe@example.com\n"
                           "\n"
                           "Summary:\n"
                           "Highly motivated and experienced professional with a strong track record of success in the technology industry.\n"
                           "\n"
                           "Skills:\n"
                           "Java, Python, C++, SQL, NoSQL\n"
                           "\n"
                           "Experience:\n"
                           "Software Engineer, Google, Mountain View, CA, 2018-2022\n"
                           "Junior Software Engineer, Amazon, New York, NY, 2016-2018\n";

    parse_resume(resume_text);

    return 0;
}