//Falcon2-11B DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store data
struct data {
    int id;
    char name[50];
};

// Function to print the data
void printData(struct data* data) {
    printf("ID: %d, Name: %s\n", data->id, data->name);
}

int main() {
    // Create an array to store data
    struct data* dataArr = (struct data*)malloc(100 * sizeof(struct data));

    // Read data from user
    for (int i = 0; i < 100; i++) {
        printf("Enter ID (1-100): ");
        scanf("%d", &dataArr[i].id);
        fflush(stdin);

        printf("Enter Name: ");
        fgets(dataArr[i].name, sizeof(dataArr[i].name), stdin);
    }

    // Sort the data array using bubble sort
    for (int i = 0; i < 100; i++) {
        for (int j = i + 1; j < 100; j++) {
            if (dataArr[i].id > dataArr[j].id) {
                struct data temp = dataArr[i];
                dataArr[i] = dataArr[j];
                dataArr[j] = temp;
            }
        }
    }

    // Print the sorted data
    printf("Sorted Data:\n");
    for (int i = 0; i < 100; i++) {
        printData(&dataArr[i]);
    }

    // Free the memory allocated for data array
    free(dataArr);

    return 0;
}