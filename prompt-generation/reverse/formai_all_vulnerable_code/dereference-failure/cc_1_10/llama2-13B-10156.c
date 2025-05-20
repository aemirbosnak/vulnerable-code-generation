//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAX_WORD_LEN 20
#define MAX_LOG_LEN 100000

// Function to count the number of occurrences of a word in the log
int count_word(char *word, char *log) {
  int count = 0;
  while (strstr(log, word) != NULL) {
    count++;
    log = strstr(log, word) + strlen(word);
  }
  return count;
}

// Function to print the report
void print_report(char *log, char *file_name) {
  int i = 0;
  char word[MAX_WORD_LEN];
  char *p;
  printf("Log Analysis Report for %s\n", file_name);
  printf("------------------------------\n");
  for (p = log; *p != '\0'; p++) {
    if (isalpha(*p)) {
      word[i] = *p;
      i++;
      if (i >= MAX_WORD_LEN) {
        break;
      }
    }
  }
  word[i] = '\0';
  printf("Total words: %d\n", strlen(word));
  printf("Top 10 words:\n");
  for (int j = 0; j < 10; j++) {
    int count = count_word(word, log);
    printf("%d. %s (%d occurrences)\n", j + 1, word, count);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <log_file>\n", argv[0]);
    return 1;
  }
  char *log_file = argv[1];
  char *log = malloc(MAX_LOG_LEN);
  int len = read_log(log_file, log);
  if (len < 0) {
    printf("Error reading log file %s\n", log_file);
    return 2;
  }
  print_report(log, log_file);
  free(log);
  return 0;
}

// Function to read the log file
int read_log(char *file_name, char *log) {
  int len = 0;
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Error opening log file %s\n", file_name);
    return -1;
  }
  char buff[1024];
  while (fgets(buff, 1024, file) != NULL) {
    len += strlen(buff);
    log = realloc(log, len + 1);
    strcat(log, buff);
  }
  fclose(file);
  return len;
}