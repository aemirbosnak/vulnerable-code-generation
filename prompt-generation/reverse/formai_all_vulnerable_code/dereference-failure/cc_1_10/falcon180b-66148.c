//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *name;
    char *value;
} pair_t;

pair_t *parse_line(char *line) {
    char *pos = strchr(line, '=');
    if (!pos)
        return NULL;

    *pos = '\0';
    pair_t *pair = (pair_t *)malloc(sizeof(pair_t));
    pair->name = strdup(line);
    pair->value = strdup(pos + 1);
    return pair;
}

void free_pair(pair_t *pair) {
    free(pair->name);
    free(pair->value);
    free(pair);
}

int compare_pairs(const void *a, const void *b) {
    pair_t *pair1 = *(pair_t **)a;
    pair_t *pair2 = *(pair_t **)b;

    return strcmp(pair1->name, pair2->name);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error: failed to open file '%s'\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LEN];
    pair_t **pairs = NULL;
    int num_pairs = 0;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        pair_t *pair = parse_line(line);
        if (pair) {
            pairs = (pair_t **)realloc(pairs, sizeof(pair_t *) * (num_pairs + 1));
            pairs[num_pairs++] = pair;
        }
    }

    fclose(fp);

    qsort(pairs, num_pairs, sizeof(pair_t *), compare_pairs);

    for (int i = 0; i < num_pairs; i++) {
        printf("%s = %s\n", pairs[i]->name, pairs[i]->value);
        free_pair(pairs[i]);
    }

    free(pairs);

    return 0;
}