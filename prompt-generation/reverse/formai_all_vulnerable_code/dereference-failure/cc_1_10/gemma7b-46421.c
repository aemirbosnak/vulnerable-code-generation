//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <string.h>

void parse_resume(char *resume) {
  // Declare variables
  char *name, *address, *phone, *email, *summary, *skills;
  int i = 0;

  // Allocate memory for each variable
  name = (char *)malloc(20);
  address = (char *)malloc(50);
  phone = (char *)malloc(20);
  email = (char *)malloc(50);
  summary = (char *)malloc(100);
  skills = (char *)malloc(200);

  // Search for key-value pairs in the resume
  for (i = 0; resume[i] != '\0'; i++) {
    // Find the name-value pair
    if (resume[i] == ':') {
      // Extract the name and value
      name[0] = resume[i - 1];
      name[1] = '\0';
      i++;
      address[0] = resume[i];
      address[1] = '\0';
      i++;
      phone[0] = resume[i];
      phone[1] = '\0';
      i++;
      email[0] = resume[i];
      email[1] = '\0';
      i++;
      summary[0] = resume[i];
      summary[1] = '\0';
      i++;
      skills[0] = resume[i];
      skills[1] = '\0';
      i++;
    }
  }

  // Print the parsed information
  printf("Name: %s\n", name);
  printf("Address: %s\n", address);
  printf("Phone: %s\n", phone);
  printf("Email: %s\n", email);
  printf("Summary: %s\n", summary);
  printf("Skills: %s\n", skills);

  // Free the allocated memory
  free(name);
  free(address);
  free(phone);
  free(email);
  free(summary);
  free(skills);
}

int main() {
  // Get the resume text
  char resume[] = "John Doe:\n123 Main St.\nNew York, NY 10001\n(123) 456-7890\njohn.doe@example.com\nSummary: Experienced software engineer with a strong background in Java and C++.\nSkills: Java, C++, Python, SQL, NoSQL";

  // Parse the resume
  parse_resume(resume);

  return 0;
}