//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000

typedef struct {
    char *text;
    int length;
} Text;

typedef struct {
    double mean;
    double variance;
    double standard_deviation;
} Stats;

void print_text(Text *text) {
    printf("%s", text->text);
}

void print_stats(Stats *stats) {
    printf("Mean: %.2f\n", stats->mean);
    printf("Variance: %.2f\n", stats->variance);
    printf("Standard deviation: %.2f\n", stats->standard_deviation);
}

Text *read_text(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char *text = malloc(MAX_LENGTH);
    if (text == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    int length = 0;
    while (fgets(text + length, MAX_LENGTH - length, file) != NULL) {
        length += strlen(text + length);
    }

    fclose(file);

    Text *text_struct = malloc(sizeof(Text));
    if (text_struct == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    text_struct->text = text;
    text_struct->length = length;

    return text_struct;
}

Stats *calculate_stats(Text *text) {
    double *frequencies = calloc(256, sizeof(double));
    if (frequencies == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    for (int i = 0; i < text->length; i++) {
        frequencies[(unsigned char)text->text[i]]++;
    }

    double mean = 0.0;
    for (int i = 0; i < 256; i++) {
        mean += i * frequencies[i];
    }
    mean /= text->length;

    double variance = 0.0;
    for (int i = 0; i < 256; i++) {
        variance += pow(i - mean, 2) * frequencies[i];
    }
    variance /= text->length;

    double standard_deviation = sqrt(variance);

    Stats *stats = malloc(sizeof(Stats));
    if (stats == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    stats->mean = mean;
    stats->variance = variance;
    stats->standard_deviation = standard_deviation;

    free(frequencies);

    return stats;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    Text *text = read_text(argv[1]);
    Stats *stats = calculate_stats(text);

    printf("Text:\n");
    print_text(text);

    printf("\nStatistics:\n");
    print_stats(stats);

    free(text->text);
    free(text);
    free(stats);

    return 0;
}