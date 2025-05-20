//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

// Create a custom data type to store temperature data
typedef struct {
    float temperature;
    time_t timestamp;
} TemperatureData;

// Create a linked list to store the temperature data
typedef struct Node {
    TemperatureData data;
    struct Node *next;
} Node;

// Create a global linked list to store the temperature data
Node *head = NULL;

// Function to add a new temperature data point to the linked list
void addTemperatureData(float temperature) {
    // Create a new node to store the data
    Node *newNode = (Node *)malloc(sizeof(Node));

    // Set the data in the new node
    newNode->data.temperature = temperature;
    newNode->data.timestamp = time(NULL);

    // Add the new node to the front of the linked list
    newNode->next = head;
    head = newNode;
}

// Function to print the temperature data from the linked list
void printTemperatureData() {
    // Iterate over the linked list and print the data
    Node *current = head;
    while (current != NULL) {
        printf("Temperature: %.2f°C\n", current->data.temperature);
        printf("Timestamp: %s\n", ctime(&current->data.timestamp));
        current = current->next;
    }
}

// Function to clear the temperature data from the linked list
void clearTemperatureData() {
    // Iterate over the linked list and free the nodes
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    // Set the head of the linked list to NULL
    head = NULL;
}

// Function to handle the CTRL+C signal
void signalHandler(int signal) {
    // Clear the temperature data from the linked list
    clearTemperatureData();

    // Exit the program
    exit(0);
}

int main() {
    // Set up the signal handler to handle the CTRL+C signal
    signal(SIGINT, signalHandler);

    // Get the temperature from the user
    float temperature;
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    // Add the temperature data to the linked list
    addTemperatureData(temperature);

    // Print the temperature data
    printTemperatureData();

    // Keep the program running until the user presses CTRL+C
    while (1) {
        sleep(1);
    }

    return 0;
}