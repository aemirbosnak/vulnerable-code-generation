//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR_LEN 1024
#define MIN_STR_LEN 10

// Define a struct to hold the string statistics
typedef struct {
    int len;      // string length
    int occ[26]; // character occurrence array
} str_stat_t;

// Function to generate a random string
str_stat_t *rand_str(int min_len, int max_len) {
    str_stat_t *stats = malloc(sizeof(str_stat_t));
    int i, j, c;
    char *str = malloc(max_len * sizeof(char));

    // Generate a random string
    for (i = 0; i < max_len; i++) {
        c = rand() % 26 + 'a';
        str[i] = c;
        stats->occ[c - 'a']++;
    }

    // Set the string length
    stats->len = max_len;

    return stats;
}

// Function to print the string statistics
void print_stats(str_stat_t *stats) {
    int i;
    printf("String Statistics:\n");
    for (i = 0; i < 26; i++) {
        printf("Character %c appears %d times\n", i + 'a', stats->occ[i]);
    }
    printf("Average character frequency: %f\n",
           (float)stats->occ[0] / stats->len);
}

int main() {
    int num_strings = 10; // number of random strings to generate
    int min_len = 10;    // minimum string length
    int max_len = 50;   // maximum string length

    // Generate the random strings
    str_stat_t *stats[num_strings];
    for (int i = 0; i < num_strings; i++) {
        stats[i] = rand_str(min_len, max_len);
    }

    // Print the string statistics
    for (int i = 0; i < num_strings; i++) {
        print_stats(stats[i]);
    }

    return 0;
}