//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_DIR_ENTRIES 1024

int main()
{
  DIR *dirp;
  struct dirent *dir;
  struct stat stat_buf;
  int total_space = 0;
  int current_dir_space = 0;
  char current_dir[256];

  // Get the current working directory
  getcwd(current_dir, sizeof(current_dir));

  // Open the current directory
  dirp = opendir(current_dir);

  // Iterate over the directory entries
  if (dirp)
  {
    while ((dir = readdir(dirp)) != NULL)
    {
      // Skip . and .. entries
      if (dir->d_name[0] == '.')
        continue;

      // Get the full path of the file or directory
      char full_path[PATH_MAX];
      snprintf(full_path, sizeof(full_path), "%s/%s", current_dir, dir->d_name);

      // Get the file or directory statistics
      stat(full_path, &stat_buf);

      // Add the space used by the file or directory to the total space
      current_dir_space += stat_buf.st_size;

      // Increment the total space used
      total_space += current_dir_space;
    }

    closedir(dirp);
  }

  // Print the total space used
  printf("Total space used: %d bytes\n", total_space);

  // Print the space used by each directory
  printf("Space used by each directory:\n");

  dirp = opendir(current_dir);
  if (dirp)
  {
    while ((dir = readdir(dirp)) != NULL)
    {
      // Skip . and .. entries
      if (dir->d_name[0] == '.')
        continue;

      // Get the full path of the file or directory
      char full_path[PATH_MAX];
      snprintf(full_path, sizeof(full_path), "%s/%s", current_dir, dir->d_name);

      // Get the file or directory statistics
      stat(full_path, &stat_buf);

      // Print the directory name and its space used
      printf("%s: %d bytes\n", dir->d_name, stat_buf.st_size);
    }

    closedir(dirp);
  }

  return 0;
}