//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX_LINES 10000
#define MAX_LENGTH 1024

typedef struct {
    char *line;
    int count;
} Line;

int compareLines(const void *a, const void *b) {
    return strcmp(((Line *)a)->line, ((Line *)b)->line);
}

int main() {
    FILE *fp = fopen("log.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char line[MAX_LENGTH];
    Line lines[MAX_LINES];
    int numLines = 0;

    while (fgets(line, MAX_LENGTH, fp) != NULL) {
        int i;
        for (i = 0; i < numLines; i++) {
            if (strcmp(line, lines[i].line) == 0) {
                lines[i].count++;
                break;
            }
        }
        if (i == numLines) {
            lines[numLines].line = strdup(line);
            lines[numLines].count = 1;
            numLines++;
        }
    }

    fclose(fp);

    qsort(lines, numLines, sizeof(Line), compareLines);

    int totalLines = 0;
    for (int i = 0; i < numLines; i++) {
        totalLines += lines[i].count;
    }

    printf("Total lines: %d\n", totalLines);
    printf("Unique lines: %d\n", numLines);

    int minCount = INT_MAX;
    int maxCount = INT_MIN;
    for (int i = 0; i < numLines; i++) {
        if (lines[i].count < minCount) {
            minCount = lines[i].count;
        }
        if (lines[i].count > maxCount) {
            maxCount = lines[i].count;
        }
    }

    printf("Minimum count: %d\n", minCount);
    printf("Maximum count: %d\n", maxCount);

    double meanCount = 0.0;
    for (int i = 0; i < numLines; i++) {
        meanCount += lines[i].count;
    }
    meanCount /= numLines;

    printf("Mean count: %.2f\n", meanCount);

    double varianceCount = 0.0;
    for (int i = 0; i < numLines; i++) {
        varianceCount += (lines[i].count - meanCount) * (lines[i].count - meanCount);
    }
    varianceCount /= numLines;

    printf("Variance count: %.2f\n", varianceCount);

    double standardDeviationCount = sqrt(varianceCount);

    printf("Standard deviation count: %.2f\n", standardDeviationCount);

    for (int i = 0; i < numLines; i++) {
        printf("%s: %d\n", lines[i].line, lines[i].count);
        free(lines[i].line);
    }

    return EXIT_SUCCESS;
}