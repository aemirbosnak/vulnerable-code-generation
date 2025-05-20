//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main() {
  pid_t pid;
  char *buf;
  struct stat st;
  struct passwd *pw;
  struct group *gr;
  struct tm *tm;

  printf("Hark, fair maiden! Behold, the tapestry of running processes:\n");

  for (pid = 1; pid <= 99999; pid++) {
    snprintf(buf, 1024, "/proc/%d", pid);

    if (stat(buf, &st) == -1) {
      continue;
    }

    if ((pw = getpwuid(st.st_uid)) == NULL) {
      continue;
    }

    if ((gr = getgrgid(st.st_gid)) == NULL) {
      continue;
    }

    if ((tm = localtime(&st.st_ctime)) == NULL) {
      continue;
    }

    printf("PID: %d\n", pid);
    printf("Name: %s\n", buf);
    printf("Owner: %s\n", pw->pw_name);
    printf("Group: %s\n", gr->gr_name);
    printf("Size: %ld bytes\n", st.st_size);
    printf("Creation Time: %s\n\n", asctime(tm));
  }

  free(buf);

  return 0;
}