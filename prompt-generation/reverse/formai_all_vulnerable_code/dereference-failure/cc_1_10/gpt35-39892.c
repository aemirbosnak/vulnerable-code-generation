//FormAI DATASET v1.0 Category: File Backup System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BACKUP_FILES 10

int main() {
  char filename[MAX_FILENAME_LENGTH];
  int num_backups = 0;
  char backup_filenames[MAX_BACKUP_FILES][MAX_FILENAME_LENGTH];
  time_t rawtime;
  struct tm *timeinfo;
  char time_string[20];
  FILE *file_ptr, *backup_file_ptr;

  printf("Enter filename to backup: ");
  scanf("%s", filename);

  file_ptr = fopen(filename, "r");
  if (file_ptr == NULL) {
    printf("Error: file not found\n");
    return 1;
  }

  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(time_string, 20, "%Y-%m-%d_%H-%M-%S", timeinfo);

  snprintf(backup_filenames[num_backups], MAX_FILENAME_LENGTH, "%s_backup_%s", filename, time_string);

  backup_file_ptr = fopen(backup_filenames[num_backups], "w");
  if (backup_file_ptr == NULL) {
    printf("Error: could not create backup file\n");
    return 1;
  }

  char c;
  while ((c = fgetc(file_ptr)) != EOF) {
    fputc(c, backup_file_ptr);
  }

  fclose(file_ptr);
  fclose(backup_file_ptr);

  printf("Backup created: %s\n", backup_filenames[num_backups]);

  num_backups++;

  if (num_backups > MAX_BACKUP_FILES) {
    remove(backup_filenames[0]);
    for (int i = 1; i < MAX_BACKUP_FILES; i++) {
      strcpy(backup_filenames[i-1], backup_filenames[i]);
    }
    num_backups--;
  }

  return 0;
}