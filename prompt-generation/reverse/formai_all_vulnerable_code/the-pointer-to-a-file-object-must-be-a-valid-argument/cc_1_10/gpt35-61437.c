//FormAI DATASET v1.0 Category: File Backup System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_FILES 10

typedef struct {
  char filename[MAX_FILENAME_LENGTH];
  time_t last_modified;
} file_info;

typedef struct {
  file_info files[MAX_BACKUP_FILES];
  int num_files;
} backup;

backup create_backup(char *dir);
void print_backup(backup b);

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Usage: %s <directory>\n", argv[0]);
    exit(1);
  }

  char *dir = argv[1];
  backup b = create_backup(dir);
  print_backup(b);

  return 0;
}

backup create_backup(char *dir) {
  backup b;
  b.num_files = 0;

  // For this example program, we will simulate adding files to the backup by reading
  // a list of files from a text file. In a real program, you would use the file system
  // functions to read the files from the specified directory.

  char filename[MAX_FILENAME_LENGTH];
  FILE *file_list = fopen("file_list.txt", "r");
  while(fgets(filename, MAX_FILENAME_LENGTH, file_list) != NULL) {
    // Remove the newline character from the end of the filename
    filename[strcspn(filename, "\n")] = 0;

    // Create a file_info struct for the file
    file_info fi;
    strcpy(fi.filename, filename);
    fi.last_modified = time(NULL);

    // Add the file to the backup
    b.files[b.num_files++] = fi;
  }
  fclose(file_list);

  return b;
}

void print_backup(backup b) {
  printf("Backup contains %d files:\n", b.num_files);
  for(int i = 0; i < b.num_files; i++) {
    printf("%s (last modified %s)", b.files[i].filename, ctime(&b.files[i].last_modified));
  }
}