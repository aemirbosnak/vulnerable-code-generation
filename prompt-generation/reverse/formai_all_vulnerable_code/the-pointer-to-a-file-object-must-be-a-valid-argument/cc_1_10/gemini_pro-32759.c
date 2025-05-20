//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

int main() {
  // Unleash the system's secrets!
  pid_t pid;
  struct stat st;
  struct passwd *pw;
  struct group *gr;
  char buf[256];

  // Charge into the realm of processes
  printf("\n** Process Explorer **\n", pid);
  printf("--------------------------------------\n");
  printf("   PID    NAME    USER   GROUP   SIZE  STAT\n");
  printf("--------------------------------------\n");

  // Scan through the process jungle
  FILE *fp = fopen("/proc", "r");
  while (fgets(buf, sizeof(buf), fp)) {
    // Isolate the process ID
    pid = strtol(buf, NULL, 10);
    if (pid <= 0) continue;

    // Sneak into the process's lair
    sprintf(buf, "/proc/%d/stat", pid);
    FILE *stat_file = fopen(buf, "r");
    if (!stat_file) continue;

    // Extract the process's name
    char name[256];
    fscanf(stat_file, "%*d %s%*s", name);
    fclose(stat_file);

    // Snoop on the process's file system footprint
    sprintf(buf, "/proc/%d/cwd", pid);
    lstat(buf, &st);

    // Identify the process's owner and group
    pw = getpwuid(st.st_uid);
    gr = getgrgid(st.st_gid);

    // Format the process information
    printf("%6d  %-10s  %-6s  %-6s  %7ld  %s\n",
      pid, name, pw->pw_name, gr->gr_name, st.st_size,
      st.st_mode & S_IFDIR ? "dir" : "file");
  }
  fclose(fp);

  // Triumphant exit
  printf("\n--------------------------------------\n");
  printf("Process Explorer: Mission Accomplished!\n");
  return 0;
}