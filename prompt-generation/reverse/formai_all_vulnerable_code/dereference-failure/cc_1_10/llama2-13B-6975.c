//LLAMA2-13B DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 10

// Structure to store the data
typedef struct {
    char name[MAX_LENGTH];
    int age;
    float height;
    char gender;
} data_t;

// Function to read the data from a file
data_t *read_data(const char *file_name) {
    data_t *data = NULL;
    int i = 0;
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        return NULL;
    }

    // Read the data from the file
    while (fscanf(file, "%s %d %f %c", data->name, &data->age, &data->height, &data->gender) == 4) {
        i++;
        data = realloc(data, (i * sizeof(data_t)));
        if (data == NULL) {
            printf("Error: Unable to allocate memory\n");
            break;
        }
        data[i - 1] = *data;
    }

    fclose(file);
    return data;
}

// Function to print the data
void print_data(data_t *data, int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("%s %d %f %c\n", data[i].name, data[i].age, data[i].height, data[i].gender);
    }
}

// Function to main function
int main() {
    data_t *data = read_data("data.txt");
    int count = sizeof(data) / sizeof(data_t);
    print_data(data, count);
    free(data);
    return 0;
}