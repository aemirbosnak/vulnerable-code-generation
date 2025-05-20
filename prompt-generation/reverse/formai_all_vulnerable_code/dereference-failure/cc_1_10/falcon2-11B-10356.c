//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// Define the Data structure for visualization
struct Data{
    int id;
    float x;
    float y;
    float z;
    char name[100];
};

// Function to display the data in a tree like structure
void displayData(struct Data *data, int size) {
    for(int i = 0; i < size; i++){
        printf("ID: %d\n", data[i].id);
        printf("Name: %s\n", data[i].name);
        printf("X: %.2f\n", data[i].x);
        printf("Y: %.2f\n", data[i].y);
        printf("Z: %.2f\n\n", data[i].z);
    }
}

// Function to add a new node to the tree like structure
void addNode(struct Data *data, int *size, int new_id, float new_x, float new_y, float new_z, char *new_name) {
    struct Data new_node;
    new_node.id = new_id;
    new_node.x = new_x;
    new_node.y = new_y;
    new_node.z = new_z;
    strcpy(new_node.name, new_name);
    data[*size].id = new_id;
    data[*size].x = new_x;
    data[*size].y = new_y;
    data[*size].z = new_z;
    strcpy(data[*size].name, new_name);
    (*size)++;
}

// Function to remove a node from the tree like structure
void removeNode(struct Data *data, int *size, int remove_id) {
    for(int i = remove_id; i < *size; i++) {
        data[i-1] = data[i];
    }
    (*size)--;
}

// Main function
int main() {
    srand(time(0));

    // Allocate memory for the Data structure
    struct Data *data = (struct Data*)malloc(100 * sizeof(struct Data));
    int size = 0;

    // Add some random nodes to the tree like structure
    for(int i = 0; i < 100; i++) {
        data[size].id = rand() % 100;
        data[size].x = (float)rand() / (float)(RAND_MAX) * 10;
        data[size].y = (float)rand() / (float)(RAND_MAX) * 10;
        data[size].z = (float)rand() / (float)(RAND_MAX) * 10;
        strcpy(data[size].name, "Node");
        addNode(data, &size, data[size].id, data[size].x, data[size].y, data[size].z, data[size].name);
    }

    // Display the data in a tree like structure
    displayData(data, size);

    // Add a new node to the tree like structure
    float new_x = (float)rand() / (float)(RAND_MAX) * 10;
    float new_y = (float)rand() / (float)(RAND_MAX) * 10;
    float new_z = (float)rand() / (float)(RAND_MAX) * 10;
    char new_name[100];
    sprintf(new_name, "Node %d", rand() % 100);
    addNode(data, &size, size, new_x, new_y, new_z, new_name);

    // Display the updated data in a tree like structure
    displayData(data, size);

    // Remove a node from the tree like structure
    removeNode(data, &size, size);

    // Display the updated data in a tree like structure
    displayData(data, size);

    free(data);
    return 0;
}