//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MAX_LINE 100

char input_buffer[MAX_SIZE];
char line_buffer[MAX_LINE];

int main() {
    double total_memory = 0;
    double used_memory = 0;
    double free_memory = 0;
    double available_memory = 0;
    double percent_used = 0;
    char *token = NULL;
    char *line = NULL;
    char *p;
    char *q;
    FILE *fp;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        printf("Error: Cannot open /proc/meminfo file.\n");
        return 1;
    }

    while ((line = fgets(line_buffer, MAX_LINE, fp))!= NULL) {
        p = line_buffer;
        while ((token = strtok_r(p, ":", &q))!= NULL) {
            p = NULL;
            if (strcmp(token, "MemTotal") == 0) {
                total_memory = strtod(token, &p);
            } else if (strcmp(token, "MemFree") == 0) {
                free_memory = strtod(token, &p);
            } else if (strcmp(token, "Buffers") == 0) {
                available_memory = strtod(token, &p);
            }
        }
    }

    fclose(fp);

    used_memory = total_memory - free_memory;
    percent_used = (used_memory / total_memory) * 100;

    printf("Total Memory: %.2lf MB\n", total_memory / (1024 * 1024));
    printf("Used Memory: %.2lf MB\n", used_memory / (1024 * 1024));
    printf("Free Memory: %.2lf MB\n", free_memory / (1024 * 1024));
    printf("Available Memory: %.2lf MB\n", available_memory / (1024 * 1024));
    printf("Percentage Used: %.2lf%%\n", percent_used);

    return 0;
}