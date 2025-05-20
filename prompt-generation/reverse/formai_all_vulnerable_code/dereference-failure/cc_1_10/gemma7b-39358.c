//Gemma-7B DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 256

typedef struct Resume {
  char name[MAX_NAME_LENGTH];
  char email[MAX_NAME_LENGTH];
  char phone[MAX_NAME_LENGTH];
  char address[MAX_NAME_LENGTH];
  char summary[MAX_NAME_LENGTH];
  struct Resume* next;
} Resume;

Resume* parse_resume(char* file_path) {
  FILE* file = fopen(file_path, "r");
  if (file == NULL) {
    return NULL;
  }

  Resume* head = NULL;
  Resume* current = NULL;

  char line[MAX_NAME_LENGTH];
  while (fgets(line, MAX_NAME_LENGTH, file) != NULL) {
    // Extract name, email, phone, and address
    char* name = strstr(line, "Name:");
    char* email = strstr(line, "Email:");
    char* phone = strstr(line, "Phone:");
    char* address = strstr(line, "Address:");

    // Create a new resume node
    Resume* new_resume = malloc(sizeof(Resume));
    new_resume->name[0] = '\0';
    new_resume->email[0] = '\0';
    new_resume->phone[0] = '\0';
    new_resume->address[0] = '\0';
    new_resume->summary[0] = '\0';
    new_resume->next = NULL;

    // Populate the node with data
    if (name) {
      strncpy(new_resume->name, name + 5, MAX_NAME_LENGTH - 1);
    }
    if (email) {
      strncpy(new_resume->email, email + 6, MAX_NAME_LENGTH - 1);
    }
    if (phone) {
      strncpy(new_resume->phone, phone + 7, MAX_NAME_LENGTH - 1);
    }
    if (address) {
      strncpy(new_resume->address, address + 8, MAX_NAME_LENGTH - 1);
    }

    // Add the node to the list
    if (current) {
      current->next = new_resume;
    } else {
      head = new_resume;
    }

    current = new_resume;
  }

  fclose(file);
  return head;
}

int main() {
  char* file_path = "resume.txt";
  Resume* head = parse_resume(file_path);

  // Print the resume data
  for (Resume* current = head; current; current = current->next) {
    printf("Name: %s\n", current->name);
    printf("Email: %s\n", current->email);
    printf("Phone: %s\n", current->phone);
    printf("Address: %s\n", current->address);
    printf("Summary: %s\n", current->summary);
    printf("\n");
  }

  return 0;
}