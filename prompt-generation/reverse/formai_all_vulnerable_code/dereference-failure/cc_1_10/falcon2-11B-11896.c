//Falcon2-11B DATASET v1.0 Category: Classical Circuit Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Function to read the circuit from a file and store it in an array of arrays
void read_circuit(char* filename, int* array[], int size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    int num_nodes = 0;
    int num_connections = 0;
    int node_index = 0;

    char node_type[3];
    int node_index1;
    int node_index2;
    int connection_type;

    while (fscanf(file, "%s %d %d %d %d", node_type, &node_index1, &node_index2, &connection_type)!= EOF) {
        if (strcmp(node_type, "AND") == 0) {
            array[node_index][num_connections] = 1;
            array[node_index1][num_connections] = 1;
            array[node_index2][num_connections] = 1;
            num_connections++;
        } else if (strcmp(node_type, "OR") == 0) {
            array[node_index][num_connections] = 1;
            array[node_index1][num_connections] = 1;
            array[node_index2][num_connections] = 1;
            num_connections++;
        } else if (strcmp(node_type, "NOT") == 0) {
            array[node_index][num_connections] = -1;
            num_connections++;
        }

        num_nodes++;
    }

    fclose(file);

    if (num_nodes > size) {
        printf("Error: circuit is too large\n");
        return;
    }

    int* new_array = (int*)malloc(num_nodes * sizeof(int));
    if (new_array == NULL) {
        printf("Error allocating memory\n");
        return;
    }

    memcpy(new_array, array, num_nodes * sizeof(int));
    free(array);

    array = new_array;
    size = num_nodes;
}

// Function to simulate the circuit
void simulate(int* array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        int value = 0;
        for (int j = 0; j < size; j++) {
            if (array[i][j]!= 0) {
                value |= array[i][j];
            }
        }
        printf("%d ", value);
    }
    printf("\n");
}

// Function to write the results to a file
void write_results(char* filename, int* array[], int size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    int i;
    for (i = 0; i < size; i++) {
        fprintf(file, "%d ", array[i]);
    }
    fprintf(file, "\n");

    fclose(file);
}

int main() {
    int array[5][5] = {
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1}
    };

    int size = 5;

    read_circuit("circuit.txt", array, size);
    simulate(array, size);
    write_results("results.txt", array, size);

    return 0;
}