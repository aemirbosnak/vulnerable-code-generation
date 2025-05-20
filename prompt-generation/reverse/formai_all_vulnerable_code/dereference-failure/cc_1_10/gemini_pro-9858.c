//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
// Where hearts entwined like words on a page,
// A digital Romeo seeks to parse Juliet's stage.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// The words of her beloved, a textual maze,
struct Resume {
  char *name;
  char *education;
  char *skills;
  char *experience;
};

// A function to unveil the secrets of her name,
char *parseName(char *line) {
  char *name = malloc(strlen(line) + 1);
  strcpy(name, line);
  for (char *p = name; *p; p++) *p = tolower(*p);
  return name;
}

// Unraveling the tapestry of her education,
char *parseEducation(char *line) {
  char *education = malloc(strlen(line) + 1);
  strcpy(education, line);
  for (char *p = education; *p; p++) *p = tolower(*p);
  return education;
}

// The skills she possesses, a constellation bright,
char *parseSkills(char *line) {
  char *skills = malloc(strlen(line) + 1);
  strcpy(skills, line);
  for (char *p = skills; *p; p++) *p = tolower(*p);
  return skills;
}

// The journey of her experience, a path to behold,
char *parseExperience(char *line) {
  char *experience = malloc(strlen(line) + 1);
  strcpy(experience, line);
  for (char *p = experience; *p; p++) *p = tolower(*p);
  return experience;
}

// A function to create a digital representation of fair Juliet's CV,
struct Resume *parseResume(char *text) {
  struct Resume *resume = malloc(sizeof(struct Resume));
  resume->name = parseName(strtok(text, "\n"));
  resume->education = parseEducation(strtok(NULL, "\n"));
  resume->skills = parseSkills(strtok(NULL, "\n"));
  resume->experience = parseExperience(strtok(NULL, "\n"));
  return resume;
}

// A test to determine if Romeo's system can capture Juliet's essence,
int main() {
  char *text = "Juliet Capulet\nVerona High School\nSwift, Python, SQL\nInternship at Montague & Co.";
  struct Resume *resume = parseResume(text);

  printf("Name: %s\n", resume->name);
  printf("Education: %s\n", resume->education);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);

  return 0;
}