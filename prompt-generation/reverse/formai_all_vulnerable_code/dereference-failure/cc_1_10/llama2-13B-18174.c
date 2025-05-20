//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR_LEN 1024
#define MAX_STATS 10

typedef struct {
    char *str;
    size_t len;
} stats_t;

void init_stats(stats_t *stats) {
    stats->str = NULL;
    stats->len = 0;
}

void add_stat(stats_t *stats, const char *str) {
    size_t len = strlen(str);
    if (stats->len + len > MAX_STR_LEN) {
        printf("Error: string too long\n");
        return;
    }
    stats->str = realloc(stats->str, stats->len + len + 1);
    memcpy(stats->str + stats->len, str, len + 1);
    stats->len += len;
}

void print_stats(stats_t *stats) {
    printf("Statistics:\n");
    printf("  Max length: %zu\n", stats->len);
    printf("  Average length: %.2f\n", (double)stats->len / MAX_STATS);
    printf("  Standard deviation: %.2f\n", sqrt((double)stats->len * (stats->len - 1) / MAX_STATS));
    printf("  Most common length: %zu\n", stats->len);
}

int main() {
    stats_t stats;
    init_stats(&stats);

    // Add some strings
    add_stat(&stats, "The quick brown fox");
    add_stat(&stats, "jumps over the lazy dog");
    add_stat(&stats, "The rain in Spain stays mainly in the plain");

    // Print the statistics
    print_stats(&stats);

    return 0;
}