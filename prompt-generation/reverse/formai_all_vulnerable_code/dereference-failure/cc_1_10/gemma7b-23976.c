//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct resume_entry {
  char name[MAX_NAME_LENGTH];
  char email[MAX_NAME_LENGTH];
  char phone[MAX_NAME_LENGTH];
  char summary[MAX_NAME_LENGTH];
} resume_entry;

resume_entry *parse_resume(char *resume_text)
{
  resume_entry *entry = malloc(sizeof(resume_entry));

  // Extract name, email, phone, and summary from the resume text
  char *name = strstr(resume_text, "Name:");
  char *email = strstr(resume_text, "Email:");
  char *phone = strstr(resume_text, "Phone:");
  char *summary = strstr(resume_text, "Summary:");

  // If the elements are found, assign them to the entry
  if (name && email && phone && summary) {
    strcpy(entry->name, name);
    strcpy(entry->email, email);
    strcpy(entry->phone, phone);
    strcpy(entry->summary, summary);
  } else {
    free(entry);
    return NULL;
  }

  return entry;
}

int main()
{
  char *resume_text = "Name: John Doe\nEmail: john.doe@example.com\nPhone: 123-456-7890\nSummary: Experienced software engineer with a strong background in C programming.\n";

  resume_entry *entry = parse_resume(resume_text);

  if (entry) {
    printf("Name: %s\n", entry->name);
    printf("Email: %s\n", entry->email);
    printf("Phone: %s\n", entry->phone);
    printf("Summary: %s\n", entry->summary);

    free(entry);
  } else {
    printf("Error parsing resume.\n");
  }

  return 0;
}