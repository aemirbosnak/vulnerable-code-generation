//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: brave
#include <stdio.h>
#include <string.h>

// Define a struct for storing resume details
struct Resume {
  char name[50];
  char email[50];
  char phone[15];
  char address[100];
  char skills[1000];
  char experience[2000];
};

// Define a function to parse the resume
void parseResume(char* filePath) {
  // Open the file
  FILE *fptr;
  fptr = fopen(filePath, "r");

  // Define variables to store resume details
  char name[50], email[50], phone[15], address[100], skills[1000], experience[2000];
  int count = 0;

  // Read the file line-by-line
  char line[1000];
  while (fgets(line, sizeof line, fptr) != NULL) {
    // Check for resume details
    if (strstr(line, "Name:")) {
      sscanf(line, "%*s %[^\n]", name);
      count++;
    }
    else if (strstr(line, "Email:")) {
      sscanf(line, "%*s %[^\n]", email);
      count++;
    }
    else if (strstr(line, "Phone:")) {
      sscanf(line, "%*s %[^\n]", phone);
      count++;
    }
    else if (strstr(line, "Address:")) {
      sscanf(line, "%*s %[^\n]", address);
      count++;
    }
    else if (strstr(line, "Skills:")) {
      sscanf(line, "%*s %[^\n]", skills);
      count++;
    }
    else if (strstr(line, "Experience:")) {
      sscanf(line, "%*s %[^\n]", experience);
      count++;
    }
  }

  // Close the file
  fclose(fptr);

  // Print the parsed resume details
  if (count == 6) {
    struct Resume r;
    strcpy(r.name, name);
    strcpy(r.email, email);
    strcpy(r.phone, phone);
    strcpy(r.address, address);
    strcpy(r.skills, skills);
    strcpy(r.experience, experience);

    printf("Name: %s\n", r.name);
    printf("Email: %s\n", r.email);
    printf("Phone: %s\n", r.phone);
    printf("Address: %s\n", r.address);
    printf("Skills: %s\n", r.skills);
    printf("Experience: %s\n", r.experience);
  }
  else {
    printf("Error parsing resume. Please check the format.\n");
  }
}

int main() {
  // Parse the sample resume file
  parseResume("sample_resume.txt");

  return 0;
}