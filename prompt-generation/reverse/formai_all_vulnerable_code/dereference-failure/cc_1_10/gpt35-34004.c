//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>
#include <signal.h>

// Function to print scan results
void displayScanResults(char* network_name[], char* mac_id[]) {
    printf("\n-----------------------SCAN RESULTS-----------------------\n");
    for(int i = 0; i < 10; i++) {
        printf("Network Name: %s\t\tMAC ID: %s\n", network_name[i], mac_id[i]);
    }
    printf("------------------------------------------------------------\n");
}

// Function to check if string is a valid MAC address
int isValidMacAddress(char* mac_address) {
    int length = strlen(mac_address), count = 0;

    // Check if length is not 17, if so, it cannot be a valid MAC address
    if(length != 17) {
        return 0;
    }

    // Iterate over the string to check if its valid
    for(int i = 0; i < length; i++) {
        if(mac_address[i] == ':') {
            count++;
        }
        else if(!isxdigit(mac_address[i])) {
            return 0;
        }
    }

    // If the count of ':' is not 5, then it cannot be a valid MAC Address
    if(count != 5) {
        return 0;
    }

    return 1;
}

// Handler function to catch signals so that we can cleanup
void signalHandler(int sig) {
    signal(SIGINT, signalHandler);
}

int main() {
    signal(SIGINT, signalHandler);

    // Create a socket to receive radio information
    int sd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(sd < 0) {
        printf("Error opening raw socket: %s\n", strerror(errno));
        return -1;
    }
    int broadcastPermission = 1;
    if(setsockopt(sd, SOL_SOCKET, SO_BROADCAST, (void *)&broadcastPermission, sizeof(broadcastPermission)) < 0) {
        printf("Error setting broadcast permission: %s\n", strerror(errno));
        close(sd);
        return -1;
    }

    // Set up the socket address for broadcast information
    struct sockaddr_in broadcastAddress;
    memset(&broadcastAddress, 0, sizeof(broadcastAddress));
    broadcastAddress.sin_family = AF_INET;
    broadcastAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    broadcastAddress.sin_port = htons(8888);

    // Bind to the port
    if(bind(sd, (struct sockaddr*)&broadcastAddress, sizeof(broadcastAddress)) < 0) {
        printf("Error binding to raw socket: %s\n", strerror(errno));
        close(sd);
        return -1;
    }

    // Create a buffer to receive data
    char buffer[1024];
    struct sockaddr_in sender;
    socklen_t senderSize = sizeof(sender);

    // Initialize arrays to store found MAC IDs and Network Names
    char* mac_id[10];
    char* network_name[10];
    for(int i = 0; i < 10; i++) {
        mac_id[i] = malloc(18);
        network_name[i] = malloc(32);
    }

    int num_scans = 0;

    while(num_scans < 10) {
        // Receive the broadcast message
        ssize_t bytesRead = recvfrom(sd, buffer, sizeof(buffer), 0, (struct sockaddr*)&sender, &senderSize);

        // Check if the received data is a valid MAC address
        if(bytesRead >= 17 && buffer[2] == '-' && buffer[5] == '-' && buffer[8] == '-' && buffer[11] == '-' && buffer[14] == '-') {
            if(isValidMacAddress(buffer)) {
                int duplicate = 0;
                for(int i = 0; i < num_scans; i++) {
                    if(strcmp(mac_id[i], buffer) == 0) {
                        duplicate = 1;
                        break;
                    }
                }
                if(duplicate == 0) {
                    strcpy(mac_id[num_scans], buffer);
                    strcpy(network_name[num_scans], inet_ntoa(sender.sin_addr));
                    num_scans++;
                }
            }
        }
    }

    // Display the scan results
    displayScanResults(network_name, mac_id);

    // Free up the allocated memory
    for(int i = 0; i < 10; i++) {
        free(mac_id[i]);
        free(network_name[i]);
    }

    // Close the socket
    close(sd);

    return 0;
}