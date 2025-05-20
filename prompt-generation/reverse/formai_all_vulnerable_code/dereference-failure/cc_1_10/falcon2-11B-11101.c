//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to get the signal strength of a Wi-Fi network
float getSignalStrength(char* ssid) {
    int status;
    struct hostent* server;
    struct in_addr* addr_list;
    unsigned char mac[6];
    float signalStrength = 0.0;

    // Create a socket
    status = socket(AF_INET, SOCK_DGRAM, 0);
    if (status < 0) {
        printf("Error: Unable to create socket\n");
        return -1.0;
    }

    // Get the MAC address of the Wi-Fi network
    status = getsockname(status, (struct sockaddr*)&mac, sizeof(mac));
    if (status < 0) {
        printf("Error: Unable to get MAC address\n");
        return -1.0;
    }

    // Get the IP address of the Wi-Fi network
    status = gethostbyaddr((const char*)&mac, sizeof(mac), AF_INET);
    if (status < 0) {
        printf("Error: Unable to get IP address\n");
        return -1.0;
    }

    // Get the hostname of the Wi-Fi network
    server = gethostbyaddr((const char*)&mac, sizeof(mac), AF_INET);
    if (server == NULL) {
        printf("Error: Unable to get hostname\n");
        return -1.0;
    }

    // Get the IP address of the Wi-Fi network
    addr_list = (struct in_addr*)server->h_addr_list;
    if (addr_list == NULL) {
        printf("Error: Unable to get IP address\n");
        return -1.0;
    }

    // Convert the IP address to a float
    signalStrength = (float)ntohs(addr_list->s_addr) / 256.0;

    return signalStrength;
}

// Main function
int main() {
    char ssid[100];
    printf("Enter the SSID of the Wi-Fi network: ");
    fgets(ssid, sizeof(ssid), stdin);
    ssid[strcspn(ssid, "\n")] = '\0'; // Remove the newline character

    float signalStrength = getSignalStrength(ssid);
    printf("Signal strength of %s: %f\n", ssid, signalStrength);

    return 0;
}