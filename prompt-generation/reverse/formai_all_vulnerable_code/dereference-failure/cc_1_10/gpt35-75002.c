//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

unsigned long long get_directory_size(const char *path);

int main(int argc, char *argv[]) {
   unsigned long long size = 0;

   if (argc < 2) {
      printf("Usage: %s directory_path\n", argv[0]);
      return 1;
   }

   size = get_directory_size(argv[1]);
   printf("Total size of %s: %llu bytes\n", argv[1], size);

   return 0;
}

unsigned long long get_directory_size(const char *path) {
   DIR *dir = opendir(path);
   struct dirent *entry;
   struct stat info;
   unsigned long long size = 0;

   if (!dir) {
      printf("Can't open directory: %s\n", path);
      return 0;
   }

   while ((entry = readdir(dir)) != NULL) {
      char file_path[1024];
      sprintf(file_path, "%s/%s", path, entry->d_name);

      if (stat(file_path, &info) == -1) {
         printf("Can't stat file: %s\n", file_path);
         continue;
      }

      if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
         size += get_directory_size(file_path);
      } else {
         size += info.st_size;
      }
   }

   closedir(dir);
   return size;
}