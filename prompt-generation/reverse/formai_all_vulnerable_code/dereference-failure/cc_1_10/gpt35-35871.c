//FormAI DATASET v1.0 Category: Log analysis ; Style: immersive
#include <stdio.h>
#include <string.h>

int main() {
  char logFile[] = "example.log";
  FILE *file = fopen(logFile, "r");
  
  if (file == NULL) {
    printf("Failed to open log file!\n");
    return 1;
  }

  printf("\nWelcome to Log Analysis!\n");
  printf("=========================================\n\n");

  char line[256];
  char *timestamp;
  char *logLevel;
  char *logMessage;

  int debugCount = 0;
  int infoCount = 0;
  int warningCount = 0;
  int errorCount = 0;

  while (fgets(line, sizeof(line), file)) {
    timestamp = strtok(line, " ");
    logLevel = strtok(NULL, " ");
    logMessage = strtok(NULL, "\n");

    if (strcmp(logLevel, "DEBUG") == 0) {
      debugCount++;
    } else if (strcmp(logLevel, "INFO") == 0) {
      infoCount++;
    } else if (strcmp(logLevel, "WARNING") == 0) {
      warningCount++;
    } else if (strcmp(logLevel, "ERROR") == 0) {
      errorCount++;
    }

    printf("Timestamp: %s\n", timestamp);
    printf("Log Level: %s\n", logLevel);
    printf("Log Message: %s\n", logMessage);
    printf("=========================================\n");
  }

  printf("DEBUG Count: %d\n", debugCount);
  printf("INFO Count: %d\n", infoCount);
  printf("WARNING Count: %d\n", warningCount);
  printf("ERROR Count: %d\n", errorCount);

  fclose(file);
  return 0;
}