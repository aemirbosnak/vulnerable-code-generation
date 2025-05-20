//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the resume information
struct Resume {
  char name[30];
  char skills[100];
  char experience[100];
  char education[100];
};

// Define a function that will parse the resume and return a Resume struct
struct Resume parseResume(char* resumeText) {
  struct Resume resume;

  // Use string manipulation functions such as strtok and strcpy to extract the relevant data from the resumeText string
  char *nameToken, *skillsToken, *experienceToken, *educationToken;
  nameToken = strtok(resumeText, "Name: ");
  skillsToken = strtok(NULL, "Skills: ");
  experienceToken = strtok(NULL, "Experience: ");
  educationToken = strtok(NULL, "Education: ");

  // Copy the extracted data into the resume struct
  strcpy(resume.name, nameToken);
  strcpy(resume.skills, skillsToken);
  strcpy(resume.experience, experienceToken);
  strcpy(resume.education, educationToken);

  // Return the completed resume struct
  return resume;
}

// Define a function that will print out the information in the Resume struct
void printResume(struct Resume resume) {
  printf("Name: %s\n", resume.name);
  printf("Skills: %s\n", resume.skills);
  printf("Experience: %s\n", resume.experience);
  printf("Education: %s\n", resume.education);
}

int main() {
  // Define a sample resume text string
  char* sampleResume = 
    "Name: John Doe\n"
    "Skills: C++, Java, Python\n"
    "Experience: Software Developer at XYZ Corp\n"
    "Education: Bachelor's Degree in Computer Science";

  // Parse the sample resume text
  struct Resume parsedResume = parseResume(sampleResume);

  // Print out the parsed resume information
  printf("Parsed Resume Information:\n");
  printResume(parsedResume);

  return 0;
}