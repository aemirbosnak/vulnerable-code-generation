//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

// A mischievous little function to spy on the secrets of other processes
void peekaboo(pid_t pid) {
  // Prepare a secret potion to cast a spell on the process
  struct sysinfo info;
  if (sysinfo(&info) < 0) {
    perror("Oops, the potion failed!");
    return;
  }

  // Cast the spell and gather the process's vital statistics
  FILE *file;
  char path[256];
  snprintf(path, sizeof(path), "/proc/%d/status", pid);
  file = fopen(path, "r");
  if (file == NULL) {
    perror("Hmm, the process seems to be hiding!");
    return;
  }

  // Decipher the process's secrets
  char line[1024];
  while (fgets(line, sizeof(line), file) != NULL) {
    // Name: PID
    if (strstr(line, "Name:") != NULL) {
      printf("Its name is %s", line + 6);
    }
    // State: S
    else if (strstr(line, "State:") != NULL) {
      printf("Its state is %s", line + 7);
    }
    // Threads: 1
    else if (strstr(line, "Threads:") != NULL) {
      printf("It has %d threads\n", atoi(line + 9));
    }
    // VmSize: 1024 kB
    else if (strstr(line, "VmSize:") != NULL) {
      printf("Its memory size is %ld kB\n", info.mem_unit * atoi(line + 8));
    }
  }
  fclose(file);
}

int main(int argc, char *argv[]) {
  // If no arguments are given, let's spy on our own secrets
  if (argc == 1) {
    peekaboo(getpid());
  }
  // Otherwise, let's spy on a specific process
  else {
    pid_t pid = atoi(argv[1]);
    peekaboo(pid);
  }

  return 0;
}