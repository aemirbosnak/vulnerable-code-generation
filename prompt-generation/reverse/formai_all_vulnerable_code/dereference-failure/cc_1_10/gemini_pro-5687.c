//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>

#define BUFFSIZE 1024

void copyFile(char *src, char *dest)
{
  int fd1, fd2;
  char buff[BUFFSIZE];
  int n;

  fd1 = open(src, O_RDONLY);
  fd2 = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);

  while ((n = read(fd1, buff, BUFFSIZE)) > 0)
  {
    write(fd2, buff, n);
  }

  close(fd1);
  close(fd2);
}

void syncDirs(char *dir1, char *dir2)
{
  DIR *dp1, *dp2;
  struct dirent *entry1, *entry2;
  char path1[256], path2[256];
  int found;

  dp1 = opendir(dir1);
  dp2 = opendir(dir2);

  while ((entry1 = readdir(dp1)) != NULL)
  {
    if (!strcmp(entry1->d_name, ".") || !strcmp(entry1->d_name, ".."))
      continue;

    sprintf(path1, "%s/%s", dir1, entry1->d_name);
    sprintf(path2, "%s/%s", dir2, entry1->d_name);

    found = 0;
    while ((entry2 = readdir(dp2)) != NULL)
    {
      if (!strcmp(entry2->d_name, ".") || !strcmp(entry2->d_name, ".."))
        continue;

      if (!strcmp(entry1->d_name, entry2->d_name))
      {
        found = 1;
        break;
      }
    }

    rewinddir(dp2);

    if (!found)
    {
      printf("Copying %s to %s\n", path1, path2);
      copyFile(path1, path2);
    }
  }

  closedir(dp1);
  closedir(dp2);
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s <dir1> <dir2>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  syncDirs(argv[1], argv[2]);

  return EXIT_SUCCESS;
}