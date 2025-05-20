//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <signal.h>

#define MAX_PACKETS 100
#define MAX_BYTES 1024

// Global variables
int sockfd;
struct sockaddr_in servaddr;
pcap_t *handle;
char errbuf[PCAP_ERRBUF_SIZE];

// Function to handle SIGINT signal
void signal_handler(int signum) {
    printf("\nExiting...\n");
    pcap_close(handle);
    close(sockfd);
    exit(0);
}

int main() {
    // Initialize signal handler
    signal(SIGINT, signal_handler);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(5000);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Open the network interface
    handle = pcap_open_live("en0", 1024, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening network interface: %s\n", errbuf);
        exit(1);
    }

    // Loop forever and listen for packets
    while (1) {
        // Receive a packet
        char buf[MAX_BYTES];
        struct sockaddr_in sender;
        socklen_t sender_len = sizeof(sender);
        int n = recvfrom(sockfd, buf, MAX_BYTES, 0, (struct sockaddr *)&sender, &sender_len);
        if (n < 0) {
            perror("recvfrom");
            continue;
        }

        // Parse the packet
        struct pcap_pkthdr *header;
        const u_char *data;
        int res = pcap_next_ex(handle, &header, &data);
        if (res == 1) {
            // Packet received successfully
            // Check for suspicious activity
            if (data[12] == 0x6 || data[12] == 0x7) {
                // TCP or UDP packet
                if (data[23] == 0x0) {
                    // SYN packet
                    printf("Possible SYN flood attack from %s\n", inet_ntoa(sender.sin_addr));
                }
            }
        }
    }

    // Close the socket and network interface
    pcap_close(handle);
    close(sockfd);

    return 0;
}