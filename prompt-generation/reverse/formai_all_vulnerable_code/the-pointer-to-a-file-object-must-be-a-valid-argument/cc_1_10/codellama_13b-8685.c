//Code Llama-13B DATASET v1.0 Category: Intrusion detection system ; Style: scalable
// Intrusion Detection System Example Program
// Scalable Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LENGTH 1000
#define MAX_PATTERNS 100

typedef struct {
    char* pattern;
    int pattern_length;
    int score;
} Pattern;

void print_pattern(Pattern pattern) {
    printf("Pattern: %s\n", pattern.pattern);
    printf("Pattern Length: %d\n", pattern.pattern_length);
    printf("Score: %d\n", pattern.score);
}

int compare_patterns(const void* a, const void* b) {
    Pattern* pattern1 = (Pattern*)a;
    Pattern* pattern2 = (Pattern*)b;
    return pattern1->score - pattern2->score;
}

void detect_intrusion(char* log_entry, Pattern* patterns, int num_patterns) {
    for (int i = 0; i < num_patterns; i++) {
        Pattern pattern = patterns[i];
        if (strstr(log_entry, pattern.pattern) != NULL) {
            printf("Intrusion detected! %s\n", log_entry);
            print_pattern(pattern);
            break;
        }
    }
}

int main() {
    char log_entry[MAX_LOG_LENGTH];
    Pattern patterns[MAX_PATTERNS];
    int num_patterns = 0;

    // Load patterns from file
    FILE* fp = fopen("patterns.txt", "r");
    while (fgets(log_entry, MAX_LOG_LENGTH, fp) != NULL) {
        Pattern pattern;
        pattern.pattern = strdup(log_entry);
        pattern.pattern_length = strlen(log_entry);
        pattern.score = 0;
        patterns[num_patterns++] = pattern;
    }
    fclose(fp);

    // Sort patterns by score
    qsort(patterns, num_patterns, sizeof(Pattern), compare_patterns);

    // Read logs from stdin and detect intrusions
    while (fgets(log_entry, MAX_LOG_LENGTH, stdin) != NULL) {
        detect_intrusion(log_entry, patterns, num_patterns);
    }

    return 0;
}