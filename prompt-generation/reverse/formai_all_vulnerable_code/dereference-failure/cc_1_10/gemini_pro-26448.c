//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a log line
#define MAX_LOG_LINE_LENGTH 1024

// Define the maximum number of log lines to store in memory
#define MAX_LOG_LINES 1000

// Define the structure of a log line
typedef struct log_line {
  char *line;
  int line_number;
  int timestamp;
  char *level;
  char *message;
} log_line;

// Define the structure of a log file
typedef struct log_file {
  char *filename;
  FILE *file;
  int num_lines;
  log_line *lines;
} log_file;

// Create a new log file
log_file *log_file_new(char *filename) {
  log_file *lf = malloc(sizeof(log_file));
  if (lf == NULL) {
    return NULL;
  }

  lf->filename = strdup(filename);
  lf->file = fopen(filename, "r");
  if (lf->file == NULL) {
    free(lf);
    return NULL;
  }

  lf->num_lines = 0;
  lf->lines = NULL;

  return lf;
}

// Free a log file
void log_file_free(log_file *lf) {
  if (lf == NULL) {
    return;
  }

  if (lf->filename != NULL) {
    free(lf->filename);
  }

  if (lf->file != NULL) {
    fclose(lf->file);
  }

  if (lf->lines != NULL) {
    for (int i = 0; i < lf->num_lines; i++) {
      if (lf->lines[i].line != NULL) {
        free(lf->lines[i].line);
      }
    }
    free(lf->lines);
  }

  free(lf);
}

// Read a log file into memory
int log_file_read(log_file *lf) {
  if (lf == NULL) {
    return -1;
  }

  char line[MAX_LOG_LINE_LENGTH];
  while (fgets(line, MAX_LOG_LINE_LENGTH, lf->file) != NULL) {
    log_line ll;
    ll.line = strdup(line);
    ll.line_number = lf->num_lines + 1;
    ll.timestamp = 0;
    ll.level = NULL;
    ll.message = NULL;

    // Parse the log line
    char *timestamp = strtok(line, " ");
    if (timestamp != NULL) {
      ll.timestamp = atoi(timestamp);
    }

    char *level = strtok(NULL, " ");
    if (level != NULL) {
      ll.level = strdup(level);
    }

    char *message = strtok(NULL, "\n");
    if (message != NULL) {
      ll.message = strdup(message);
    }

    // Add the log line to the list of log lines
    lf->lines = realloc(lf->lines, (lf->num_lines + 1) * sizeof(log_line));
    lf->lines[lf->num_lines] = ll;
    lf->num_lines++;
  }

  return 0;
}

// Print a log file
void log_file_print(log_file *lf) {
  if (lf == NULL) {
    return;
  }

  for (int i = 0; i < lf->num_lines; i++) {
    printf("%d %s %s %s\n", lf->lines[i].line_number, lf->lines[i].timestamp, lf->lines[i].level, lf->lines[i].message);
  }
}

// Search a log file for a specific message
int log_file_search(log_file *lf, char *message) {
  if (lf == NULL) {
    return -1;
  }

  for (int i = 0; i < lf->num_lines; i++) {
    if (strstr(lf->lines[i].message, message) != NULL) {
      return i;
    }
  }

  return -1;
}

// Main function
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <log file>\n", argv[0]);
    return 1;
  }

  log_file *lf = log_file_new(argv[1]);
  if (lf == NULL) {
    perror("Error opening log file");
    return 1;
  }

  int ret = log_file_read(lf);
  if (ret != 0) {
    perror("Error reading log file");
    log_file_free(lf);
    return 1;
  }

  log_file_print(lf);

  int index = log_file_search(lf, "ERROR");
  if (index != -1) {
    printf("Found ERROR message at line %d\n", lf->lines[index].line_number);
  } else {
    printf("No ERROR messages found\n");
  }

  log_file_free(lf);

  return 0;
}