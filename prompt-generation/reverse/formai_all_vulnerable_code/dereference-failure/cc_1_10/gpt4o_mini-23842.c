//GPT-4o-mini DATASET v1.0 Category: Network Packet Monitoring ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_PACKET_SIZE 65536
#define PORT 8080
#define ADDR "127.0.0.1"

// Function prototype for packet capture
void packet_handler(unsigned char *args, const struct pcap_pkthdr *header, const unsigned char *packet);
void start_capture(void);
void start_server(void);
void start_client(void);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [server|client]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        start_client();
    } else {
        fprintf(stderr, "Invalid argument! Use 'server' or 'client'.\n");
        return 1;
    }

    return 0;
}

void start_capture(void) {
    pcap_if_t *alldevs;
    pcap_if_t *d;
    char errbuf[PCAP_ERRBUF_SIZE];

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Could not find any devices: %s\n", errbuf);
        return;
    }

    for (d = alldevs; d != NULL; d = d->next) {
        printf("Capturing on device: %s\n", d->name);
        break; // Only capture on first device
    }

    pcap_t *handle = pcap_open_live(d->name, MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", d->name, errbuf);
        return;
    }

    pcap_loop(handle, 10, packet_handler, NULL);
    pcap_close(handle);
}

void packet_handler(unsigned char *args, const struct pcap_pkthdr *header, const unsigned char *packet) {
    printf("Packet captured: Length: %d\n", header->len);
    // Here we can add more logic to analyze the packet if needed.
}

void start_server(void) {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[MAX_PACKET_SIZE];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ADDR);
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on %s:%d\n", ADDR, PORT);
    
    while (1) {
        int n = recvfrom(sockfd, (char *)buffer, MAX_PACKET_SIZE, 
                         MSG_WAITALL, (struct sockaddr *)&client_addr, &addr_len);
        buffer[n] = '\0';
        printf("Received packet from client: %s\n", buffer);
    }

    close(sockfd);
}

void start_client(void) {
    int sockfd;
    struct sockaddr_in server_addr;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ADDR);
    server_addr.sin_port = htons(PORT);
    
    char *dummy_packet = "Hello from client!";
    sendto(sockfd, (const char *)dummy_packet, strlen(dummy_packet), 
           MSG_CONFIRM, (const struct sockaddr *)&server_addr, sizeof(server_addr));
    
    printf("Packet sent to server: %s\n", dummy_packet);
    close(sockfd);
}