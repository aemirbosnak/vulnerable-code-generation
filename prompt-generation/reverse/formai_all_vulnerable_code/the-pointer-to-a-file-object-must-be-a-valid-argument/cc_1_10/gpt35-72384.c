//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct for holding resume information
typedef struct Resume {
  char name[50];
  char email[50];
  char phone[20];
  char address[100];
  char education[100];
  char skills[200];
  char experience[500];
} Resume;

// function to parse resume and fill in the struct
Resume parse_resume(char* filename) {
  Resume resume;
  char line[200];

  // open the file and read the contents line by line
  FILE* fp = fopen(filename, "r");
  while(fgets(line, 200, fp) != NULL) {
    // extract the name, email, phone, address, education, skills, and experience fields from the resume
    if(strstr(line, "Name:")) {
      sscanf(line, "Name: %s", resume.name);
    } else if(strstr(line, "Email:")) {
      sscanf(line, "Email: %s", resume.email);
    } else if(strstr(line, "Phone:")) {
      sscanf(line, "Phone: %s", resume.phone);
    } else if(strstr(line, "Address:")) {
      sscanf(line, "Address: %s", resume.address);
    } else if(strstr(line, "Education:")) {
      sscanf(line, "Education: %s", resume.education);
    } else if(strstr(line, "Skills:")) {
      sscanf(line, "Skills: %s", resume.skills);
    } else if(strstr(line, "Experience:")) {
      sscanf(line, "Experience: %s", resume.experience);
    }
  }
  fclose(fp);

  return resume;
}

// main function
int main() {
  // input a filename from the user
  char filename[50];
  printf("Enter the filename of the resume to parse: ");
  scanf("%s", filename);

  // parse the resume and fill in the struct
  Resume resume = parse_resume(filename);

  // print out the fields of the resume
  printf("\nName: %s\n", resume.name);
  printf("Email: %s\n", resume.email);
  printf("Phone: %s\n", resume.phone);
  printf("Address: %s\n", resume.address);
  printf("Education: %s\n", resume.education);
  printf("Skills: %s\n", resume.skills);
  printf("Experience: %s\n", resume.experience);

  return 0;
}