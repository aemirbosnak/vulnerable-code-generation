//GEMINI-pro DATASET v1.0 Category: File handling ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data structure for storing data from the file
typedef struct {
    int id;
    char *name;
    int age;
    char *email;
} Person;

// Define the path to the file
#define FILE_PATH "data.txt"

// Function to read data from the file and store it in an array of structures
Person *readDataFromFile(int *size) {
    // Open the file in read mode
    FILE *file = fopen(FILE_PATH, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", FILE_PATH);
        return NULL;
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the array of structures
    *size = fileSize / sizeof(Person);
    Person *data = malloc(*size * sizeof(Person));

    // Read the data from the file and store it in the array of structures
    int i = 0;
    while (!feof(file)) {
        fscanf(file, "%d %s %d %s", &data[i].id, data[i].name, &data[i].age, data[i].email);
        i++;
    }

    // Close the file
    fclose(file);

    // Return the array of structures
    return data;
}

// Function to write data from an array of structures to a file
void writeDataToFile(Person *data, int size) {
    // Open the file in write mode
    FILE *file = fopen(FILE_PATH, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", FILE_PATH);
        return;
    }

    // Write the data from the array of structures to the file
    int i;
    for (i = 0; i < size; i++) {
        fprintf(file, "%d %s %d %s\n", data[i].id, data[i].name, data[i].age, data[i].email);
    }

    // Close the file
    fclose(file);
}

// Function to print the data from an array of structures
void printData(Person *data, int size) {
    printf("Data from the file:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d %s %d %s\n", data[i].id, data[i].name, data[i].age, data[i].email);
    }
    printf("\n");
}

// Main function
int main() {
    // Read data from the file and store it in an array of structures
    int size;
    Person *data = readDataFromFile(&size);
    if (data == NULL) {
        printf("Error reading data from file %s\n", FILE_PATH);
        return 1;
    }

    // Print the data from the array of structures
    printData(data, size);

    // Add a new person to the array of structures
    printf("Adding a new person to the array of structures:\n");
    Person newPerson = {5, "John Doe", 30, "john.doe@example.com"};
    data = realloc(data, (size + 1) * sizeof(Person));
    data[size] = newPerson;
    size++;
    
    // Write the updated data to the file
    writeDataToFile(data, size);
    
    // Print the updated data from the file
    printf("Updated data from the file:\n");
    data = readDataFromFile(&size);
    printData(data, size);

    // Free the allocated memory
    free(data);

    return 0;
}