//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#define PROC_DIR "/proc"
#define BUFSIZE 4096

int main(void) {
  // Let's dive into the vibrant realm of processes!

  // Open the /proc directory, a bustling hub of process information
  DIR *procdir = opendir(PROC_DIR);
  if (procdir == NULL) {
    perror("Error opening /proc directory");
    return EXIT_FAILURE;
  }

  // Get ready to explore each process like an intrepid adventurer
  struct dirent *entry;
  while ((entry = readdir(procdir)) != NULL) {
    // Check if the entry is a directory representing a process
    if (!strcmp(entry->d_type, "4")) {
      // Prepare to unleash the might of a process viewer
      char path[BUFSIZE];
      snprintf(path, BUFSIZE, "%s/%s", PROC_DIR, entry->d_name);

      // Open the process's status file, a treasure trove of information
      FILE *status = fopen(path, "r");
      if (status == NULL) {
        perror("Error opening process status file");
        continue;
      }

      // Let's gather the vital statistics of this process
      char name[BUFSIZE];
      char state;
      int ppid;
      unsigned int pid;
      fscanf(status, "Name:\t%s\n", name);
      fscanf(status, "State:\t%c\n", &state);
      fscanf(status, "PPid:\t%d\n", &ppid);
      fscanf(status, "Pid:\t%u\n", &pid);

      // Close the status file, letting go of its precious data
      fclose(status);

      // Print out the process's details with style and verve
      printf("Behold, the process named '%s' (%u)!\n", name, pid);
      printf("State: %c, a testament to its current status\n", state);
      printf("Parent Process: %d, a legacy it carries\n", ppid);
      puts("-------------------------------------------------");
    }
  }

  // Close the /proc directory, bidding farewell to the process realm
  closedir(procdir);

  return EXIT_SUCCESS;
}