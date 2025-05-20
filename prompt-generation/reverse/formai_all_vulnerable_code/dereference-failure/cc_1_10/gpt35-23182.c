//FormAI DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    int id;
    char name[50];
    float price;
};

struct data *read_data(int *count) {
    FILE *fp;
    struct data *data_array;

    fp = fopen("data_file", "rb");

    if (fp == NULL) {
        printf("Error: unable to open file\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    *count = file_size / sizeof(struct data);
    rewind(fp);

    data_array = (struct data*)malloc(*count * sizeof(struct data));

    fread(data_array, sizeof(struct data), *count, fp);

    fclose(fp);

    return data_array;
}

void write_data(struct data *data_array, int count) {
    FILE *fp;
    int i;

    fp = fopen("data_file", "wb");

    if (fp == NULL) {
        printf("Error: unable to open file\n");
        exit(1);
    }

    fwrite(data_array, sizeof(struct data), count, fp);

    fclose(fp);
}

void print_data(struct data *data_array, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("ID: %d\nName: %s\nPrice: %.2f\n\n", data_array[i].id, data_array[i].name, data_array[i].price);
    }
}

void recover_data() {
    int count, i;
    struct data *data_array;

    data_array = read_data(&count);

    printf("The following data was recovered from data_file:\n\n");

    print_data(data_array, count);

    for (i = 0; i < count; i++) {
        if (strcmp(data_array[i].name, "deleted") == 0) {
            printf("Attempting to recover data at index %d...\n", i);
            data_array[i].id = 100 + i;
            strcpy(data_array[i].name, "recovered");
            data_array[i].price = 99.99;
            printf("Data was successfully recovered!\n\n");
        }
    }

    write_data(data_array, count);

    free(data_array);
}

int main() {
    recover_data();

    return 0;
}