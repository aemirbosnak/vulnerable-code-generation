//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse the name from a resume
char *parse_name(char *resume) {
  char *name = malloc(100);
  int i = 0;
  while (resume[i] != '\n') {
    name[i] = resume[i];
    i++;
  }
  name[i] = '\0';
  return name;
}

// Function to parse the email address from a resume
char *parse_email(char *resume) {
  char *email = malloc(100);
  int i = 0;
  while (resume[i] != '\n') {
    i++;
  }
  i++;
  int j = 0;
  while (resume[i] != '\n') {
    email[j] = resume[i];
    i++;
    j++;
  }
  email[j] = '\0';
  return email;
}

// Function to parse the phone number from a resume
char *parse_phone(char *resume) {
  char *phone = malloc(20);
  int i = 0;
  while (resume[i] != '\n') {
    i++;
  }
  i++;
  i++;
  int j = 0;
  while (resume[i] != '\n') {
    phone[j] = resume[i];
    i++;
    j++;
  }
  phone[j] = '\0';
  return phone;
}

// Function to parse the skills from a resume
char **parse_skills(char *resume) {
  char **skills = malloc(100 * sizeof(char *));
  int i = 0;
  int j = 0;
  while (resume[i] != '\0') {
    if (resume[i] == '\n') {
      i++;
      j++;
    }
    skills[j] = malloc(100);
    int k = 0;
    while (resume[i] != '\n' && resume[i] != '\0') {
      skills[j][k] = resume[i];
      i++;
      k++;
    }
    skills[j][k] = '\0';
  }
  return skills;
}

// Function to print a resume
void print_resume(char *name, char *email, char *phone, char **skills) {
  printf("Name: %s\n", name);
  printf("Email: %s\n", email);
  printf("Phone: %s\n", phone);
  printf("Skills: ");
  int i = 0;
  while (skills[i] != NULL) {
    printf("%s, ", skills[i]);
    i++;
  }
  printf("\n");
}

// Main function
int main() {
  char *resume =
      "John Doe\n"
      "john.doe@example.com\n"
      "555-555-5555\n"
      "Skills:\n"
      "C\n"
      "C++\n"
      "Java\n"
      "Python\n";

  char *name = parse_name(resume);
  char *email = parse_email(resume);
  char *phone = parse_phone(resume);
  char **skills = parse_skills(resume);

  print_resume(name, email, phone, skills);

  return 0;
}