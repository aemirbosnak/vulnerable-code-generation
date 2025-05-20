//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: authentic
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main(int argc, char *argv[]) {
  struct sysinfo info;
  if (sysinfo(&info) != 0) {
    perror("sysinfo");
    return EXIT_FAILURE;
  }

  printf("System Information:\n");
  printf("  Total RAM: %lu MB\n", info.totalram / 1024 / 1024);
  printf("  Free RAM: %lu MB\n", info.freeram / 1024 / 1024);
  printf("  Processes Running: %lu\n", info.procs);
  printf("  Process Table Size: %lu\n", info.procs);
  printf("  Total Swap Space: %lu MB\n", info.totalswap / 1024 / 1024);
  printf("  Free Swap Space: %lu MB\n", info.freeswap / 1024 / 1024);
  printf("  Uptime: %lu seconds\n", info.uptime);

  if (argc == 2) {
    if (strcmp(argv[1], "-p") == 0) {
      printf("\nProcess List:\n");
      printf("  PID  PPID  C  STIME  TTY  TIME  CMD\n");
      pid_t pid = 1;
      while (pid != 0) {
        char path[256];
        snprintf(path, sizeof(path), "/proc/%d/status", pid);
        FILE *f = fopen(path, "r");
        if (f != NULL) {
          char line[1024];
          while (fgets(line, sizeof(line), f) != NULL) {
            if (strncmp(line, "Pid:", 4) == 0) {
              char name[64], state;
              long ppid, c, stime, tty, time;
              sscanf(line, "Pid: %d State: %c Name: %s", &pid, &state, name);
              fgets(line, sizeof(line), f);
              sscanf(line, "PPid: %ld", &ppid);
              fgets(line, sizeof(line), f);
              sscanf(line, "C: %ld", &c);
              fgets(line, sizeof(line), f);
              sscanf(line, "Stime: %ld", &stime);
              fgets(line, sizeof(line), f);
              sscanf(line, "TTY: %ld", &tty);
              fgets(line, sizeof(line), f);
              sscanf(line, "Time: %ld", &time);
              printf("  %d  %d  %ld  %ld  %ld  %ld  %s", pid, ppid, c, stime, tty, time, name);
              break;
            }
          }
          fclose(f);
        }
        pid++;
      }
    }
  }

  return EXIT_SUCCESS;
}