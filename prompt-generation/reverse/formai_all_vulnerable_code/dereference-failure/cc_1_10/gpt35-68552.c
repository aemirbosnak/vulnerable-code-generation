//FormAI DATASET v1.0 Category: Firewall ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <signal.h>

// Define the default IP address and port number
#define DEFAULT_IP_ADDRESS "127.0.0.1"
#define DEFAULT_PORT 8080

// Define the maximum packet size
#define MAX_PACKET_SIZE 65536

// Define the structure of a packet
typedef struct packet {
    struct iphdr ip;
    struct icmphdr icmp;
    char data[MAX_PACKET_SIZE - sizeof(struct iphdr) - sizeof(struct icmphdr)];
} packet;

int sockfd;

// Handler function for catching CTRL+C signal
void interrupt_handler(int signal) {
    printf("\nCTRL+C received. Closing the firewall...\n");
    close(sockfd); // Close the socket
    exit(0); // Exit the program
}

// Function for sending packets
void send_packet(struct sockaddr_in *dest_addr, unsigned char *packet_buffer, int packet_size) {
    if (sendto(sockfd, packet_buffer, packet_size, 0, (struct sockaddr *)dest_addr, sizeof(struct sockaddr)) < 0) {
        perror("sendto() failed"); // Print an error message if the packet sending fails
    }
}

int main(int argc, char **argv) {
    // Print a welcome message
    printf("Welcome to the C Firewall!\n");

    // Set up the CTRL+C signal handler
    signal(SIGINT, interrupt_handler);

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("socket() failed"); // Print an error message if the socket creation fails
        exit(1); // Exit the program
    }

    // Disable IP header inclusion on raw sockets
    const int disable = 0;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &disable, sizeof(disable)) < 0 ) {
        perror("setsockopt() failed"); // Print an error message if the socket option setting fails
        exit(1); // Exit the program
    }

    // Set the socket to receive broadcast packets
    const int broadcast = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) < 0) {
        perror("setsockopt() failed"); // Print an error message if the socket option setting fails
        exit(1); // Exit the program
    }

    // Parse command line arguments (IP address and port number)
    char *ip_address = argc > 1 ? argv[1] : DEFAULT_IP_ADDRESS;
    int port = argc > 2 ? atoi(argv[2]) : DEFAULT_PORT;

    // Prepare the destination address structure
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &dest_addr.sin_addr) <= 0) {
        perror("inet_pton() failed"); // Print an error message if the IP address conversion fails
        exit(1); // Exit the program
    }

    // Create the packet
    packet my_packet;
    memset(&my_packet, 0, sizeof(my_packet));
    my_packet.ip.version = 4;
    my_packet.ip.ihl = 5;
    my_packet.ip.tos = 0;
    my_packet.ip.tot_len = sizeof(struct iphdr) + sizeof(struct icmphdr);
    my_packet.ip.id = htons(1);
    my_packet.ip.frag_off = htons(0);
    my_packet.ip.ttl = 255;
    my_packet.ip.protocol = IPPROTO_ICMP;
    my_packet.ip.check = htons(0);
    my_packet.ip.saddr = inet_addr("192.168.0.100");
    my_packet.icmp.type = ICMP_ECHO;
    my_packet.icmp.code = 0;
    my_packet.icmp.checksum = htons(~(ICMP_ECHO << 8));

    // Send the packet
    send_packet(&dest_addr, (unsigned char *)&my_packet, my_packet.ip.tot_len);

    // Receive the response packet
    unsigned char packet_buffer[MAX_PACKET_SIZE];
    memset(packet_buffer, 0, sizeof(packet_buffer));
    int packet_size = recv(sockfd, packet_buffer, sizeof(packet_buffer), 0);
    if (packet_size < 0) {
        perror("recv() failed"); // Print an error message if the packet receiving fails
    } else {
        printf("Received packet with size %d\n", packet_size);
    }

    // Close the socket
    close(sockfd);

    // Print a goodbye message
    printf("Goodbye from the C Firewall!\n");

    return 0;
}