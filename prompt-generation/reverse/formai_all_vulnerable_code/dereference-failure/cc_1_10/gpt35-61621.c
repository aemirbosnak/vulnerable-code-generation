//FormAI DATASET v1.0 Category: Log analysis ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000

struct log_entry {
  char timestamp[25];
  char level[10];
  char message[200];
};

void parse_log_entry(char *line, struct log_entry *log)
{
  char *token;

  // parse timestamp
  token = strtok(line, ",");
  strcpy(log->timestamp, token);

  // parse log level
  token = strtok(NULL, ",");
  strcpy(log->level, token);

  // parse log message
  token = strtok(NULL, ",");
  strcpy(log->message, token);
}

int main()
{
  FILE *log_file;
  char line[250];
  int num_entries = 0;
  struct log_entry log_entries[MAX_LOG_ENTRIES];

  // open log file
  log_file = fopen("log.txt", "r");

  // read each line of log file and parse into log_entry struct
  while(fgets(line, sizeof(line), log_file)) {
    parse_log_entry(line, &log_entries[num_entries]);
    num_entries++;
  }

  // close log file
  fclose(log_file);

  // print out all log entries with ERROR level
  printf("---- ERROR LEVEL LOG ENTRIES -----\n");
  for(int i = 0; i < num_entries; i++) {
    if(strcmp(log_entries[i].level, "ERROR") == 0) {
      printf("%s %s %s", log_entries[i].timestamp,
                         log_entries[i].level,
                         log_entries[i].message);
    }
  }

  // print out all log entries with WARNING level
  printf("---- WARNING LEVEL LOG ENTRIES -----\n");
  for(int i = 0; i < num_entries; i++) {
    if(strcmp(log_entries[i].level, "WARNING") == 0) {
      printf("%s %s %s", log_entries[i].timestamp,
                         log_entries[i].level,
                         log_entries[i].message);
    }
  }

  // print out all log entries with INFO level
  printf("---- INFO LEVEL LOG ENTRIES -----\n");
  for(int i = 0; i < num_entries; i++) {
    if(strcmp(log_entries[i].level, "INFO") == 0) {
      printf("%s %s %s", log_entries[i].timestamp,
                         log_entries[i].level,
                         log_entries[i].message);
    }
  }

  return 0;
}