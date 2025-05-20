//FormAI DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

#define PROC_PATH "/proc/"

struct Task {
  pid_t pid;
  uid_t uid;
  char *username;
  char cmdline[BUFSIZ];
};

void print_header() {
  printf("%-7s %-10s %-30s\n", "PID", "UID", "CMDLINE");
}

void print_task(struct Task *t) {
  printf("%-7d %-10d %-30s\n", t->pid, t->uid, t->cmdline);
}

char *get_username(uid_t uid) {
  struct passwd *pw = getpwuid(uid);
  if (pw != NULL) {
    return pw->pw_name;
  } else {
    return "-";
  }
}

int is_number(const char *s) {
  for (size_t i = 0; i < strlen(s); ++i) {
    if (!isdigit(s[i])) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {
  if (argc != 1 && argc != 2) {
    printf("Usage: %s [pid]\n", argv[0]);
    return 1;
  }

  DIR *dirp = opendir(PROC_PATH);
  if (dirp == NULL) {
    printf("Could not open directory: %s\n", PROC_PATH);
    return 1;
  }

  print_header();

  struct dirent *dp;
  while ((dp = readdir(dirp)) != NULL) {
    if (!is_number(dp->d_name)) {
      continue;
    }

    pid_t pid = atoi(dp->d_name);
    if (pid == getpid()) {
      continue;
    }

    char status_path[BUFSIZ];
    snprintf(status_path, sizeof(status_path), "%s%d/status", PROC_PATH, pid);

    FILE *fp = fopen(status_path, "r");
    if (fp == NULL) {
      continue;
    }

    struct Task *t = (struct Task *)malloc(sizeof(struct Task));

    t->pid = pid;

    char line[BUFSIZ];
    while (fgets(line, sizeof(line), fp) != NULL) {
      if (strncmp(line, "Uid:", 4) == 0) {
        sscanf(line + 4, "%d", &(t->uid));
      } else if (strncmp(line, "Name:", 5) == 0) {
        char *name = line + 5;
        name[strcspn(name, "\n")] = '\0';
        strncpy(t->cmdline, name, sizeof(t->cmdline));
      }
    }

    fclose(fp);

    t->username = get_username(t->uid);

    if (argc == 2 && pid != atoi(argv[1])) {
      free(t);
      continue;
    }

    print_task(t);
    free(t);
  }

  closedir(dirp);

  return 0;
}