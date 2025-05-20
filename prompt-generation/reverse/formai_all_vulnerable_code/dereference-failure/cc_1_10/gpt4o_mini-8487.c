//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_LOG_ENTRIES 100

typedef enum {
    FLAT,
    JSON,
    XML
} OutputFormat;

typedef struct {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logEntryCount = 0;

void addLogEntry(const char *line) {
    if (logEntryCount >= MAX_LOG_ENTRIES) {
        printf("Log entries limit reached!\n");
        return;
    }

    sscanf(line, "%[^ ] %[^ ] %[^\n]", logEntries[logEntryCount].timestamp,
           logEntries[logEntryCount].level, logEntries[logEntryCount].message);
    logEntryCount++;
}

void printLogsFlat() {
    printf("Timestamp            Level      Message\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < logEntryCount; i++) {
        printf("%-20s %-10s %s\n",
               logEntries[i].timestamp,
               logEntries[i].level,
               logEntries[i].message);
    }
}

void printLogsJSON() {
    printf("[\n");
    for (int i = 0; i < logEntryCount; i++) {
        printf("  {\n");
        printf("    \"timestamp\": \"%s\",\n", logEntries[i].timestamp);
        printf("    \"level\": \"%s\",\n", logEntries[i].level);
        printf("    \"message\": \"%s\"\n", logEntries[i].message);
        printf("  }%s\n", (i < logEntryCount - 1) ? "," : "");
    }
    printf("]\n");
}

void printLogsXML() {
    printf("<logs>\n");
    for (int i = 0; i < logEntryCount; i++) {
        printf("  <log>\n");
        printf("    <timestamp>%s</timestamp>\n", logEntries[i].timestamp);
        printf("    <level>%s</level>\n", logEntries[i].level);
        printf("    <message>%s</message>\n", logEntries[i].message);
        printf("  </log>\n");
    }
    printf("</logs>\n");
}

void analyzeLogs(OutputFormat format) {
    switch (format) {
        case FLAT:
            printLogsFlat();
            break;
        case JSON:
            printLogsJSON();
            break;
        case XML:
            printLogsXML();
            break;
        default:
            printf("Unknown output format.\n");
    }
}

void usage() {
    printf("Usage: log_analyzer <log_file> <format>\n");
    printf("Format options: flat, json, xml\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage();
        return 1;
    }

    OutputFormat format = FLAT;
    if (strcmp(argv[2], "json") == 0) {
        format = JSON;
    } else if (strcmp(argv[2], "xml") == 0) {
        format = XML;
    } else if (strcmp(argv[2], "flat") != 0) {
        usage();
        return 1;
    }

    FILE *logFile = fopen(argv[1], "r");
    if (!logFile) {
        perror("Could not open log file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), logFile)) {
        addLogEntry(line);
    }
    fclose(logFile);

    analyzeLogs(format);

    return 0;
}