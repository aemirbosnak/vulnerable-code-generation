//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: genius
#include <stdio.h>
#include <string.h>

typedef struct resume_entry {
  char name[256];
  char email[256];
  char phone[256];
  char address[256];
  char summary[256];
} resume_entry;

int main() {
  resume_entry resume_list[100];
  int resume_count = 0;

  // Parse resume file
  FILE* resume_file = fopen("resume.txt", "r");
  if (resume_file) {
    char line[256];
    while (fgets(line, 256, resume_file) != NULL) {
      // Extract resume data
      char* name = strstr(line, "Name:");
      char* email = strstr(line, "Email:");
      char* phone = strstr(line, "Phone:");
      char* address = strstr(line, "Address:");
      char* summary = strstr(line, "Summary:");

      // Create a new resume entry
      resume_entry new_entry;
      strcpy(new_entry.name, name);
      strcpy(new_entry.email, email);
      strcpy(new_entry.phone, phone);
      strcpy(new_entry.address, address);
      strcpy(new_entry.summary, summary);

      // Add the new entry to the list
      resume_list[resume_count++] = new_entry;
    }
    fclose(resume_file);
  }

  // Print the list of resume entries
  for (int i = 0; i < resume_count; i++) {
    printf("%s\n", resume_list[i].name);
    printf("%s\n", resume_list[i].email);
    printf("%s\n", resume_list[i].phone);
    printf("%s\n", resume_list[i].address);
    printf("%s\n", resume_list[i].summary);
  }

  return 0;
}