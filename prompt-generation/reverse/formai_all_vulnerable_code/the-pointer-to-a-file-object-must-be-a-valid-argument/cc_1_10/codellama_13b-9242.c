//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: romantic
// Romantic File Backup System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 1024

typedef struct {
  char name[BUFSIZE];
  char date[BUFSIZE];
  char time[BUFSIZE];
} file_info_t;

void print_file_info(file_info_t* file_info) {
  printf("Name: %s\n", file_info->name);
  printf("Date: %s\n", file_info->date);
  printf("Time: %s\n", file_info->time);
}

void backup_file(char* file_name, char* backup_name) {
  FILE* file = fopen(file_name, "r");
  FILE* backup = fopen(backup_name, "w");
  char buf[BUFSIZE];
  while (fgets(buf, BUFSIZE, file)) {
    fputs(buf, backup);
  }
  fclose(file);
  fclose(backup);
}

int main() {
  file_info_t file_info;
  char file_name[BUFSIZE];
  char backup_name[BUFSIZE];
  char date[BUFSIZE];
  char time[BUFSIZE];
  printf("Enter file name: ");
  fgets(file_name, BUFSIZE, stdin);
  file_name[strcspn(file_name, "\n")] = 0;
  strcpy(backup_name, file_name);
  strcat(backup_name, ".bak");
  printf("Enter date (YYYY-MM-DD): ");
  fgets(date, BUFSIZE, stdin);
  date[strcspn(date, "\n")] = 0;
  printf("Enter time (HH:MM:SS): ");
  fgets(time, BUFSIZE, stdin);
  time[strcspn(time, "\n")] = 0;
  strcpy(file_info.name, file_name);
  strcpy(file_info.date, date);
  strcpy(file_info.time, time);
  backup_file(file_name, backup_name);
  print_file_info(&file_info);
  return 0;
}