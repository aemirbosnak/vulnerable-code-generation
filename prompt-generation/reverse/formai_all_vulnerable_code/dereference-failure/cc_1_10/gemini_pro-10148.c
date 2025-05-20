//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <time.h>

#define MAX_LINE_LEN 1024
#define MAX_PATTERNS 10

struct log_pattern {
    regex_t regex;
    char *pattern;
};

struct log_analyzer {
    struct log_pattern patterns[MAX_PATTERNS];
    int num_patterns;
};

void add_log_pattern(struct log_analyzer *analyzer, char *pattern) {
    int err;

    if (analyzer->num_patterns >= MAX_PATTERNS) {
        fprintf(stderr, "Error: too many patterns\n");
        exit(1);
    }

    err = regcomp(&analyzer->patterns[analyzer->num_patterns].regex, pattern, REG_EXTENDED);
    if (err != 0) {
        char errbuf[1024];

        regerror(err, &analyzer->patterns[analyzer->num_patterns].regex, errbuf, sizeof(errbuf));
        fprintf(stderr, "Error: %s\n", errbuf);
        exit(1);
    }

    analyzer->patterns[analyzer->num_patterns].pattern = strdup(pattern);
    analyzer->num_patterns++;
}

int match_log_patterns(struct log_analyzer *analyzer, char *log_line) {
    int i;

    for (i = 0; i < analyzer->num_patterns; i++) {
        if (regexec(&analyzer->patterns[i].regex, log_line, 0, NULL, 0) == 0) {
            return 1;
        }
    }

    return 0;
}

void print_log_matches(struct log_analyzer *analyzer, FILE *stream) {
    char line[MAX_LINE_LEN];

    while (fgets(line, sizeof(line), stream) != NULL) {
        if (match_log_patterns(analyzer, line)) {
            fputs(line, stdout);
        }
    }
}

int main(int argc, char **argv) {
    struct log_analyzer analyzer;
    int i;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s pattern1 pattern2 ... logfile\n", argv[0]);
        exit(1);
    }

    analyzer.num_patterns = 0;
    for (i = 1; i < argc - 1; i++) {
        add_log_pattern(&analyzer, argv[i]);
    }

    print_log_matches(&analyzer, fopen(argv[argc - 1], "r"));

    for (i = 0; i < analyzer.num_patterns; i++) {
        regfree(&analyzer.patterns[i].regex);
        free(analyzer.patterns[i].pattern);
    }

    return 0;
}