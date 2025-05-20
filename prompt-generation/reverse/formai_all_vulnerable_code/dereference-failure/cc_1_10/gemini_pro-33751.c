//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

// Define the maximum number of files to process
#define MAX_FILES 1000

// Define the structure of a file
typedef struct {
  char *name;
  size_t size;
  time_t mtime;
  uid_t uid;
  gid_t gid;
} file_t;

// Define the comparison function for sorting files by size
int compare_files(const void *a, const void *b) {
  const file_t *fa = (const file_t *)a;
  const file_t *fb = (const file_t *)b;

  return (fa->size > fb->size) ? -1 : (fa->size < fb->size) ? 1 : 0;
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user has specified a directory to analyze
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the directory name
  char *directory = argv[1];

  // Open the directory
  DIR *dir = opendir(directory);
  if (dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  // Allocate memory for the files
  file_t *files = malloc(sizeof(file_t) * MAX_FILES);
  if (files == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  // Read the directory and add the files to the array
  int num_files = 0;
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Get the file name
    char *name = entry->d_name;

    // Get the file size
    struct stat statbuf;
    if (stat(name, &statbuf) == -1) {
      perror("stat");
      continue;
    }
    size_t size = statbuf.st_size;

    // Get the file mtime
    time_t mtime = statbuf.st_mtime;

    // Get the file uid
    uid_t uid = statbuf.st_uid;

    // Get the file gid
    gid_t gid = statbuf.st_gid;

    // Add the file to the array
    files[num_files].name = name;
    files[num_files].size = size;
    files[num_files].mtime = mtime;
    files[num_files].uid = uid;
    files[num_files].gid = gid;
    num_files++;
  }

  // Close the directory
  closedir(dir);

  // Sort the files by size
  qsort(files, num_files, sizeof(file_t), compare_files);

  // Print the files
  for (int i = 0; i < num_files; i++) {
    // Get the file name
    char *name = files[i].name;

    // Get the file size
    size_t size = files[i].size;

    // Get the file mtime
    time_t mtime = files[i].mtime;

    // Get the file uid
    uid_t uid = files[i].uid;

    // Get the file gid
    gid_t gid = files[i].gid;

    // Print the file information
    printf("%s %ld %s %s %s\n", name, size, ctime(&mtime), getpwuid(uid)->pw_name, getgrgid(gid)->gr_name);
  }

  // Free the memory allocated for the files
  free(files);

  return EXIT_SUCCESS;
}