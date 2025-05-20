//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_SUBNETS 10

typedef struct {
    char name[MAX_LINE_LENGTH];
    int num_subnets;
    int *subnet_sizes;
} SubnetCalculator;

int read_line(char *line, FILE *file) {
    int len = 0;
    while (fscanf(file, "%s", line + len)!= EOF) {
        len += strlen(line + len) + 1;
        if (len >= MAX_LINE_LENGTH) {
            printf("Line too long: %s\n", line);
            exit(1);
        }
    }
    line[len] = '\0';
    return len;
}

void read_subnets(SubnetCalculator *sc, FILE *file) {
    char line[MAX_LINE_LENGTH];
    int i, len;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        len = read_line(line, file);
        if (len == 0) {
            continue;
        }
        if (sc->num_subnets >= MAX_SUBNETS) {
            printf("Too many subnets: %s\n", line);
            exit(1);
        }
        sc->subnet_sizes[sc->num_subnets] = atoi(line);
        sc->num_subnets++;
    }
}

void calculate_subnets(SubnetCalculator *sc) {
    int i, j, size, count = 0;

    for (i = 0; i < sc->num_subnets; i++) {
        size = sc->subnet_sizes[i];
        for (j = size; j <= 32; j++) {
            if ((32 - j) % size == 0) {
                count++;
            }
        }
    }

    printf("Total subnets: %d\n", count);
}

int main(int argc, char *argv[]) {
    FILE *file;
    SubnetCalculator sc;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    sc.num_subnets = 0;
    sc.subnet_sizes = malloc(MAX_SUBNETS * sizeof(int));

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        exit(1);
    }

    read_subnets(&sc, file);
    calculate_subnets(&sc);

    fclose(file);
    free(sc.subnet_sizes);

    return 0;
}