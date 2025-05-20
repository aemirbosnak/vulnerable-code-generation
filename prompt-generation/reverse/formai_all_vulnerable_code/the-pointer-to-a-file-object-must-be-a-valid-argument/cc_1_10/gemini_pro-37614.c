//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <string.h>

// Let's add some cheer to our log analysis!
#define LOG_LEVEL_INFO "\033[32m[INFO]\033[0m"
#define LOG_LEVEL_WARNING "\033[33m[WARNING]\033[0m"
#define LOG_LEVEL_ERROR "\033[31m[ERROR]\033[0m"

// Here's our cheerful log analysis function!
void analyzeLog(char *logLine) {
  // First, let's split the log line into fields
  char *fields[5];
  int numFields = 0;
  char *token = strtok(logLine, " ");
  while (token != NULL && numFields < 5) {
    fields[numFields++] = token;
    token = strtok(NULL, " ");
  }

  // Now, let's check the log level
  char *logLevel = fields[0];
  if (strcmp(logLevel, "INFO") == 0) {
    printf("%s %s\n", LOG_LEVEL_INFO, fields[1]);
  } else if (strcmp(logLevel, "WARNING") == 0) {
    printf("%s %s\n", LOG_LEVEL_WARNING, fields[1]);
  } else if (strcmp(logLevel, "ERROR") == 0) {
    printf("%s %s\n", LOG_LEVEL_ERROR, fields[1]);
  } else {
    printf("Oops! Unknown log level: %s\n", logLevel);
  }
}

int main() {
  // Let's create a sample log file
  char logFile[] = "logfile.txt";
  FILE *fp = fopen(logFile, "w");
  fprintf(fp, "INFO This is an informational message\n");
  fprintf(fp, "WARNING This is a warning message\n");
  fprintf(fp, "ERROR This is an error message\n");
  fclose(fp);

  // Now, let's read and analyze our log file
  fp = fopen(logFile, "r");
  char logLine[1024];
  while (fgets(logLine, sizeof(logLine), fp) != NULL) {
    analyzeLog(logLine);
  }
  fclose(fp);

  // Let's leave our program with a cheerful message!
  printf("Log analysis complete! Have a great day :)\n");
  return 0;
}