//FormAI DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_LOG_ENTRIES 50

struct log_entry {
  char timestamp[20];
  char message[MAX_LINE_LENGTH];
};

int main() {
  struct log_entry log_entries[MAX_LOG_ENTRIES];
  char input_line[MAX_LINE_LENGTH];
  int num_entries = 0;

  printf("Enter log entries one by one.\n");
  printf("Type 'exit' to stop adding entries.\n\n");

  while (num_entries < MAX_LOG_ENTRIES) {
    printf("Log entry %d: ", num_entries+1);

    // read input line
    fgets(input_line, MAX_LINE_LENGTH, stdin);

    // remove newline character at end of input line
    if (strlen(input_line) > 0 && input_line[strlen(input_line)-1] == '\n') {
      input_line[strlen(input_line)-1] = '\0';
    }

    if (strcmp(input_line, "exit") == 0) {
      break;
    }

    // parse timestamp and message from input line
    char *token = strtok(input_line, ",");
    strcpy(log_entries[num_entries].timestamp, token);
    token = strtok(NULL, ",");
    strcpy(log_entries[num_entries].message, token);

    num_entries++;
  }

  printf("\n");

  // print all log entries
  for (int i = 0; i < num_entries; i++) {
    printf("%s: %s\n", log_entries[i].timestamp, log_entries[i].message);
  }

  return 0;
}