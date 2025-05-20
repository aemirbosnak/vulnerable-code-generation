//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 1000

typedef struct {
    char *name;
    int value;
} data_t;

data_t data[MAX_SIZE];
int num_data = 0;

void add_data(char *name, int value) {
    if (num_data >= MAX_SIZE) {
        printf("Error: Maximum number of data points reached.\n");
        exit(1);
    }
    data[num_data].name = strdup(name);
    data[num_data].value = value;
    num_data++;
}

int get_data_index(char *name) {
    for (int i = 0; i < num_data; i++) {
        if (strcmp(data[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void print_data() {
    printf("Data:\n");
    for (int i = 0; i < num_data; i++) {
        printf("%s: %d\n", data[i].name, data[i].value);
    }
}

int main() {
    add_data("x", 1);
    add_data("y", 2);
    add_data("z", 3);
    print_data();

    int index = get_data_index("y");
    if (index!= -1) {
        data[index].value = 4;
        printf("Updated data:\n");
        print_data();
    }

    return 0;
}