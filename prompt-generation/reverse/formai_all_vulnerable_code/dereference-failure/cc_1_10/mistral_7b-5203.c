//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024
#define MIN_FREQ 5

typedef struct {
    int value;
    size_t count;
} Freq;

typedef struct {
    Freq data[256];
    size_t size;
} FreqTable;

void load_data(FILE *fp, FreqTable *ft) {
    char line[BUF_SIZE];
    int value;

    ft->size = 0;

    while (fgets(line, BUF_SIZE, fp) != NULL) {
        value = atoi(line);
        if (isdigit((unsigned char)value)) {
            ft->data[value].value = value;
            ft->data[value].count++;
            ft->size++;
        }
    }
}

void print_freq(FreqTable ft) {
    size_t i;

    printf("Frequency table:\n");

    for (i = 0; i < ft.size; i++) {
        if (ft.data[i].count >= MIN_FREQ) {
            printf("%d: %ld\n", ft.data[i].value, ft.data[i].count);
        }
    }
}

int main() {
    FILE *fp;
    FreqTable ft;

    if ((fp = fopen("data.txt", "r")) == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    load_data(fp, &ft);
    print_freq(ft);

    fclose(fp);
    return EXIT_SUCCESS;
}