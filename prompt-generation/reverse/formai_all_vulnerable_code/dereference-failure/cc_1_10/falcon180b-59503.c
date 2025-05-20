//Falcon-180B DATASET v1.0 Category: Data mining ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1000
#define MAX_NUM_DATA 100

typedef struct {
    char *data;
    int frequency;
} Data;

Data *data_array;
int num_data;

void initialize_data_array() {
    data_array = (Data *) malloc(MAX_NUM_DATA * sizeof(Data));
    num_data = 0;
}

void add_data(char *new_data) {
    int i;
    for (i = 0; i < num_data; i++) {
        if (strcmp(data_array[i].data, new_data) == 0) {
            data_array[i].frequency++;
            return;
        }
    }
    if (num_data >= MAX_NUM_DATA) {
        printf("Error: Maximum number of data reached.\n");
        exit(1);
    }
    data_array[num_data].data = (char *) malloc(strlen(new_data) + 1);
    strcpy(data_array[num_data].data, new_data);
    data_array[num_data].frequency = 1;
    num_data++;
}

void print_data_array() {
    int i;
    for (i = 0; i < num_data; i++) {
        printf("%s: %d\n", data_array[i].data, data_array[i].frequency);
    }
}

int main() {
    initialize_data_array();

    char input_data[MAX_DATA_SIZE];
    while (1) {
        printf("Enter a data (or type 'exit' to quit): ");
        fgets(input_data, MAX_DATA_SIZE, stdin);
        input_data[strcspn(input_data, "\n")] = '\0';
        if (strcmp(input_data, "exit") == 0) {
            break;
        }
        add_data(input_data);
    }

    print_data_array();

    free(data_array);
    return 0;
}