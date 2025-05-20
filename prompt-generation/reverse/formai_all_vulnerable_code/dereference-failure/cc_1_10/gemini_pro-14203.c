//GEMINI-pro DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>
#include <dirent.h>

int main() {
  uid_t uid = getuid();
  gid_t gid = getgid();

  struct passwd *pwd = getpwuid(uid);
  struct group *grp = getgrgid(gid);

  printf("User: %s (UID: %d)\n", pwd->pw_name, uid);
  printf("Group: %s (GID: %d)\n", grp->gr_name, gid);

  // List files in the current directory
  DIR *dir = opendir(".");
  if (dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
  }

  closedir(dir);

  // Create a new file
  int fd = open("newfile.txt", O_CREAT | O_WRONLY, 0644);
  if (fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  // Write to the file
  const char *str = "Hello, world!\n";
  ssize_t bytes_written = write(fd, str, strlen(str));
  if (bytes_written == -1) {
    perror("write");
    return EXIT_FAILURE;
  }

  close(fd);

  return EXIT_SUCCESS;
}