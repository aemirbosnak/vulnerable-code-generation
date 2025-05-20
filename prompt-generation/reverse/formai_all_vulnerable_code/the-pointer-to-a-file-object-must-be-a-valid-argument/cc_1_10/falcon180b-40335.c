//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char *name;
    int age;
    float income;
    char gender;
} Person;

Person data[MAX_ROWS][MAX_COLS];

void load_data(char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[1024];
    int row = 0;
    int col = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");

        if (row >= MAX_ROWS || col >= MAX_COLS) {
            printf("Error: Data exceeds maximum size.\n");
            exit(1);
        }

        data[row][col].name = strdup(token);
        token = strtok(NULL, ",");
        data[row][col].age = atoi(token);
        token = strtok(NULL, ",");
        data[row][col].income = atof(token);
        token = strtok(NULL, ",");
        data[row][col].gender = token[0];

        row++;
        col++;
    }

    fclose(fp);
}

void print_data() {
    int i, j;

    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (data[i][j].name!= NULL) {
                printf("%s,%d,%.2f,%c\n", data[i][j].name, data[i][j].age, data[i][j].income, data[i][j].gender);
            }
        }
    }
}

void sort_data(int (*compare)(const void *, const void *)) {
    qsort(data, MAX_ROWS, sizeof(Person), compare);
}

int compare_age(const void *a, const void *b) {
    return (*(Person *)a).age - (*(Person *)b).age;
}

int compare_income(const void *a, const void *b) {
    return (*(Person *)b).income - (*(Person *)a).income;
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    load_data(argv[1]);
    print_data();

    sort_data(compare_age);
    print_data();

    sort_data(compare_income);
    print_data();

    return 0;
}