//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_N 1000

typedef struct {
    double value;
    int index;
} DataPoint;

void read_data(char *filename, DataPoint *data, int *n) {
    FILE *fp = fopen(filename, "r");
    int i = 0;
    char line[100];
    sscanf(filename, "%d", n);
    rewind(fp);
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%lf", &data[i].value);
        data[i].index = i;
        i++;
    }
    fclose(fp);
}

int find_min_index(DataPoint *data, int n) {
    int min_index = 0;
    double min_value = data[0].value;
    int i;
    for (i = 1; i < n; i++) {
        if (data[i].value < min_value) {
            min_value = data[i].value;
            min_index = i;
        }
    }
    return min_index;
}

void swap(DataPoint *a, DataPoint *b) {
    DataPoint temp = *a;
    *a = *b;
    *b = temp;
}

void greedy_selection(DataPoint *data, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min_index = find_min_index(data, n - i - 1);
        swap(&data[min_index], &data[n - i - 1]);
    }
}

void print_data(DataPoint *data, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Data point %d: %.2f\n", data[i].index, data[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <datafile.csv>\n", argv[0]);
        return 1;
    }

    DataPoint data[MAX_N];
    int n;
    read_data(argv[1], data, &n);

    if (n > MAX_N) {
        fprintf(stderr, "Error: too many data points (%d)\n", n);
        return 1;
    }

    greedy_selection(data, n);
    print_data(data, n);

    return 0;
}