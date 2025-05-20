//FormAI DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 1024 // Define the buffer size to be used for sending and receiving data

// Define a structure that will hold the data for a scan thread
struct ScanThreadData {
    char* ipAddr; // The IP address to scan
    int startPort; // The starting port number to scan
    int endPort; // The ending port number to scan
};

// Define the function that will be run by each scan thread
void* ScanThread(void* threadData) {
    struct ScanThreadData* data = (struct ScanThreadData*)threadData; // Cast the thread data to its actual type
    int sock; // Define a variable to hold the socket file descriptor
    
    // Create a socket for the scan thread
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error creating socket for scan thread\n");
        pthread_exit(NULL); // End the thread
    }
    
    // Define the address structure with the IP address to scan and the starting port number
    struct sockaddr_in scanAddr;
    memset(&scanAddr, 0, sizeof(scanAddr));
    scanAddr.sin_family = AF_INET;
    scanAddr.sin_addr.s_addr = inet_addr(data->ipAddr);
    scanAddr.sin_port = htons(data->startPort);
    
    // Loop through all ports to be scanned, attempting to connect to each one
    for(int port = data->startPort; port <= data->endPort; ++port) {
        scanAddr.sin_port = htons(port); // Set the port number in the address structure
        
        // Attempt to connect to the port
        if(connect(sock, (struct sockaddr*)&scanAddr, sizeof(scanAddr)) < 0) {
            continue; // If the connection fails, move on to the next port
        }
        
        // If the connection succeeds, print out a message indicating which port was opened
        printf("Port %d is open on IP address %s\n", port, data->ipAddr);
    }
    
    close(sock); // Close the socket file descriptor
    pthread_exit(NULL); // End the thread
}

// Define the main function
int main(int argc, char* argv[]) {
    if(argc < 4) {
        fprintf(stderr, "Usage: %s <IP Address> <Starting Port> <Ending Port>\n", argv[0]); // Print the correct usage to the standard error stream
        return 1; // Return a non-zero exit code to indicate failure
    }
    
    char* ipAddr = argv[1]; // Get the IP address string from the command line arguments
    int startPort = atoi(argv[2]); // Get the starting port number from the command line arguments
    int endPort = atoi(argv[3]); // Get the ending port number from the command line arguments
    
    // If the starting port number is greater than the ending port number, swap them
    if(startPort > endPort) {
        int temp = startPort;
        startPort = endPort;
        endPort = temp;
    }
    
    pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t) * (endPort - startPort + 1)); // Allocate memory for an array of thread identifiers
    
    // Create a scan thread for each port to be scanned
    for(int port = startPort; port <= endPort; ++port) {
        struct ScanThreadData* data = (struct ScanThreadData*)malloc(sizeof(struct ScanThreadData)); // Allocate memory for the scan thread data structure
        data->ipAddr = ipAddr; // Set the IP address to scan in the scan thread data structure
        data->startPort = port; // Set the starting port number to scan in the scan thread data structure
        data->endPort = port; // Set the ending port number to scan in the scan thread data structure
        
        pthread_create(&threads[port - startPort], NULL, ScanThread, data); // Create the scan thread
    }
    
    // Wait for all scan threads to finish
    for(int i = 0; i <= endPort - startPort; ++i) {
        pthread_join(threads[i], NULL);
    }
    
    free(threads); // Free the memory allocated for the thread identifiers
    
    return 0; // Return zero to indicate success
}