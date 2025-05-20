//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definitions for Virus Types
#define VIRUS_UNKNOWN 0
#define VIRUS_W32_VB 1
#define VIRUS_W32_SILVER 2
#define VIRUS_W32_SALMONELLA 3
#define VIRUS_W32_MYDOOM 4
#define VIRUS_W32_MALICIOUS 5

// Virus Signature table
char virus_signatures[6][4] = {
  "W32VB",
  "W32SILVER",
  "W32SALMONELLA",
  "W32MYDOOM",
  "W32MALICIOUS",
  "UNKNOWN"
};

// Virus Scanner function
int scan_file(FILE *file) {
  char line[100];
  int virus_type = VIRUS_UNKNOWN;
  int virus_match = 0;

  // Read file line by line
  while (fgets(line, sizeof(line), file)!= NULL) {
    // Check for virus signature in each line
    for (int i = 0; i < 6; i++) {
      if (strstr(line, virus_signatures[i])) {
        virus_match = 1;
        virus_type = i;
        break;
      }
    }

    // Check for another virus signature in each line
    if (virus_match == 0) {
      for (int i = 0; i < 6; i++) {
        if (strstr(line, virus_signatures[i])) {
          virus_match = 1;
          virus_type = i;
          break;
        }
      }
    }
  }

  // Return virus type
  return virus_type;
}

int main() {
  FILE *file = fopen("virus_sample.txt", "r");
  if (file == NULL) {
    printf("Failed to open file");
    return 1;
  }

  int virus_type = scan_file(file);
  fclose(file);

  if (virus_type == VIRUS_UNKNOWN) {
    printf("No virus found\n");
  } else if (virus_type == VIRUS_W32_VB) {
    printf("Virus detected: W32_VB\n");
  } else if (virus_type == VIRUS_W32_SILVER) {
    printf("Virus detected: W32_SILVER\n");
  } else if (virus_type == VIRUS_W32_SALMONELLA) {
    printf("Virus detected: W32_SALMONELLA\n");
  } else if (virus_type == VIRUS_W32_MYDOOM) {
    printf("Virus detected: W32_MYDOOM\n");
  } else if (virus_type == VIRUS_W32_MALICIOUS) {
    printf("Virus detected: W32_MALICIOUS\n");
  } else {
    printf("Unknown virus detected\n");
  }

  return 0;
}