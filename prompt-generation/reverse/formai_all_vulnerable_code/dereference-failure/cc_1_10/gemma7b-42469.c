//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void parse_resume(char **resume_text)
{
  // 1. Extract the candidate's name
  char *name = strstr(*resume_text, "Name:");
  if (name)
  {
    name = name + 5;
    printf("Candidate's name: %s\n", name);
  }

  // 2. Extract the candidate's address
  char *address = strstr(*resume_text, "Address:");
  if (address)
  {
    address = address + 8;
    printf("Candidate's address: %s\n", address);
  }

  // 3. Extract the candidate's phone number
  char *phone = strstr(*resume_text, "Phone:");
  if (phone)
  {
    phone = phone + 6;
    printf("Candidate's phone number: %s\n", phone);
  }

  // 4. Extract the candidate's email address
  char *email = strstr(*resume_text, "Email:");
  if (email)
  {
    email = email + 6;
    printf("Candidate's email address: %s\n", email);
  }
}

int main()
{
  // Allocate memory for the resume text
  char *resume_text = malloc(MAX_BUFFER_SIZE);

  // Get the resume text from the user
  printf("Enter the resume text: ");
  fgets(resume_text, MAX_BUFFER_SIZE, stdin);

  // Parse the resume
  parse_resume(&resume_text);

  // Free the memory allocated for the resume text
  free(resume_text);

  return 0;
}