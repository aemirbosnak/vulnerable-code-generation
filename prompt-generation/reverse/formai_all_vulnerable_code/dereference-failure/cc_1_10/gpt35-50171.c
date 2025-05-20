//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
  char name[50];
  char email[50];
  char phone[20];
  char address[100];
  char skills[200];
  char experience[1000];
  char education[500];
};

void parse_resume(FILE* file) {
  struct resume res;
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);
  char* buffer = (char*)malloc(file_size);
  fread(buffer, 1, file_size, file);
  char* token = strtok(buffer, "\n");
  while (token != NULL) {
    if (strstr(token, "Name")) {
      sscanf(token, "Name: %s", res.name);
    }
    else if (strstr(token, "Email")) {
      sscanf(token, "Email: %s", res.email);
    }
    else if (strstr(token, "Phone")) {
      sscanf(token, "Phone: %s", res.phone);
    }
    else if (strstr(token, "Address")) {
      sscanf(token, "Address: %s", res.address);
    }
    else if (strstr(token, "Skills")) {
      sscanf(token, "Skills: %s", res.skills);
    }
    else if (strstr(token, "Experience")) {
      sscanf(token, "Experience: %s", res.experience);
    }
    else if (strstr(token, "Education")) {
      sscanf(token, "Education: %s", res.education);
    }
    token = strtok(NULL, "\n");
  }
  printf("Name: %s\n", res.name);
  printf("Email: %s\n", res.email);
  printf("Phone: %s\n", res.phone);
  printf("Address: %s\n", res.address);
  printf("Skills: %s\n", res.skills);
  printf("Experience: %s\n", res.experience);
  printf("Education: %s\n", res.education);
  free(buffer);
}

int main() {
  FILE* file = fopen("resume.txt", "r");
  if (file == NULL) {
    printf("Failed to open file\n");
    return 1;
  }
  parse_resume(file);
  fclose(file);
  return 0;
}