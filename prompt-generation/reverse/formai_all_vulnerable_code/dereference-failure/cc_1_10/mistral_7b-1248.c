//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100
#define NUM_STRINGS 5

typedef struct {
    char str[MAX_LEN];
    int dist_to_prev[NUM_STRINGS];
} string_t;

void init_strings(string_t *strings, int num_strings) {
    for (int i = 0; i < num_strings; ++i) {
        strcpy(strings[i].str, "");
        for (int j = 0; j < num_strings; ++j) {
            strings[i].dist_to_prev[j] = i;
        }
    }
}

void read_strings(string_t *strings, int num_strings) {
    for (int i = 0; i < num_strings; ++i) {
        printf("Enter string %d: ", i + 1);
        fgets(strings[i].str, MAX_LEN, stdin);
        strings[i].str[strlen(strings[i].str) - 1] = '\0';
    }
}

void print_matrix(string_t *strings, int num_strings) {
    printf("\nLevenshtein Distance Matrix:\n");
    for (int i = 0; i < num_strings; ++i) {
        printf("%s", strings[i].str);
        for (int j = 0; j < num_strings; ++j) {
            printf("\t%d", strings[i].dist_to_prev[j]);
        }
        printf("\n");
    }
}

void calculate_distances(string_t *strings, int num_strings) {
    int cost_matrix[NUM_STRINGS][NUM_STRINGS];

    for (int i = 0; i < num_strings; ++i) {
        for (int j = 0; j < num_strings; ++j) {
            if (i == 0 || j == 0) {
                cost_matrix[i][j] = i;
            } else if (strings[i].str[0] == strings[j].str[0]) {
                cost_matrix[i][j] = strings[i].dist_to_prev[j - 1];
            } else {
                cost_matrix[i][j] = 1 + min(
                    strings[i].dist_to_prev[j - 1],
                    strings[i - 1].dist_to_prev[j],
                    strings[i - 1].dist_to_prev[j - 1]
                );
            }
            strings[i].dist_to_prev[j] = cost_matrix[i][j];
        }
    }
}

int min(int a, int b, int c) {
    if (a < b) {
        if (a < c) {
            return a;
        } else {
            return c;
        }
    } else {
        if (b < c) {
            return b;
        } else {
            return c;
        }
    }
}

int main() {
    string_t strings[NUM_STRINGS];
    init_strings(strings, NUM_STRINGS);
    read_strings(strings, NUM_STRINGS);
    calculate_distances(strings, NUM_STRINGS);
    print_matrix(strings, NUM_STRINGS);
    return 0;
}