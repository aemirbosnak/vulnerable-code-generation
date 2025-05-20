//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_resume(char **resume)
{
  int i = 0;
  char *section = NULL;
  char *key = NULL;
  char *value = NULL;

  // Loop over the resume
  for (i = 0; resume[i] != NULL; i++)
  {
    // Check if the current character is the start of a section
    if (resume[i] >= 'A' && resume[i] <= 'Z')
    {
      section = strdup(resume[i]);
    }

    // Check if the current character is the key-value separator
    if (resume[i] == ':')
    {
      key = strdup(resume[i - 1]);
      value = strdup(resume[i + 1]);
    }

    // Print the section, key, and value
    if (section && key && value)
    {
      printf("Section: %s\n", section);
      printf("Key: %s\n", key);
      printf("Value: %s\n", value);
    }
  }
}

int main()
{
  char *resume = "Jane Doe\n"
                   "123 Main St.\n"
                   "New York, NY 10001\n"
                   "(123) 456-7890\n"
                   "\n"
                   "Summary\n"
                   "Highly motivated and experienced professional with a strong background in marketing and communications.\n"
                   "\n"
                   "Skills\n"
                   "Proficient in Microsoft Office Suite, Google Analytics, and social media marketing.\n";

  parse_resume(&resume);

  return 0;
}