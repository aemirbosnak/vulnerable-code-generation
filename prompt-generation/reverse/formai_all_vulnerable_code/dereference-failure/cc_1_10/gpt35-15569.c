//FormAI DATASET v1.0 Category: File Synchronizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

void copy_file(char *name, char *src_path, char *dst_path)
{
  char src[512], dst[512];
  int src_file, dst_file;
  ssize_t nread;
  unsigned char buffer[4096];

  sprintf(src, "%s/%s", src_path, name);
  sprintf(dst, "%s/%s", dst_path, name);

  src_file = open(src, O_RDONLY);
  if(src_file < 0) {
    printf("\nERROR: Unable to open %s\n", src);
    return;
  }

  dst_file = creat(dst, 0666);
  if(dst_file < 0) {
    printf("\nERROR: Unable to create %s\n", dst);
    close(src_file);
    return;
  }

  while(nread = read(src_file, buffer, sizeof(buffer)), nread > 0) {
      unsigned char *out = buffer;
      ssize_t nwritten;
      do {
          nwritten = write(dst_file, out, nread);

          if(nwritten >= 0) {
              nread -= nwritten;
              out += nwritten;
          } else if(errno != EINTR) {
              printf("\nERROR: Unable to write to %s\n", dst);
              close(src_file);
              close(dst_file);
              unlink(dst);
              return;
          }
      } while(nread > 0);
  }

  if(nread < 0) {
      printf("\nERROR: Unable to read from %s\n", src);
      close(src_file);
      close(dst_file);
      unlink(dst);
      return;
  }

  fsync(dst_file);

  close(src_file);
  close(dst_file);
  printf("%s Copied\n", name);
}

void sync_files(char *src_path, char *dst_path)
{
  DIR* src_dir;
  struct dirent* src_dir_entry;

  src_dir = opendir(src_path);

  if(src_dir == NULL) {
    printf("ERROR: %s Directory not found\n", src_path);
    return;
  }

  while((src_dir_entry = readdir(src_dir)) != NULL) {
    if((src_dir_entry->d_type == DT_REG)) {
      copy_file(src_dir_entry->d_name, src_path, dst_path);
    } else if (strcmp(src_dir_entry->d_name, ".") != 0 && strcmp(src_dir_entry->d_name, "..") != 0) {
      char inner_src[512], inner_dst[512];
      strcpy(inner_src, src_path);
      strcpy(inner_dst, dst_path);
      strcat(inner_src, "/");
      strcat(inner_dst, "/");
      strcat(inner_src, src_dir_entry->d_name);
      strcat(inner_dst, src_dir_entry->d_name);
      mkdir(inner_dst, 0777);
      sync_files(inner_src, inner_dst);
    }
  }

  closedir(src_dir);
}

int main(int argc, char** argv)
{
  if(argc != 3) {
    printf("Usage: ./fsync <source_path> <destination_path>\n");
    exit(1);
  }

  char *src_path = argv[1];
  char *dst_path = argv[2];
  
  sync_files(src_path, dst_path);

  return 0;
}