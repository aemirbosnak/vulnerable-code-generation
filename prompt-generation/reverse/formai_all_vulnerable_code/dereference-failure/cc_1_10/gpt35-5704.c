//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_ROW_SIZE 1000
#define MAX_COL_SIZE 100

typedef struct {
    int row;
    int col;
    char **data;
} CSV_Data;

CSV_Data *csv_data = NULL;
int num_rows = 0;
int num_cols = 0;

pthread_mutex_t lock;

void csv_reader(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[MAX_ROW_SIZE];
    int count = 0;
    while (fgets(line, MAX_ROW_SIZE, fp)) {
        if (count == 0) {
            char *token = strtok(line, ",");
            while (token != NULL) {
                num_cols++;
                token = strtok(NULL, ",");
            }
            csv_data = (CSV_Data*)malloc(sizeof(CSV_Data));
            csv_data->row = num_rows;
            csv_data->col = num_cols;
            csv_data->data = (char**)malloc(sizeof(char*)*num_rows*num_cols);
        }

        char *token = strtok(line, ",");
        int i = 0;
        while (token != NULL) {
            pthread_mutex_lock(&lock);
            csv_data->data[count*num_cols+i] = strdup(token);
            pthread_mutex_unlock(&lock);
            i++;
            token = strtok(NULL, ",");
        }
        count++;
        num_rows++;
    }
    fclose(fp);
}

void print_csv_data() {
    for (int i=0; i<num_rows; i++) {
        for (int j=0; j<num_cols; j++) {
            printf("%s ", csv_data->data[i*num_cols+j]);
        }
        printf("\n");
    }
}

void free_csv_data() {
    for (int i=0; i<num_rows; i++) {
        for (int j=0; j<num_cols; j++) {
            free(csv_data->data[i*num_cols+j]);
        }
    }
    free(csv_data->data);
    free(csv_data);
}

int main() {
    csv_reader("data.csv");
    print_csv_data();
    free_csv_data();
    return 0;
}