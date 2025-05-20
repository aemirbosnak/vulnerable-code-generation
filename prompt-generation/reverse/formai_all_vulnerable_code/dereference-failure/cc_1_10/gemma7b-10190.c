//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX 10

void parse_resume(char **resume)
{
  int i = 0;
  char **sections = malloc(MAX * sizeof(char *));
  sections[0] = strdup("Personal Information");
  sections[1] = strdup("Professional Summary");
  sections[2] = strdup("Skills");
  sections[3] = strdup("Experience");
  sections[4] = strdup("Education");

  for (; resume[i] != NULL; i++)
  {
    char *section = NULL;
    for (int j = 0; sections[j] != NULL; j++)
    {
      if (strstr(resume[i], sections[j]) != NULL)
      {
        section = sections[j];
        break;
      }
    }

    if (section != NULL)
    {
      printf("Section: %s\n", section);
      printf("Content: %s\n", resume[i]);
    }
  }
}

int main()
{
  char **resume = malloc(MAX * sizeof(char *));
  resume[0] = strdup("John Doe");
  resume[1] = strdup("123 Main St.");
  resume[2] = strdup("New York, NY 10001");
  resume[3] = strdup("(123) 456-7890");
  resume[4] = strdup("john.doe@example.com");
  resume[5] = strdup("Summary");
  resume[6] = strdup("Highly motivated and experienced professional with a strong track record of success in the technology industry.");
  resume[7] = strdup("Skills");
  resume[8] = strdup("Java, C++, Python, SQL");
  resume[9] = strdup("Experience");
  resume[10] = strdup("Software Engineer, ACM Corporation, New York, NY");
  resume[11] = strdup("Developed and implemented software solutions for various clients.");

  parse_resume(resume);

  return 0;
}