//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: artistic
// In the realm of code, a symphony unfolds,
// Where log analysis dances, a story it unfolds.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our symphony's instruments
typedef struct {
    char *message;
    int frequency;
} LogEntry;

// The conductor, orchestrating the flow of logs
int compareLogs(const void *a, const void *b) {
    LogEntry *logA = (LogEntry *)a;
    LogEntry *logB = (LogEntry *)b;
    return logA->frequency < logB->frequency;
}

// The stage, where logs come alive
void drawHistogram(LogEntry *logs, int count) {
    int maxFrequency = 0;
    for (int i = 0; i < count; i++) {
        if (logs[i].frequency > maxFrequency)
            maxFrequency = logs[i].frequency;
    }

    for (int i = 0; i < count; i++) {
        int barSize = (int)((float)logs[i].frequency / (float)maxFrequency * 100.0);
        printf("%-20s | ", logs[i].message);
        for (int j = 0; j < barSize; j++)
            printf("#");
        printf("\n");
    }
}

// The maestro's baton, guiding the analysis
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the log file, a treasure trove of data
    FILE *logFile = fopen(argv[1], "r");
    if (logFile == NULL) {
        printf("Error opening log file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // A canvas to paint the frequencies
    LogEntry logs[1000];
    int logCount = 0;

    // Scan each line, the notes of our symphony
    char line[1024];
    while (fgets(line, sizeof(line), logFile) != NULL) {
        // Parse the line, extracting the message
        char *message = strtok(line, " ");

        // Search for the message in our existing log entries
        int found = 0;
        for (int i = 0; i < logCount; i++) {
            if (strcmp(logs[i].message, message) == 0) {
                logs[i].frequency++;
                found = 1;
                break;
            }
        }

        // If not found, add it to the symphony
        if (!found) {
            logs[logCount].message = strdup(message);
            logs[logCount].frequency = 1;
            logCount++;
        }
    }

    fclose(logFile);

    // Sort the logs, a melody from chaos
    qsort(logs, logCount, sizeof(LogEntry), compareLogs);

    // Draw the histogram, a visual masterpiece
    drawHistogram(logs, logCount);

    // Free the allocated memory, a harmonious end
    for (int i = 0; i < logCount; i++)
        free(logs[i].message);

    return EXIT_SUCCESS;
}