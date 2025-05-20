//FormAI DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
    int id;
    char name[50];
    double price;
} Data;

int main() {
    char filename[50];
    printf("Enter the name of the CSV file to read: ");
    scanf("%s", filename);

    FILE *csv_file = fopen(filename, "r");
    if (csv_file == NULL) {
        printf("Error: Cannot open file\n");
        return 1;
    }

    char line[100];
    fgets(line, sizeof(line), csv_file); // skip the header line

    Data data_array[100];
    int data_count = 0;

    while (fgets(line, sizeof(line), csv_file)) {
        Data data;
        char *token = strtok(line, ",");
        data.id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(data.name, token);

        token = strtok(NULL, ",");
        data.price = atof(token);

        data_array[data_count++] = data;
    }

    fclose(csv_file);

    FILE *bin_file = fopen("data.bin", "wb");
    fwrite(&data_count, sizeof(data_count), 1, bin_file);
    fwrite(data_array, sizeof(Data), data_count, bin_file);
    fclose(bin_file);

    printf("Data mining completed. Data saved to data.bin\n");

    return 0;
}