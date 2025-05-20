//GEMINI-pro DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

int main() {
  // Get the current working directory.
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) == NULL) {
    perror("getcwd");
    return EXIT_FAILURE;
  }

  // Open the current working directory.
  DIR *dir = opendir(cwd);
  if (dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  // Get the current user's information.
  struct passwd *pw = getpwuid(getuid());
  if (pw == NULL) {
    perror("getpwuid");
    return EXIT_FAILURE;
  }

  // Get the current group's information.
  struct group *gr = getgrgid(getgid());
  if (gr == NULL) {
    perror("getgrgid");
    return EXIT_FAILURE;
  }

  // Print the current user's name and directory information.
  printf("Current user: %s\n", pw->pw_name);
  printf("Current directory: %s\n", cwd);

  // Print the current group's name.
  printf("Current group: %s\n", gr->gr_name);

  // Print the contents of the current directory.
  printf("Contents of current directory:\n");
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
  }

  // Close the current working directory.
  closedir(dir);

  return EXIT_SUCCESS;
}