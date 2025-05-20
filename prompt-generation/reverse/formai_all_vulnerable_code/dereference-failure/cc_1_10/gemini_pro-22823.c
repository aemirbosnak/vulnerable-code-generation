//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

void print_proc_info(pid_t pid) {
  char proc_path[64];
  snprintf(proc_path, sizeof(proc_path), "/proc/%ld", pid);

  char *argv0 = NULL;
  char *cwd = NULL;
  char *exe = NULL;

  // Get the process name.
  FILE *cmdline = fopen(strcat(proc_path, "/cmdline"), "r");
  if (cmdline) {
    size_t len = 0;
    getline(&argv0, &len, cmdline);
    fclose(cmdline);
  }

  // Get the current working directory.
  cwd = malloc(PATH_MAX);
  if (cwd) {
    readlink(strcat(proc_path, "/cwd"), cwd, PATH_MAX);
  }

  // Get the executable path.
  exe = malloc(PATH_MAX);
  if (exe) {
    readlink(strcat(proc_path, "/exe"), exe, PATH_MAX);
  }

  // Get the process user and group.
  struct stat st;
  stat(proc_path, &st);
  struct passwd *user = getpwuid(st.st_uid);
  struct group *group = getgrgid(st.st_gid);

  // Print the process information.
  printf("  '- %s (%ld) [user: %s, group: %s, cwd: %s, exe: %s]\n",
      argv0, pid,
      user->pw_name, group->gr_name, cwd, exe);

  // Free the allocated memory.
  free(cwd);
  free(exe);
  free(argv0);
}

int main(void) {
  DIR *procdir = opendir("/proc");
  if (procdir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  // Iterate over all the processes in /proc.
  struct dirent *proc;
  while ((proc = readdir(procdir)) != NULL) {
    // Check if the directory is a number (a process ID).
    char *endptr;
    long pid = strtol(proc->d_name, &endptr, 10);
    if (*endptr != '\0') {
      continue;
    }

    // Print the process information.
    print_proc_info(pid);
  }

  closedir(procdir);

  return EXIT_SUCCESS;
}