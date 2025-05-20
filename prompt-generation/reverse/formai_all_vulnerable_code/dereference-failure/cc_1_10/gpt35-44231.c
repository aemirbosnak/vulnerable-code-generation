//FormAI DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void backupFile(char* filename, char* backupDir)
{
  char backupFilename[100];
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  sprintf(backupFilename, "%s/%s_%04d-%02d-%02d_%02d:%02d:%02d.bak", backupDir, filename, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  
  FILE *srcFile;
  FILE *backupFile;
  
  srcFile = fopen(filename, "rb");
  backupFile = fopen(backupFilename,"wb");
  
  if(srcFile == NULL || backupFile == NULL)
  {
    printf("Error opening file.\n");
    exit(1);
  }
  
  int bufferSize = 1024;
  char buffer[bufferSize];
  
  while(fread(buffer, 1, bufferSize, srcFile) != 0)
  {
    fwrite(buffer, 1, bufferSize, backupFile);
  }
  
  fclose(srcFile);
  fclose(backupFile);
  
  printf("Backup created successfully for %s!\n", filename);
}

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    printf("Usage: ./backup <filename> <backup_directory>\n");
    exit(1);
  }
  
  char* filename = argv[1];
  char* backupDir = argv[2];
  
  backupFile(filename, backupDir);
  
  return 0;
}