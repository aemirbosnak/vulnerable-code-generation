//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define BASES 4
#define LENGTH 1000000
#define BUFFER_SIZE 1000

typedef struct {
    char base;
    int count;
} base_t;

void random_string(char *str, int length) {
    int base, i;
    for (i = 0; i < length; ++i) {
        base = rand() % BASES;
        str[i] = base + 'A';
    }
    str[length] = '\0';
}

void read_file(char *filename, char **buffer, int *length) {
    FILE *file;
    char c;
    int index = 0;
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    while ((c = fgetc(file)) != EOF) {
        buffer[index++] = &c;
    }
    *length = index;
    fclose(file);
}

void count_bases(char *buffer, int length, base_t *bases) {
    int i, j;
    for (i = 0; i < length; ++i) {
        for (j = 0; j < BASES; ++j) {
            if (buffer[i] == j + 'A') {
                bases[j].count++;
                break;
            }
        }
    }
}

void print_result(base_t *bases) {
    int i;
    printf("Base\tCount\n");
    for (i = 0; i < BASES; ++i) {
        printf("%c\t%d\n", bases[i].base, bases[i].count);
    }
}

int main() {
    char *filename = "sequence.txt";
    char *buffer;
    int length, i;
    base_t bases[BASES];

    srand(time(NULL));

    random_string((char *) calloc(LENGTH, sizeof(char)), LENGTH);
    printf("Randomly generated sequence:\n");
    puts((char *) malloc(LENGTH * sizeof(char)));
    free(buffer);

    read_file(filename, &buffer, &length);
    printf("Sequence from file:\n");
    puts(buffer);
    free(buffer);

    count_bases(buffer, length, bases);
    print_result(bases);

    for (i = 0; i < BASES; ++i) {
        bases[i].base = i + 'A';
    }

    return 0;
}