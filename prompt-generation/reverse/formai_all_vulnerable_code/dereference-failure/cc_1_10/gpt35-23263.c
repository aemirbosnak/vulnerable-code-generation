//FormAI DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_FILENAME_LENGTH 512

int main(int argc, char* argv[]) {
  char* filename; // original file name
  char* backupFilename; // backup file name
  char currentTime[20]; // current time in yyyy-mm-dd_HH:MM:SS format
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  // check if a filename was provided as command line argument
  if(argc < 2) {
    printf("Usage: backup <filename>\n");
    return 1;
  }
  
  filename = argv[1];

  // generate backup filename by appending current time stamp
  sprintf(currentTime, "%04d-%02d-%02d_%02d:%02d:%02d",
    tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
    tm.tm_hour, tm.tm_min, tm.tm_sec);

  backupFilename = malloc(MAX_BACKUP_FILENAME_LENGTH);
  if(!backupFilename) {
    fprintf(stderr, "Failed to allocate memory\n");
    return 1;
  }

  // create backup filename by appending timestamp to original filename
  strncpy(backupFilename, filename, MAX_FILENAME_LENGTH);
  strncat(backupFilename, ".", 1); // add separator
  strncat(backupFilename, currentTime, 20);

  // open original file and backup file
  int fdIn = open(filename, O_RDONLY);
  int fdOut = open(backupFilename, O_CREAT | O_WRONLY, 0640);
  if(fdIn == -1 || fdOut == -1) {
    perror("Failed to open files");
    return 1;
  }

  // read data from original file and write to backup file
  int bytesRead;
  char buffer[1024];
  while((bytesRead = read(fdIn, buffer, sizeof(buffer))) > 0) {
    if(write(fdOut, buffer, bytesRead) != bytesRead) {
      perror("Failed to write to backup file");
      return 1;
    }
  }

  // close files
  close(fdIn);
  close(fdOut);

  printf("Backup created: %s\n", backupFilename);

  free(backupFilename);

  return 0;
}