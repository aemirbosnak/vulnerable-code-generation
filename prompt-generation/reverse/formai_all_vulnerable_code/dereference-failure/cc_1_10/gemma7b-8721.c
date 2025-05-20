//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <string.h>

void parse_resume(char *resume_text)
{
    char *key_words[] = {"Skills", "Experience", "Education", "References"};
    int i = 0;

    // Iterate over key words
    for (; i < 4; i++)
    {
        char *key_word = key_words[i];
        char *value = strstr(resume_text, key_word);

        // If key word is found, extract value
        if (value)
        {
            char *start = value;
            char *end = strstr(start, key_word);

            // Remove key word and surrounding whitespace
            char *parsed_value = malloc(end - start + 1);
            memcpy(parsed_value, start, end - start);
            parsed_value[end - start] = '\0';

            // Print parsed value
            printf("%s: %s\n", key_word, parsed_value);
            free(parsed_value);
        }
    }
}

int main()
{
    char resume_text[] = "Jane Doe\n"
                          "123 Main St.\n"
                          "New York, NY 10001\n"
                          "\n"
                          "**Skills:** Java, Python, C++, SQL\n"
                          "\n"
                          "**Experience:** Software Engineer, Google, New York, NY (2018-2022)\n"
                          "Software Engineer, Microsoft, Seattle, WA (2016-2018)\n"
                          "\n"
                          "**Education:** Master of Science in Computer Science, University of California, Berkeley (2016)\n"
                          "Bachelor of Science in Electrical Engineering, University of Pennsylvania, Philadelphia (2012)\n"
                          "\n"
                          "**References:** Available upon request.\n";

    parse_resume(resume_text);

    return 0;
}