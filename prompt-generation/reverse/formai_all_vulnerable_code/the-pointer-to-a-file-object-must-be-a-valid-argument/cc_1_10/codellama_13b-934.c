//Code Llama-13B DATASET v1.0 Category: Resume Parsing System ; Style: artistic
// Resume Parsing System
#include <stdio.h>
#include <string.h>

// Struct to store resume data
struct Resume {
  char name[50];
  char email[50];
  char phone[20];
  char address[100];
  char experience[100];
  char education[100];
  char skills[100];
};

// Function to read resume data from file
void readResume(FILE *fp, struct Resume *resume) {
  char line[100];
  while (fgets(line, sizeof(line), fp) != NULL) {
    if (strstr(line, "Name:") != NULL) {
      strcpy(resume->name, line);
    } else if (strstr(line, "Email:") != NULL) {
      strcpy(resume->email, line);
    } else if (strstr(line, "Phone:") != NULL) {
      strcpy(resume->phone, line);
    } else if (strstr(line, "Address:") != NULL) {
      strcpy(resume->address, line);
    } else if (strstr(line, "Experience:") != NULL) {
      strcpy(resume->experience, line);
    } else if (strstr(line, "Education:") != NULL) {
      strcpy(resume->education, line);
    } else if (strstr(line, "Skills:") != NULL) {
      strcpy(resume->skills, line);
    }
  }
}

// Function to print resume data
void printResume(struct Resume resume) {
  printf("Name: %s\n", resume.name);
  printf("Email: %s\n", resume.email);
  printf("Phone: %s\n", resume.phone);
  printf("Address: %s\n", resume.address);
  printf("Experience: %s\n", resume.experience);
  printf("Education: %s\n", resume.education);
  printf("Skills: %s\n", resume.skills);
}

int main() {
  // Open resume file
  FILE *fp = fopen("resume.txt", "r");

  // Create resume structure
  struct Resume resume;

  // Read resume data from file
  readResume(fp, &resume);

  // Print resume data
  printResume(resume);

  // Close resume file
  fclose(fp);

  return 0;
}