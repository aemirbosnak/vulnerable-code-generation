//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <pwd.h>
#include <dirent.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

// Process structure
typedef struct process {
  int pid;
  char *name;
  char state;
  int ppid;
  int priority;
  long rss;
  long vsize;
  time_t time;
} process;

// Compare function for qsort
int compare_processes(const void *a, const void *b) {
  const process *p1 = (const process *)a;
  const process *p2 = (const process *)b;

  return strcmp(p1->name, p2->name);
}

// Get process information
int get_process_info(process *p, int pid) {
  char path[PATH_MAX];
  char line[1024];
  FILE *fp;

  // Get process path
  snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);
  fp = fopen(path, "r");
  if (fp == NULL) {
    return -1;
  }
  fgets(line, sizeof(line), fp);
  fclose(fp);

  // Parse process name
  p->name = strdup(line);

  // Get process state
  snprintf(path, sizeof(path), "/proc/%d/status", pid);
  fp = fopen(path, "r");
  if (fp == NULL) {
    return -1;
  }
  while (fgets(line, sizeof(line), fp) != NULL) {
    if (strncmp(line, "State:", 6) == 0) {
      p->state = line[7];
      break;
    }
  }
  fclose(fp);

  // Get process parent ID
  p->ppid = getppid();

  // Get process priority
  snprintf(path, sizeof(path), "/proc/%d/sched", pid);
  fp = fopen(path, "r");
  if (fp == NULL) {
    return -1;
  }
  while (fgets(line, sizeof(line), fp) != NULL) {
    if (strncmp(line, "priority:", 9) == 0) {
      p->priority = atoi(line + 9);
      break;
    }
  }
  fclose(fp);

  // Get process RSS
  snprintf(path, sizeof(path), "/proc/%d/statm", pid);
  fp = fopen(path, "r");
  if (fp == NULL) {
    return -1;
  }
  fscanf(fp, "%ld", &p->rss);
  fclose(fp);

  // Get process virtual size
  snprintf(path, sizeof(path), "/proc/%d/stat", pid);
  fp = fopen(path, "r");
  if (fp == NULL) {
    return -1;
  }
  fscanf(fp, "%*d %*s %*s %*d %*d %*d %*d %*d %*d %*d %*d %ld", &p->vsize);
  fclose(fp);

  // Get process start time
  p->time = time(NULL);

  return 0;
}

// Print process information
void print_process(const process *p) {
  printf("%-5d %-15s %c %5d %3d %6ld %6ld %s",
    p->pid, p->name, p->state, p->ppid, p->priority, p->rss, p->vsize, ctime(&p->time));
}

// Main function
int main(void) {
  // Get system information
  struct utsname u;
  uname(&u);

  // Get current user
  struct passwd *pw = getpwuid(getuid());

  // Get processes
  DIR *dir;
  struct dirent *de;
  process *processes = NULL;
  int num_processes = 0;

  dir = opendir("/proc");
  if (dir == NULL) {
    perror("opendir");
    exit(EXIT_FAILURE);
  }

  while ((de = readdir(dir)) != NULL) {
    if (atoi(de->d_name) > 0) {
      num_processes++;
      processes = realloc(processes, num_processes * sizeof(process));
      get_process_info(&processes[num_processes - 1], atoi(de->d_name));
    }
  }

  closedir(dir);

  // Sort processes by name
  qsort(processes, num_processes, sizeof(process), compare_processes);

  // Print system information
  printf("System: %s\n", u.sysname);
  printf("Release: %s\n", u.release);
  printf("Version: %s\n", u.version);
  printf("Machine: %s\n", u.machine);
  printf("User: %s\n", pw->pw_name);
  printf("Home: %s\n", pw->pw_dir);

  // Print process header
  printf("\nPID   NAME     STATE  PPID PRI RSS VSIZE  TIME\n");

  // Print processes
  for (int i = 0; i < num_processes; i++) {
    print_process(&processes[i]);
  }

  // Free processes
  for (int i = 0; i < num_processes; i++) {
    free(processes[i].name);
  }
  free(processes);

  return EXIT_SUCCESS;
}