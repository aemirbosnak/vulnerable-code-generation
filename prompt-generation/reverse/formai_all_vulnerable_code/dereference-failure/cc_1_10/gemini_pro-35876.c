//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

// Function to check if a string matches a regular expression
int regex_match(char *string, char *pattern) {
  int status;
  regex_t regex;

  // Compile the regular expression
  if (regcomp(&regex, pattern, REG_EXTENDED | REG_NOSUB) != 0) {
    return 0;
  }

  // Execute the regular expression on the string
  status = regexec(&regex, string, 0, NULL, 0);

  // Free the compiled regular expression
  regfree(&regex);

  // Return the status of the match
  return status == 0;
}

// Function to parse a resume file and extract the relevant information
struct resume_data {
  char *name;
  char *email;
  char *phone_number;
  char *skills;
  char *experience;
  char *education;
  char *awards;
};

struct resume_data *parse_resume(char *filename) {
  // Open the resume file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Read the resume file line by line
  char lines[MAX_LINES][MAX_LINE_LENGTH];
  int line_count = 0;
  while (fgets(lines[line_count], MAX_LINE_LENGTH, file) != NULL) {
    line_count++;
  }

  // Close the resume file
  fclose(file);

  // Initialize the resume data structure
  struct resume_data *data = malloc(sizeof(struct resume_data));
  data->name = NULL;
  data->email = NULL;
  data->phone_number = NULL;
  data->skills = NULL;
  data->experience = NULL;
  data->education = NULL;
  data->awards = NULL;

  // Parse the resume file line by line
  for (int i = 0; i < line_count; i++) {
    char *line = lines[i];

    // Extract the name
    if (regex_match(line, ".*Name:.*")) {
      data->name = strdup(strtok(line, ":"));
    }

    // Extract the email
    if (regex_match(line, ".*Email:.*")) {
      data->email = strdup(strtok(line, ":"));
    }

    // Extract the phone number
    if (regex_match(line, ".*Phone Number:.*")) {
      data->phone_number = strdup(strtok(line, ":"));
    }

    // Extract the skills
    if (regex_match(line, ".*Skills:.*")) {
      data->skills = strdup(strtok(line, ":"));
    }

    // Extract the experience
    if (regex_match(line, ".*Experience:.*")) {
      data->experience = strdup(strtok(line, ":"));
    }

    // Extract the education
    if (regex_match(line, ".*Education:.*")) {
      data->education = strdup(strtok(line, ":"));
    }

    // Extract the awards
    if (regex_match(line, ".*Awards:.*")) {
      data->awards = strdup(strtok(line, ":"));
    }
  }

  // Return the resume data structure
  return data;
}

// Function to print the resume data structure
void print_resume_data(struct resume_data *data) {
  printf("Name: %s\n", data->name);
  printf("Email: %s\n", data->email);
  printf("Phone Number: %s\n", data->phone_number);
  printf("Skills: %s\n", data->skills);
  printf("Experience: %s\n", data->experience);
  printf("Education: %s\n", data->education);
  printf("Awards: %s\n", data->awards);
}

// Main function
int main() {
  // Parse the resume file
  struct resume_data *data = parse_resume("resume.txt");

  // Print the resume data
  print_resume_data(data);

  // Free the resume data structure
  free(data);

  return 0;
}