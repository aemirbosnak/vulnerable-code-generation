//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_NAME_LENGTH 50
#define MAX_SKILL_LENGTH 100
#define MAX_EXPERIENCE_LENGTH 200

// Struct for storing resume information
typedef struct {
  char name[MAX_NAME_LENGTH];
  char skills[MAX_SKILL_LENGTH][10];
  char experiences[MAX_EXPERIENCE_LENGTH][5];
} ResumeInfo;

int main(int argc, char *argv[]) {
  int fd;
  ResumeInfo *resume;

  // Check for correct number of arguments
  if (argc != 2) {
    printf("Error: Please provide a resume file as an argument.\n");
    exit(1);
  }

  // Open resume file for reading
  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("Error opening resume file.");
    exit(1);
  }

  // Allocate memory for resume information
  resume = (ResumeInfo *) malloc(sizeof(ResumeInfo));
  if (resume == NULL) {
    perror("Error allocating memory for resume information.");
    close(fd);
    exit(1);
  }

  // Read name from resume file
  read(fd, resume->name, MAX_NAME_LENGTH);
  read(fd, "\n", 1); // Read newline character after name

  // Read skills from resume file
  printf("Reading skills...\n");
  for (int i = 0; i < 10 && read(fd, resume->skills[i], MAX_SKILL_LENGTH) > 0; i++) {
    read(fd, "\n", 1); // Read newline character after each skill
  }

  // Read experiences from resume file
  printf("Reading experiences...\n");
  for (int i = 0; i < 5 && read(fd, resume->experiences[i], MAX_EXPERIENCE_LENGTH) > 0; i++) {
    read(fd, "\n", 1); // Read newline character after each experience
  }

  // Print resume information
  printf("\nName: %s\n", resume->name);
  printf("Skills:\n");
  for (int i = 0; i < 10; i++) {
    printf("- %s\n", resume->skills[i]);
  }
  printf("Experiences:\n");
  for (int i = 0; i < 5; i++) {
    printf("  %s\n", resume->experiences[i]);
  }

  // Free memory and close file
  free(resume);
  close(fd);

  return 0;
}

// Function to print error message and exit program
void die(const char *msg) {
  perror(msg);
  exit(1);
}