//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 100

// Radiation-proofed resume parsing system.
int main() {
  // Initialize the scavenger team.
  char scavengers[MAX_LINES][MAX_LINE_LENGTH];
  int num_scavengers = 0;

  // Scan the wasteland for resumes.
  FILE *file = fopen("resumes.txt", "r");
  if (!file) {
    printf("No resumes found in the wasteland.\n");
    return 1;
  }

  // Parse each resume.
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, file)) {
    // Skip empty lines and comments.
    if (strlen(line) == 0 || line[0] == '#') {
      continue;
    }

    // Extract the scavenger's name and skills.
    char *name = strtok(line, ",");
    char *skills = strtok(NULL, "\n");

    // Add the scavenger to the team.
    strcpy(scavengers[num_scavengers], name);
    strcpy(scavengers[num_scavengers] + strlen(name), skills);
    num_scavengers++;
  }
  fclose(file);

  // Print the list of scavengers.
  printf("Scavenger Team:\n");
  for (int i = 0; i < num_scavengers; i++) {
    printf("%s\n", scavengers[i]);
  }

  // Find the best scavenger for the job.
  int best_scavenger = -1;
  int best_skills = 0;
  for (int i = 0; i < num_scavengers; i++) {
    int num_skills = 0;
    char *skill = strtok(scavengers[i] + strlen(scavengers[i]), ",");
    while (skill) {
      num_skills++;
      skill = strtok(NULL, ",");
    }
    if (num_skills > best_skills) {
      best_scavenger = i;
      best_skills = num_skills;
    }
  }

  // Assign the best scavenger to the job.
  printf("Best Scavenger: %s\n", scavengers[best_scavenger]);

  return 0;
}