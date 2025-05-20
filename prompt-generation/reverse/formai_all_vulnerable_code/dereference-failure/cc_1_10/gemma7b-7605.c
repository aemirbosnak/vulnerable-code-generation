//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

void parse_resume(char **resume_data)
{
  char **name_parts = NULL;
  char name[MAX_NAME_LENGTH] = "";
  int i = 0;

  // Allocate memory for name parts
  name_parts = malloc(MAX_NAME_LENGTH * sizeof(char *));

  // Extract name parts from resume data
  for (i = 0; resume_data[i] != NULL; i++)
  {
    if (strstr(resume_data[i], "Name:") != NULL)
    {
      char *name_start = strstr(resume_data[i], ":");
      name_start += 2;
      strncpy(name, name_start, MAX_NAME_LENGTH - 1);
      name_parts[0] = name;
    }
  }

  // Print name parts
  for (i = 0; name_parts[i] != NULL; i++)
  {
    printf("%s\n", name_parts[i]);
  }

  // Free memory
  free(name_parts);
}

int main()
{
  char **resume_data = NULL;

  // Allocate memory for resume data
  resume_data = malloc(MAX_NAME_LENGTH * sizeof(char *));

  // Read resume data from file
  FILE *fp = fopen("resume.txt", "r");
  int i = 0;
  char line[MAX_NAME_LENGTH] = "";
  while (getline(fp, line, MAX_NAME_LENGTH) != -1)
  {
    resume_data[i] = strdup(line);
    i++;
  }
  fclose(fp);

  // Parse resume data
  parse_resume(resume_data);

  // Free memory
  free(resume_data);

  return 0;
}