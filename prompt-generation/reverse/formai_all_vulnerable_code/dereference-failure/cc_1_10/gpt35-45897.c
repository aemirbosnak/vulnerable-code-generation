//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Cryptic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void sync_files(char* src, char* dest);
bool is_sync_needed(char* src_file, char* dest_file);
void copy_file(char* src, char* dest);
void create_dir(char* path);

int main(int argc, char *argv[]) {
  if(argc < 3) {
    printf("Usage: %s source_dir destination_dir\n", argv[0]);
    exit(1);
  }

  char* src = argv[1];
  char* dest = argv[2];

  if(access(src, F_OK) == -1) {
    printf("Source directory %s does not exist.\n", src);
    exit(1);
  }

  if(access(dest, F_OK) == -1) {
    create_dir(dest);
  }

  sync_files(src, dest);

  return 0;
}

void sync_files(char* src, char* dest) {
  DIR* dir = opendir(src);
  struct dirent* ent;
  while((ent = readdir(dir)) != NULL) {
    if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
      continue;
    }

    char* src_file_path = malloc(strlen(src) + strlen(ent->d_name) + 2);
    strcpy(src_file_path, src);
    strcat(src_file_path, "/");
    strcat(src_file_path, ent->d_name);

    char* dest_file_path = malloc(strlen(dest) + strlen(ent->d_name) + 2);
    strcpy(dest_file_path, dest);
    strcat(dest_file_path, "/");
    strcat(dest_file_path, ent->d_name);

    if(ent->d_type == DT_DIR) {
      if(access(dest_file_path, F_OK) == -1) {
        create_dir(dest_file_path);
      }

      sync_files(src_file_path, dest_file_path);
    } else if(ent->d_type == DT_REG) {
      if(is_sync_needed(src_file_path, dest_file_path)) {
        copy_file(src_file_path, dest_file_path);
      }
    }

    free(src_file_path);
    free(dest_file_path);
  }
}

bool is_sync_needed(char* src_file, char* dest_file) {
  struct stat src_stat, dest_stat;

  if(stat(src_file, &src_stat) != 0) {
    return false;
  }

  if(stat(dest_file, &dest_stat) != 0) {
    return true;
  }

  return src_stat.st_mtime > dest_stat.st_mtime;
}

void copy_file(char* src, char* dest) {
  int src_file = open(src, O_RDONLY);
  int dest_file = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);

  char buffer[BUFSIZ];
  int n;

  while((n = read(src_file, buffer, BUFSIZ)) > 0) {
    write(dest_file, buffer, n);
  }

  close(src_file);
  close(dest_file);
}

void create_dir(char* path) {
  char* parent = dirname(path);
  if(strcmp(parent, "/") != 0) {
    create_dir(parent);
  }

  mkdir(path, 0777);
}