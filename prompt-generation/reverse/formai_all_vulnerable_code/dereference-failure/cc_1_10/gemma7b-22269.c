//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

struct resume_t {
  char name[MAX_NAME_LENGTH];
  char address[MAX_NAME_LENGTH];
  char phone_number[MAX_NAME_LENGTH];
  char email_address[MAX_NAME_LENGTH];
  char summary[MAX_NAME_LENGTH];
  struct resume_t* next;
};

void parse_resume(char* resume_text) {
  struct resume_t* head = NULL;
  struct resume_t* current = NULL;

  // Split the resume text into sections
  char* sections[] = {"Name:", "Address:", "Phone Number:", "Email Address:", "Summary:"};
  int num_sections = sizeof(sections) / sizeof(char*);

  // Iterate over the sections
  for (int i = 0; i < num_sections; i++) {
    char* section_start = strstr(resume_text, sections[i]);

    // Extract the data for each section
    switch (i) {
      case 0:
        current = malloc(sizeof(struct resume_t));
        strcpy(current->name, section_start + strlen(sections[i]) + 1);
        break;
      case 1:
        strcpy(current->address, section_start + strlen(sections[i]) + 1);
        break;
      case 2:
        strcpy(current->phone_number, section_start + strlen(sections[i]) + 1);
        break;
      case 3:
        strcpy(current->email_address, section_start + strlen(sections[i]) + 1);
        break;
      case 4:
        strcpy(current->summary, section_start + strlen(sections[i]) + 1);
        break;
    }

    // Add the current resume entry to the list
    if (head == NULL) {
      head = current;
    } else {
      current->next = head;
      head = current;
    }
  }

  // Print the parsed resume data
  struct resume_t* temp = head;
  while (temp) {
    printf("Name: %s\n", temp->name);
    printf("Address: %s\n", temp->address);
    printf("Phone Number: %s\n", temp->phone_number);
    printf("Email Address: %s\n", temp->email_address);
    printf("Summary: %s\n", temp->summary);
    printf("\n");
    temp = temp->next;
  }
}

int main() {
  char* resume_text = "Name: John Doe\nAddress: 123 Main St., New York, NY 10001\nPhone Number: (555) 123-4567\nEmail Address: john.doe@example.com\nSummary: Experienced software engineer with a strong background in Java and C++.";

  parse_resume(resume_text);

  return 0;
}