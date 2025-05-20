//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct gas_tank {
  char *driver;
  int fuel;
  struct gas_tank *next;
};

int main() {
  struct gas_tank *g = NULL;

  // Parse the resume
  char *line = NULL;
  size_t len = 0;
  while (getline(&line, &len, stdin) != -1) {
    line[strcspn(line, "\n")] = 0;  // Remove newline

    // Check if the line is a valid gas tank
    if (strlen(line) < 5 || strncmp(line, "TANK: ", 5) != 0) {
      fprintf(stderr, "Invalid TANK declaration: %s\n", line);
      continue;
    }

    // Extract the driver and fuel
    char *driver = strtok(line + 5, " ");
    char *fuel = strtok(NULL, " ");

    // Create a new gas tank
    struct gas_tank *new_tank = malloc(sizeof(struct gas_tank));
    new_tank->driver = strdup(driver);
    new_tank->fuel = atoi(fuel);
    new_tank->next = NULL;

    // Insert the new gas tank into the list
    if (g == NULL) {
      g = new_tank;
    } else {
      struct gas_tank *cur = g;
      while (cur->next != NULL) {
        cur = cur->next;
      }
      cur->next = new_tank;
    }
  }

  // Print the list of gas tanks
  printf("\n**Gas Tank Inventory**\n");
  struct gas_tank *cur = g;
  while (cur != NULL) {
    printf("Driver: %s, Fuel: %d\n", cur->driver, cur->fuel);
    cur = cur->next;
  }

  // Cleanup
  cur = g;
  while (cur != NULL) {
    struct gas_tank *next = cur->next;
    free(cur->driver);
    free(cur);
    cur = next;
  }
  free(line);

  return 0;
}