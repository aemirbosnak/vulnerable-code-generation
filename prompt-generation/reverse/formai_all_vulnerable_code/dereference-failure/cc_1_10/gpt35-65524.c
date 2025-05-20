//FormAI DATASET v1.0 Category: Data mining ; Style: configurable
#include <stdio.h>

// Function to calculate mean of an array
float calc_mean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (float) sum / size;
}

// Function to calculate standard deviation of an array
float calc_std_dev(int arr[], int size, float mean) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }
    return sqrt(sum / size);
}

// Function to read input from a file and populate an array
int read_input_from_file(char *filename, int arr[], int max_size) {
    int size = 0;
    FILE *fp = fopen(filename, "r");
    if (fp) {
        while (fscanf(fp, "%d", &arr[size]) == 1 && size < max_size) {
            size++;
        }
        fclose(fp);
    }
    return size;
}

int main(int argc, char *argv[]) {
    int max_size = 100;
    char *filename = "input.txt";
    if (argc > 1) {
        max_size = atoi(argv[1]);
    }
    if (argc > 2) {
        filename = argv[2];
    }
    int arr[max_size];
    int size = read_input_from_file(filename, arr, max_size);
    if (size > 0) {
        float mean = calc_mean(arr, size);
        float std_dev = calc_std_dev(arr, size, mean);
        printf("Mean: %f\n", mean);
        printf("Standard Deviation: %f\n", std_dev);
    } else {
        printf("Unable to read from input file.\n");
    }
    return 0;
}