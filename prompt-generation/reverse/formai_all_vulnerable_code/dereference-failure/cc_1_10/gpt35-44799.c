//FormAI DATASET v1.0 Category: File Synchronizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void SynchronizeFiles(const char *source_path, const char *destination_path) {
  DIR *source_dir = opendir(source_path);
  DIR *destination_dir = opendir(destination_path);
  struct dirent *entry;

  if (source_dir == NULL || destination_dir == NULL) {
    printf("Error opening directories\n");
    exit(1);
  }

  while ((entry = readdir(source_dir)) != NULL) {
    if (entry->d_type == DT_REG) { // if it is a regular file
      char source_file_path[strlen(source_path) + strlen(entry->d_name) + 2];
      char destination_file_path[strlen(destination_path) + strlen(entry->d_name) + 2];
      sprintf(source_file_path, "%s/%s", source_path, entry->d_name);
      sprintf(destination_file_path, "%s/%s", destination_path, entry->d_name);

      FILE *source_file = fopen(source_file_path, "rb");
      FILE *destination_file = fopen(destination_file_path, "rb");

      if (source_file == NULL) {
        printf("Error opening source file: %s\n", source_file_path);
        continue;
      }

      if (destination_file == NULL) { // if the file does not exist in the destination directory, copy it over
        printf("Copying file: %s to %s\n", source_file_path, destination_file_path);
        destination_file = fopen(destination_file_path, "wb");
        char buffer[1024];
        size_t bytes_read;

        while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0)
          fwrite(buffer, 1, bytes_read, destination_file);

        fclose(destination_file);
      } else { // compare the contents of the files
        fseek(source_file, 0, SEEK_END);
        long source_file_size = ftell(source_file);
        fseek(destination_file, 0, SEEK_END);
        long destination_file_size = ftell(destination_file);

        if (source_file_size != destination_file_size) {
          printf("Files do not match: %s and %s\n", source_file_path, destination_file_path);
        } else {
          rewind(source_file);
          rewind(destination_file);
          char source_buffer[1024];
          char destination_buffer[1024];

          while (fread(source_buffer, 1, sizeof(source_buffer), source_file) > 0 &&
                 fread(destination_buffer, 1, sizeof(destination_buffer), destination_file) > 0) {
            if (memcmp(source_buffer, destination_buffer, sizeof(source_buffer))) {
              printf("Files do not match: %s and %s\n", source_file_path, destination_file_path);
              break;
            }
          }
        }
      }
      fclose(source_file);
      fclose(destination_file);
    }
  }
  closedir(source_dir);
  closedir(destination_dir);
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
    exit(1);
  }

  SynchronizeFiles(argv[1], argv[2]);

  return 0;
}