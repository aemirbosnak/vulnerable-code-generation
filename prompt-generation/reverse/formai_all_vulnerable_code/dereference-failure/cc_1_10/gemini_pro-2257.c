//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LEN 1024

// Structure to store file information
typedef struct {
   char* path;
   long size;
} FileInfo;

// Function to compare two FileInfo structs by size
int compare_file_info_by_size(const void* a, const void* b) {
   FileInfo* fi1 = (FileInfo*) a;
   FileInfo* fi2 = (FileInfo*) b;
   return fi2->size - fi1->size;
}

// Function to get the size of a file
long get_file_size(const char* path) {
   struct stat st;
   if (stat(path, &st) == -1) {
      perror("stat");
      return -1;
   }
   return st.st_size;
}

// Function to get the size of a directory
long get_directory_size(const char* path) {
   DIR* dir = opendir(path);
   if (dir == NULL) {
      perror("opendir");
      return -1;
   }

   long total_size = 0;

   struct dirent* entry;
   while ((entry = readdir(dir)) != NULL) {
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
         continue;
      }

      char* full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
      strcpy(full_path, path);
      strcat(full_path, "/");
      strcat(full_path, entry->d_name);

      if (entry->d_type == DT_DIR) {
         total_size += get_directory_size(full_path);
      } else {
         total_size += get_file_size(full_path);
      }

      free(full_path);
   }

   closedir(dir);

   return total_size;
}

// Function to analyze the disk space usage of a path
void analyze_disk_space(const char* path) {
   long total_size = get_directory_size(path);

   // Get a list of all files in the directory
   DIR* dir = opendir(path);
   if (dir == NULL) {
      perror("opendir");
      return;
   }

   int num_files = 0;
   struct dirent* entry;
   while ((entry = readdir(dir)) != NULL) {
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
         continue;
      }

      num_files++;
   }

   closedir(dir);

   // Allocate memory for the file info array
   FileInfo* files = malloc(num_files * sizeof(FileInfo));

   // Populate the file info array
   dir = opendir(path);
   int i = 0;
   while ((entry = readdir(dir)) != NULL) {
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
         continue;
      }

      char* full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
      strcpy(full_path, path);
      strcat(full_path, "/");
      strcat(full_path, entry->d_name);

      files[i].path = full_path;
      files[i].size = get_file_size(full_path);

      i++;
   }

   closedir(dir);

   // Sort the file info array by size
   qsort(files, num_files, sizeof(FileInfo), compare_file_info_by_size);

   // Print the file info array
   printf("Directory: %s\n", path);
   printf("Total size: %ld bytes\n", total_size);
   printf("Number of files: %d\n", num_files);
   for (i = 0; i < num_files; i++) {
      printf("%s: %ld bytes\n", files[i].path, files[i].size);
   }

   // Free the memory allocated for the file info array
   for (i = 0; i < num_files; i++) {
      free(files[i].path);
   }
   free(files);
}

int main() {
   analyze_disk_space(".");
   return 0;
}