//FormAI DATASET v1.0 Category: File Synchronizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

void synchronize(char *src_dir, char *dest_dir);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./sync src_dir dest_dir\n");
    exit(1);
  }
  
  synchronize(argv[1], argv[2]);

  printf("Synchronization complete!\n");

  return 0;
}

void synchronize(char *src_dir, char *dest_dir) {
  DIR *src_dirp, *dest_dirp;
  struct dirent *src_entry, *dest_entry;
  struct stat src_stat, dest_stat;
  char src_path[PATH_MAX], dest_path[PATH_MAX];
  
  // Open source and destination directories
  if ((src_dirp = opendir(src_dir)) == NULL) {
    fprintf(stderr, "Failed to open source directory: %s\n", strerror(errno));
    return;
  }
  if ((dest_dirp = opendir(dest_dir)) == NULL) {
    fprintf(stderr, "Failed to open destination directory: %s\n", strerror(errno));
    return;
  }

  // Loop through source directory
  while ((src_entry = readdir(src_dirp)) != NULL) {
    // Ignore hidden files and directories
    if (src_entry->d_name[0] == '.') {
      continue;
    }

    // Build full path of source file/directory
    snprintf(src_path, PATH_MAX, "%s/%s", src_dir, src_entry->d_name);

    // Check if source entry is a file or directory
    if (stat(src_path, &src_stat) == -1) {
      fprintf(stderr, "Failed to stat source file %s: %s\n", src_path, strerror(errno));
      continue;
    }

    // Build full path of destination file/directory
    snprintf(dest_path, PATH_MAX, "%s/%s", dest_dir, src_entry->d_name);

    // Check if destination entry exists
    if (stat(dest_path, &dest_stat) == -1) {
      // Destination entry does not exist, create if source is a file or synchronize if source is a directory
      if (S_ISREG(src_stat.st_mode)) {
        // Source is a file, just copy over to destination
        FILE *src_file, *dest_file;
        if ((src_file = fopen(src_path, "r")) == NULL) {
          fprintf(stderr, "Failed to open source file %s: %s\n", src_path, strerror(errno));
          continue;
        }
        if ((dest_file = fopen(dest_path, "w")) == NULL) {
          fprintf(stderr, "Failed to open destination file %s: %s\n", dest_path, strerror(errno));
          fclose(src_file);
          continue;
        }
        
        // Copy contents of source file to destination file
        char buffer[1024];
        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file))) {
          fwrite(buffer, 1, bytes_read, dest_file);
        }

        fclose(src_file);
        fclose(dest_file);
        printf("Created and copied %s\n", dest_path);
      } else if (S_ISDIR(src_stat.st_mode)) {
        // Source is a directory, create destination directory and synchronize recursively 
        if (mkdir(dest_path, src_stat.st_mode) == -1) {
          fprintf(stderr, "Failed to create destination directory %s: %s\n", dest_path, strerror(errno));
          continue;
        }

        printf("Created directory %s\n", dest_path);
        synchronize(src_path, dest_path);
      }
    } else {
      // Destination entry exists, synchronize if source is a directory or update if source is a file
      if (S_ISREG(src_stat.st_mode)) {
        if (S_ISREG(dest_stat.st_mode)) {
          // Both source and destination are files, compare modification times and copy over if source is newer
          if (src_stat.st_mtime > dest_stat.st_mtime) {
            // Source file is newer, copy over to destination file
            FILE *src_file, *dest_file;
            if ((src_file = fopen(src_path, "r")) == NULL) {
              fprintf(stderr, "Failed to open source file %s: %s\n", src_path, strerror(errno));
              continue;
            }
            if ((dest_file = fopen(dest_path, "w")) == NULL) {
              fprintf(stderr, "Failed to open destination file %s: %s\n", dest_path, strerror(errno));
              fclose(src_file);
              continue;
            }
            
            // Copy contents of source file to destination file
            char buffer[1024];
            size_t bytes_read;
            while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file))) {
              fwrite(buffer, 1, bytes_read, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
            printf("Updated %s\n", dest_path);
          } else if (src_stat.st_mtime < dest_stat.st_mtime) {
            printf("Source file %s is older than destination file %s, skipping update\n", src_path, dest_path);
          } else {
            printf("%s is up to date\n", dest_path);
          }
        } else {
          // Source is a file but destination is a directory, copy over to directory with same name
          char dest_file_path[PATH_MAX];
          snprintf(dest_file_path, PATH_MAX, "%s/%s", dest_path, src_entry->d_name);
          
          FILE *src_file, *dest_file;
          if ((src_file = fopen(src_path, "r")) == NULL) {
            fprintf(stderr, "Failed to open source file %s: %s\n", src_path, strerror(errno));
            continue;
          }
          if ((dest_file = fopen(dest_file_path, "w")) == NULL) {
            fprintf(stderr, "Failed to open destination file %s: %s\n", dest_file_path, strerror(errno));
            fclose(src_file);
            continue;
          }
          
          // Copy contents of source file to destination file
          char buffer[1024];
          size_t bytes_read;
          while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file))) {
            fwrite(buffer, 1, bytes_read, dest_file);
          }

          fclose(src_file);
          fclose(dest_file);
          printf("Copied %s to %s\n", src_path, dest_file_path);
        }
      } else if (S_ISDIR(src_stat.st_mode)) {
        if (S_ISDIR(dest_stat.st_mode)) {
          // Both source and destination are directories, synchronize recursively
          synchronize(src_path, dest_path);
        } else {
          // Source is a directory but destination is a file, error
          fprintf(stderr, "Failed to synchronize %s with %s: Directory cannot be synchronized with file\n", src_path, dest_path);
        }
      }
    }
  }

  // Loop through destination directory and delete any files/directories that do not exist in source directory
  while ((dest_entry = readdir(dest_dirp)) != NULL) {
    // Ignore hidden files and directories
    if (dest_entry->d_name[0] == '.') {
      continue;
    }

    // Build full path of destination file/directory
    snprintf(dest_path, PATH_MAX, "%s/%s", dest_dir, dest_entry->d_name);

    // Check if destination entry exists in source directory
    if (stat(dest_path, &dest_stat) == -1) {
      // Destination entry does not exist in source directory, delete
      if (S_ISREG(dest_stat.st_mode)) {
        // Destination is a file, delete
        if (unlink(dest_path) == -1) {
          fprintf(stderr, "Failed to delete destination file %s: %s\n", dest_path, strerror(errno));
        } else {
          printf("Deleted %s\n", dest_path);
        }
      } else if (S_ISDIR(dest_stat.st_mode)) {
        // Destination is a directory, delete recursively
        DIR *dest_subdir;
        struct dirent *dest_subentry;
        
        // Open destination subdirectory
        if ((dest_subdir = opendir(dest_path)) == NULL) {
          fprintf(stderr, "Failed to open destination subdirectory %s: %s\n", dest_path, strerror(errno));
          continue;
        }

        // Delete all files/directories in subdirectory recursively
        while ((dest_subentry = readdir(dest_subdir)) != NULL) {
          // Ignore hidden files and directories and . and ..
          if (dest_subentry->d_name[0] == '.' || strcmp(dest_subentry->d_name, ".") == 0 || strcmp(dest_subentry->d_name, "..") == 0) {
            continue;
          }

          // Build full path of subentry
          char dest_subpath[PATH_MAX];
          snprintf(dest_subpath, PATH_MAX, "%s/%s", dest_path, dest_subentry->d_name);

          // Check if subentry is a file or directory
          struct stat dest_substat;
          if (stat(dest_subpath, &dest_substat) == -1) {
            fprintf(stderr, "Failed to stat destination subentry %s: %s\n", dest_subpath, strerror(errno));
            continue;
          }

          if (S_ISREG(dest_substat.st_mode)) {
            // Subentry is a file, delete
            if (unlink(dest_subpath) == -1) {
              fprintf(stderr, "Failed to delete destination subfile %s: %s\n", dest_subpath, strerror(errno));
            } else {
              printf("Deleted %s\n", dest_subpath);
            }
          } else if (S_ISDIR(dest_substat.st_mode)) {
            // Subentry is a directory, delete recursively
            synchronize("", dest_subpath);
          }
        }

        closedir(dest_subdir);

        // Delete the subdirectory itself
        if (rmdir(dest_path) == -1) {
          fprintf(stderr, "Failed to delete destination directory %s: %s\n", dest_path, strerror(errno));
        } else {
          printf("Deleted directory %s\n", dest_path);
        }
      }
    }
  }

  // Close directories
  closedir(src_dirp);
  closedir(dest_dirp);
}