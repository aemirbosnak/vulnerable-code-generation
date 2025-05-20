//FormAI DATASET v1.0 Category: System process viewer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <pwd.h>

#define PROCESS_NAME_LEN 256
#define CMDLINE_MAX_LEN 2048

int main() {
  DIR *proc;
  struct dirent *entry;
  char pid[16], process_name[PROCESS_NAME_LEN], cmdline[CMDLINE_MAX_LEN], uid[16];
  char path[256];
  FILE *fp;
  struct passwd *user_info;
  
  printf("PID\t Name\t UID \t Command\n");
  printf("-----------------------------------------------------\n");
  
  if ((proc = opendir("/proc")) == NULL) {
    perror("opendir() failed");
    exit(EXIT_FAILURE);
  }
  
  while ((entry = readdir(proc)) != NULL) {
    if (!isdigit(*entry->d_name)) {
      continue;
    }
    
    strcpy(pid, entry->d_name);
    strcpy(path, "/proc/");
    strcat(path, pid);
    strcat(path, "/cmdline");

    if ((fp = fopen(path, "r")) == NULL) {
      printf("Error: cannot open file %s\n", path);
      continue;
    }
    fgets(cmdline, CMDLINE_MAX_LEN, fp);
    fclose(fp);

    if (cmdline[0] == '\0') {
      continue;
    }

    snprintf(path, 256, "/proc/%s/status", pid);

    if ((fp = fopen(path, "r")) == NULL) {
      printf("Error: cannot open file %s\n", path);
      continue;
    }

    while (fgets(path, 256, fp) != NULL) {
      if (strncmp(path, "Name:", 5) == 0) {
        sscanf(path + 5, "%s", process_name);
      }
      else if (strncmp(path, "Uid:", 4) == 0) {
        sscanf(path + 4, "%s", uid);
      }
    }
    fclose(fp);

    user_info = getpwuid(atoi(uid));

    printf("%s\t %-15s %s\t %s\n", pid, process_name, user_info->pw_name, cmdline);
  }

  closedir(proc);
  exit(EXIT_SUCCESS);
}