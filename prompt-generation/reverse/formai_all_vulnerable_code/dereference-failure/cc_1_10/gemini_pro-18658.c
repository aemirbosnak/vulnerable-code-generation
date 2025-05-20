//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct entry {
  char *date;
  char *text;
};

void write_entry(struct entry *entry) {
  FILE *fp = fopen("diary.txt", "a");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }
  fprintf(fp, "%s\n", entry->date);
  fprintf(fp, "%s\n", entry->text);
  fclose(fp);
}

void read_entry(struct entry *entry) {
  FILE *fp = fopen("diary.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return;
  }
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;
  nread = getline(&line, &len, fp);
  if (nread > 0) {
    entry->date = strdup(line);
  }
  nread = getline(&line, &len, fp);
  if (nread > 0) {
    entry->text = strdup(line);
  }
  fclose(fp);
}

int main() {
  struct entry entry;
  time_t now = time(NULL);
  struct tm *tm = localtime(&now);
  entry.date = malloc(sizeof(char) * 100);
  entry.text = malloc(sizeof(char) * 1000);
  strftime(entry.date, 100, "%Y-%m-%d", tm);
  printf("Enter your entry: ");
  fgets(entry.text, 1000, stdin);
  write_entry(&entry);
  read_entry(&entry);
  printf("Your entry is:\n");
  printf("%s\n", entry.date);
  printf("%s\n", entry.text);
  free(entry.date);
  free(entry.text);
  return 0;
}