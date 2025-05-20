//Falcon-180B DATASET v1.0 Category: Recursive ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000000

typedef struct node_t {
    int count;
    struct node_t *next;
} node_t;

void delete_table(node_t *table) {
    node_t *temp;
    while (table!= NULL) {
        temp = table->next;
        free(table);
        table = temp;
    }
}

void insert_word(node_t **table, char *word) {
    int len = strlen(word);
    node_t *cur = *table;
    while (cur!= NULL && len > cur->count) {
        cur = cur->next;
    }
    if (cur == NULL) {
        cur = (node_t *) malloc(sizeof(node_t));
        cur->count = len;
        cur->next = *table;
        *table = cur;
    }
    else if (cur->count == len) {
        cur->count++;
    }
    else {
        node_t *temp = (node_t *) malloc(sizeof(node_t));
        temp->count = len;
        temp->next = cur->next;
        cur->next = temp;
    }
}

void print_table(node_t *table) {
    while (table!= NULL) {
        printf("%d ", table->count);
        table = table->next;
    }
    printf("\n");
}

int main() {
    char *filename = "input.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    node_t *table = NULL;
    while ((read = getline(&line, &len, file))!= -1) {
        if (read > 0 && line[read-1] == '\n') {
            line[--read] = '\0';
        }
        int len_line = strlen(line);
        int i = 0;
        while (i < len_line) {
            if (isalpha(line[i])) {
                char *word = (char *) malloc(sizeof(char) * (i+1));
                strncpy(word, line, i);
                word[i] = '\0';
                insert_word(&table, word);
                free(word);
            }
            i++;
        }
    }
    delete_table(table);
    free(line);
    fclose(file);
    return 0;
}