//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <linux/cdrom.h>

int main(int argc, char *argv[]) {
  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <source file>\n", argv[0]);
    return 1;
  }

  char *filename = argv[1];
  int fd = open(filename, O_RDONLY);
  if (fd < 0) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return 2;
  }

  char buffer[1024];
  size_t nbytes = read(fd, buffer, sizeof(buffer));
  close(fd);

  if (nbytes == 0) {
    fprintf(stderr, "Error reading file %s\n", filename);
    return 3;
  }

  char *backup_filename = strcat(filename, ".bak");
  if (access(backup_filename, F_OK)!= -1) {
    unlink(backup_filename);
  }

  int fd2 = open(backup_filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  if (fd2 < 0) {
    fprintf(stderr, "Error creating backup file %s\n", backup_filename);
    return 4;
  }

  nbytes = write(fd2, buffer, nbytes);
  close(fd2);

  if (nbytes!= nbytes) {
    fprintf(stderr, "Error writing to backup file %s\n", backup_filename);
    return 5;
  }

  printf("File %s backed up successfully to %s\n", filename, backup_filename);
  return 0;
}