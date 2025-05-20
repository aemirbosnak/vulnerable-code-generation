//FormAI DATASET v1.0 Category: File Synchronizer ; Style: mathematical
/*
  C File Synchronizer Example Program
  Designed by Chatbot in a Mathematical Style

  This program compares two directories and synchronizes them by copying
  any missing or modified files from one directory to the other. The hashes
  of the files are used to determine whether they are different.

  Developed by Chatbot
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <openssl/sha.h>

#define HASH_SIZE 20 // size of a SHA-1 hash in bytes

// Function to compute the SHA-1 hash of a file
void hash_file(const char* filename, unsigned char* hash) {
  FILE* file = fopen(filename, "rb");
  if (!file) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    exit(EXIT_FAILURE);
  }

  SHA_CTX ctx;
  SHA1_Init(&ctx);

  unsigned char buffer[4096];
  size_t count;
  while ((count = fread(buffer, 1, sizeof(buffer), file)) > 0) {
    SHA1_Update(&ctx, buffer, count);
  }

  fclose(file);

  SHA1_Final(hash, &ctx);
}

// Function to synchronize two directories recursively
void sync_directories(const char* source_dir, const char* dest_dir) {
  DIR* source = opendir(source_dir);
  if (!source) {
    fprintf(stderr, "Error opening directory: %s\n", source_dir);
    exit(EXIT_FAILURE);
  }

  DIR* dest = opendir(dest_dir);
  if (!dest) {
    if (errno != ENOENT) {
      fprintf(stderr, "Error opening directory: %s\n", dest_dir);
      exit(EXIT_FAILURE);
    }

    if (mkdir(dest_dir, 0755) < 0) {
      fprintf(stderr, "Error creating directory: %s\n", dest_dir);
      exit(EXIT_FAILURE);
    }

    dest = opendir(dest_dir);
    if (!dest) {
      fprintf(stderr, "Error opening directory: %s\n", dest_dir);
      exit(EXIT_FAILURE);
    }
  }

  struct dirent* entry;
  while ((entry = readdir(source))) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    char source_path[PATH_MAX], dest_path[PATH_MAX];
    snprintf(source_path, PATH_MAX, "%s/%s", source_dir, entry->d_name);
    snprintf(dest_path, PATH_MAX, "%s/%s", dest_dir, entry->d_name);

    struct stat source_stat;
    if (stat(source_path, &source_stat) < 0) {
      fprintf(stderr, "Error getting file information: %s\n", source_path);
      exit(EXIT_FAILURE);
    }

    if (S_ISDIR(source_stat.st_mode)) {
      sync_directories(source_path, dest_path);
    } else {
      unsigned char source_hash[HASH_SIZE], dest_hash[HASH_SIZE];
      hash_file(source_path, source_hash);

      int dest_exists = 0;
      struct stat dest_stat;
      if (stat(dest_path, &dest_stat) == 0) {
        if (S_ISREG(dest_stat.st_mode)) {
          hash_file(dest_path, dest_hash);
          dest_exists = 1;
        } else {
          fprintf(stderr, "Error: destination %s exists but is not a regular file\n", dest_path);
          exit(EXIT_FAILURE);
        }
      }

      if (dest_exists && memcmp(source_hash, dest_hash, HASH_SIZE) == 0) {
        continue;
      }

      FILE* source_file = fopen(source_path, "rb");
      if (!source_file) {
        fprintf(stderr, "Error opening file: %s\n", source_path);
        exit(EXIT_FAILURE);
      }

      FILE* dest_file = fopen(dest_path, "wb");
      if (!dest_file) {
        fprintf(stderr, "Error creating file: %s\n", dest_path);
        fclose(source_file);
        exit(EXIT_FAILURE);
      }

      unsigned char buffer[4096];
      size_t count;
      while ((count = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        if (fwrite(buffer, 1, count, dest_file) != count) {
          fprintf(stderr, "Error writing to file: %s\n", dest_path);
          fclose(source_file);
          fclose(dest_file);
          exit(EXIT_FAILURE);
        }
      }

      if (ferror(source_file)) {
        fprintf(stderr, "Error reading from file: %s\n", source_path);
        fclose(source_file);
        fclose(dest_file);
        exit(EXIT_FAILURE);
      }

      if (fclose(source_file) < 0) {
        fprintf(stderr, "Error closing file: %s\n", source_path);
        fclose(dest_file);
        exit(EXIT_FAILURE);
      }

      if (fclose(dest_file) < 0) {
        fprintf(stderr, "Error closing file: %s\n", dest_path);
        exit(EXIT_FAILURE);
      }

      printf("Copied %s to %s\n", source_path, dest_path);
    }
  }

  closedir(source);
  closedir(dest);
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s source_dir dest_dir\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  sync_directories(argv[1], argv[2]);

  return 0;
}