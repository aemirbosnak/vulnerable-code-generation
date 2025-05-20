//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define THOUSANDS 1024

static long long s2i(char *statbuf, int field) {
  /* stat field to long long */
  /* field 0 is dev */
  /* field 1 is ino */
  /* field 2 is mode */
  /* field 3 is nlink */
  /* field 4 is uid */
  /* field 5 is gid */
  /* field 6 is rdev */
  /* field 7 is size */
  /* field 8 is blksize */
  /* field 9 is blocks */
  /* field 10 is atime */
  /* field 11 is mtime */
  /* field 12 is ctime */
  char *s = statbuf + 8 * field;
  long long n = 0;
  int f;
  for (f = 0; f < 8; f++) {
    n *= 256;
    n += (unsigned char)*s++;
  }
  return n;
}

static int sort(const void *a, const void *b) {
  return s2i((char *)a, 7) - s2i((char *)b, 7);
}

int main(int argc, char **argv) {
  /* make a sorted list of filenames by size */
  FILE *fp;
  int found;
  struct stat statbuf;
  int count, f;
  long long filesize;
  char *file, *statname;

  filesize = 0;
  if (argc <= 1) {
    statname = ".";
  } else {
    statname = argv[1];
  }
  fp = popen("find . -type f | sort", "r");
  if (fp == NULL) {
    fprintf(stderr, "Can't find files\n");
    exit(1);
  }
  count = 0;
  do {
    file = fgets((char *)NULL, 1024, fp);
    if (file == NULL) {
      break;
    }
    file[strlen(file) - 1] = '\0';
    if (strcmp(file, statname) == 0) {
      continue;
    }
    found = stat(file, &statbuf);
    if (found == 0) {
      count++;
      filesize += s2i((char *)&statbuf, 7);
      printf("%lld %s\n", s2i((char *)&statbuf, 7), file);
    }
  } while (1);
  fclose(fp);
  filesize *= 100;
  filesize /= THOUSANDS;
  filesize /= THOUSANDS;
  printf("%lld MBytes\n", filesize);
  return 0;
}