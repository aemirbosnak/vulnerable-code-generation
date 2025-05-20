//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 1000000

struct data_t {
    char name[10];
    int age;
    char email[50];
};

struct data_t* read_csv(FILE* file) {
    struct data_t* data = NULL;
    size_t size = 0;

    if (file == NULL) {
        fprintf(stderr, "Error: Invalid file pointer\n");
        return NULL;
    }

    if (fscanf(file, "%s %d %s", data->name, &data->age, data->email)!= 3) {
        fprintf(stderr, "Error: Failed to read CSV data\n");
        return NULL;
    }

    size = sizeof(struct data_t) + strlen(data->name) + 1 + strlen(data->email) + 1;

    data = realloc(data, size);
    if (data == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory\n");
        return NULL;
    }

    return data;
}

int main() {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file\n");
        return 1;
    }

    struct data_t* data = NULL;
    while ((data = read_csv(file))!= NULL) {
        printf("%s, %d, %s\n", data->name, data->age, data->email);
    }

    fclose(file);

    return 0;
}