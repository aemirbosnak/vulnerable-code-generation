//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a data structure to hold resume information
typedef struct {
  char name[100];
  char email[100];
  char phone[20];
  char skills[200];
  char experiences[500];
} Resume;

// Define a function to populate resume information
Resume *parse_resume(char *resume_text) {
  Resume *r = malloc(sizeof(Resume));
  
  // Use string manipulation functions to extract information from the resume text
  char *name_start = strstr(resume_text, "Name:");
  if (name_start == NULL) {
    printf("Error: name not found\n");
    return NULL;
  }
  char *name_end = strstr(name_start, "\n");
  strncpy(r->name, name_start+5, name_end-name_start-5);
  r->name[name_end-name_start-5] = '\0';

  char *email_start = strstr(resume_text, "Email:");
  if (email_start == NULL) {
    printf("Error: email not found\n");
    return NULL;
  }
  char *email_end = strstr(email_start, "\n");
  strncpy(r->email, email_start+6, email_end-email_start-6);
  r->email[email_end-email_start-6] = '\0';

  char *phone_start = strstr(resume_text, "Phone:");
  if (phone_start == NULL) {
    printf("Error: phone not found\n");
    return NULL;
  }
  char *phone_end = strstr(phone_start, "\n");
  strncpy(r->phone, phone_start+6, phone_end-phone_start-6);
  r->phone[phone_end-phone_start-6] = '\0';

  char *skills_start = strstr(resume_text, "Skills:");
  if (skills_start == NULL) {
    printf("Error: skills not found\n");
    return NULL;
  }
  char *skills_end = strstr(skills_start, "\n");
  strncpy(r->skills, skills_start+7, skills_end-skills_start-7);
  r->skills[skills_end-skills_start-7] = '\0';

  char *experiences_start = strstr(resume_text, "Experiences:");
  if (experiences_start == NULL) {
    printf("Error: experiences not found\n");
    return NULL;
  }
  char *experiences_end = strstr(experiences_start, "\n");
  strncpy(r->experiences, experiences_start+12, experiences_end-experiences_start-12);
  r->experiences[experiences_end-experiences_start-12] = '\0';

  return r;
}

// Define a function to print out resume information
void print_resume(Resume *r) {
  printf("Name: %s\n", r->name);
  printf("Email: %s\n", r->email);
  printf("Phone: %s\n", r->phone);
  printf("Skills: %s\n", r->skills);
  printf("Experiences: %s\n", r->experiences);
}

int main() {
  char *resume_text = "Name: John Smith\nEmail: johnsmith@gmail.com\nPhone: 123-456-7890\nSkills: C++, Java, Python\nExperiences: Worked on a team that developed a new mobile app";
  Resume *r = parse_resume(resume_text);

  if (r != NULL) {
    printf("Resume parsed successfully!\n");
    print_resume(r);
  }

  free(r);
  return 0;
}