//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *start;
    char *end;
} interval;

typedef struct {
    int count;
    interval *intervals;
} statistics;

void print_statistics(statistics *stats) {
    printf("Total count: %d\n", stats->count);
    for (int i = 0; i < stats->count; i++) {
        printf("Interval %d: %s to %s\n", i, stats->intervals[i].start, stats->intervals[i].end);
    }
}

statistics *calculate_statistics(char *html) {
    statistics *stats = malloc(sizeof(statistics));
    stats->count = 0;
    stats->intervals = NULL;

    char *start = html;
    char *end = html;

    while (*end != '\0') {
        if (*end == '<') {
            if (stats->count == 0) {
                stats->intervals = malloc(sizeof(interval));
                stats->intervals[stats->count].start = end;
            }
            end++;
        } else if (*end == '>') {
            stats->intervals[stats->count].end = end;
            stats->count++;
            end++;
        } else {
            end++;
        }
    }

    return stats;
}

int main() {
    char *html = "<html>\n<head>\n<title>Example</title>\n</head>\n<body>\n<h1>Hello, world!</h1>\n</body>\n</html>";

    statistics *stats = calculate_statistics(html);
    print_statistics(stats);

    return 0;
}