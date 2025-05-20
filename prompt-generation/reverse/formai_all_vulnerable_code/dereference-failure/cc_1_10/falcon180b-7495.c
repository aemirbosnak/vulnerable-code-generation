//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_INDEX 10000
#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define MAX_TERM_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} record_t;

typedef struct {
    char term[MAX_TERM_LENGTH];
    int count;
} term_t;

typedef struct {
    int *index;
    int num_terms;
    term_t terms[MAX_INDEX];
} index_t;

void build_index(index_t *index, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    record_t record;
    term_t term;
    int i = 0;

    while (fscanf(file, "%s %s\n", record.key, record.value)!= EOF) {
        int j = 0;
        while (j < MAX_TERM_LENGTH && record.key[j]!= '\0') {
            if (isalpha(record.key[j])) {
                term.term[j] = tolower(record.key[j]);
            } else {
                term.term[j] = '\0';
                break;
            }
            j++;
        }
        term.count = 1;

        if (i >= MAX_INDEX) {
            printf("Error: index is full\n");
            exit(1);
        }
        index->index[i] = 0;
        strcpy(index->terms[i].term, term.term);
        index->terms[i].count = 1;
        i++;
        index->num_terms++;
    }

    fclose(file);
}

void search_index(index_t *index, char *query) {
    int i = 0;
    while (i < index->num_terms) {
        if (strncmp(query, index->terms[i].term, strlen(query)) == 0) {
            printf("Found %d records with key '%s'\n", index->terms[i].count, index->terms[i].term);
            break;
        }
        i++;
    }
}

int main() {
    index_t index;
    index.num_terms = 0;

    build_index(&index, "data.txt");

    char query[MAX_TERM_LENGTH];
    printf("Enter a search query: ");
    scanf("%s", query);

    search_index(&index, query);

    return 0;
}