//FormAI DATASET v1.0 Category: System process viewer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
  DIR *dir;
  struct dirent *ent;
  char status[1024];

  // Open the proc directory for reading
  if ((dir = opendir("/proc")) != NULL) {
    
    // Iterate over all the process directories in /proc
    while ((ent = readdir(dir)) != NULL) {
      // If the directory name isn't a number, skip it
      if (atoi(ent->d_name) == 0)
        continue;
      
      // Read the status file for this process to get its name and status
      FILE *fp;
      char path[1024];
      sprintf(path, "/proc/%s/status", ent->d_name);
      fp = fopen(path, "r");
      
      // If the status file couldn't be opened, skip this process
      if (fp == NULL)
        continue;
      
      // Read the status file line by line
      while (fgets(status, sizeof(status), fp) != NULL) {
        // Find the line that contains the process' name
        if (strncmp(status, "Name:", 5) == 0) {
          printf("Process Name: %s", &status[6]);
          break;
        }
      }

      // Close the status file
      fclose(fp);

      // Print the process' ID
      printf("Process ID: %s\n", ent->d_name);
    }
    
    // Close the proc directory
    closedir(dir);
    
  } else {
    // The proc directory couldn't be opened, so the program can't continue
    printf("Unable to open /proc directory\n");
    return 1;
  }

  return 0;
}