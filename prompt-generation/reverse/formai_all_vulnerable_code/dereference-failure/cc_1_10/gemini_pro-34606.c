//GEMINI-pro DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <file> <owner> <group>\n", argv[0]);
    return 1;
  }

  char *file = argv[1];
  char *owner = argv[2];
  char *group = argv[3];

  struct stat st;
  if (stat(file, &st) == -1) {
    perror("stat");
    return 1;
  }

  struct passwd *pw = getpwnam(owner);
  if (pw == NULL) {
    perror("getpwnam");
    return 1;
  }

  struct group *gr = getgrnam(group);
  if (gr == NULL) {
    perror("getgrnam");
    return 1;
  }

  if (chown(file, pw->pw_uid, gr->gr_gid) == -1) {
    perror("chown");
    return 1;
  }

  if (chmod(file, st.st_mode) == -1) {
    perror("chmod");
    return 1;
  }

  printf("Changed ownership of %s to %s:%s\n", file, owner, group);

  return 0;
}