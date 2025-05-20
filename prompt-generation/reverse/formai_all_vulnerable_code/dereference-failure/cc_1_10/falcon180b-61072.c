//Falcon-180B DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

void read_csv(char* filename, Person data[][MAX_ROWS]) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int rows = 0;
    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (rows >= MAX_ROWS) {
            printf("Maximum number of rows exceeded.\n");
            exit(1);
        }

        char* token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }

        data[0][rows].id = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            continue;
        }

        strncpy(data[0][rows].name, token, sizeof(data[0][rows].name));
        token = strtok(NULL, ",");
        if (token == NULL) {
            continue;
        }

        data[0][rows].age = atoi(token);
        rows++;
    }

    fclose(fp);
}

void print_data(Person data[][MAX_ROWS], int start_row, int end_row) {
    for (int i = start_row; i <= end_row; i++) {
        printf("%d\t%s\t%d\n", data[0][i].id, data[0][i].name, data[0][i].age);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <start_row> <end_row>\n", argv[0]);
        return 1;
    }

    char filename[1024] = {0};
    strncpy(filename, argv[1], sizeof(filename));

    int start_row = atoi(argv[2]);
    int end_row = atoi(argv[3]);

    Person data[MAX_ROWS][MAX_COLS];

    read_csv(filename, data);

    print_data(data, start_row, end_row);

    return 0;
}