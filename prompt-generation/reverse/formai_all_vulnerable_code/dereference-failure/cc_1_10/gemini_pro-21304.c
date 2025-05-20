//GEMINI-pro DATASET v1.0 Category: System administration ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main() {
  // Open the directory
  DIR *dir = opendir(".");
  if (dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  // Loop through the directory entries
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Get the file metadata
    struct stat file_metadata;
    if (lstat(entry->d_name, &file_metadata) == -1) {
      perror("lstat");
      continue;
    }

    // Get the file owner's name
    struct passwd *user = getpwuid(file_metadata.st_uid);
    if (user == NULL) {
      perror("getpwuid");
      continue;
    }

    // Get the file group's name
    struct group *group = getgrgid(file_metadata.st_gid);
    if (group == NULL) {
      perror("getgrgid");
      continue;
    }

    // Format the file information
    char file_info[256];
    snprintf(file_info, sizeof(file_info), "%s %ld %s %s %ld %s",
             (S_ISDIR(file_metadata.st_mode)) ? "d" : "-",
             file_metadata.st_size, user->pw_name, group->gr_name,
             file_metadata.st_mtime, entry->d_name);

    // Print the file information
    printf("%s\n", file_info);
  }

  // Close the directory
  closedir(dir);

  return EXIT_SUCCESS;
}