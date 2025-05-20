//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 65536
#define IP_HEADER_SIZE sizeof(struct ip)
#define TCP_HEADER_SIZE sizeof(struct tcphdr)
#define SLEEP_INTERVAL 5

// Function to calculate the checksum for TCP
unsigned short checksum(void *b, int len) {    
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }

    if (len == 1) {
        sum += *(unsigned char *)buf;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to monitor network quality
void monitor_network() {
    int sock_raw;
    struct sockaddr_in source, destination;
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);
    struct iphdr *iph;
    struct tcphdr *tcph;
    int data_size;

    while (1) {
        sleep(SLEEP_INTERVAL);

        // Create a raw socket that captures all packets
        sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
        if (sock_raw < 0) {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        data_size = recv(sock_raw, buffer, BUFFER_SIZE, 0);
        if (data_size < 0) {
            perror("Failed to get packets");
            continue;
        }

        // Process each packet
        iph = (struct iphdr *)(buffer + IP_HEADER_SIZE);
        tcph = (struct tcphdr *)(buffer + IP_HEADER_SIZE + IP_HEADER_SIZE);

        // Extract source and destination IP addresses
        memset(&source, 0, sizeof(source));
        memset(&destination, 0, sizeof(destination));

        source.sin_addr.s_addr = iph->saddr;
        destination.sin_addr.s_addr = iph->daddr;

        // Example paranoid measures: print and track packet information
        printf("Packet from %s to %s\n", inet_ntoa(source.sin_addr), inet_ntoa(destination.sin_addr));
        printf("Packet Size: %d bytes\n", data_size);
        printf("TCP Source Port: %d\n", ntohs(tcph->source));
        printf("TCP Destination Port: %d\n", ntohs(tcph->dest));
        printf("Checksum Validation: %s\n", (tcph->check == checksum(tcph, TCP_HEADER_SIZE)) ? "Valid" : "Invalid");
        printf("-------------------------------------------------------------------\n");

        // Close socket
        close(sock_raw);
    }

    free(buffer);
}

// Escape function to prevent code injection (paranoid mode)
void escape_input(char *input) {
    // Loop through input and modify any dangerous characters - simple example
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ';' || input[i] == '&') {
            input[i] = '_'; // Replacing dangerous characters
        }
    }
}

int main(int argc, char *argv[]) {
    char input[100];
    
    // Prompt user for network monitor start
    printf("Enter a command to start monitoring (stretch the limits): ");
    fgets(input, sizeof(input), stdin);
    escape_input(input);

    if (strstr(input, "monitor") != NULL) {
        printf("Starting the paranoid network quality of service monitor...\n");
        // Call the monitor function
        monitor_network();
    } else {
        printf("Invalid command! Staying secure...\n");
    }

    return 0;
}