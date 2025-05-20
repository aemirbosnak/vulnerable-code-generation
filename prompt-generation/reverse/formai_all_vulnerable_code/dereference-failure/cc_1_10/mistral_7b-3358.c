//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: careful
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_ADDRESS "8.8.8.8"
#define BUFFER_SIZE 1024
#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0

int main(int argc, char *argv[]) {
    int sockfd, rc, i;
    char send_buf[BUFFER_SIZE], receive_buf[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <destination IP address>\n", argv[0]);
        exit(1);
    }

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket creation error");
        exit(1);
    }

    // Set server address
    server = gethostbyname(SERVER_ADDRESS);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(ICMP_ECHO_REQUEST);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    // Ping the destination IP address
    for (i = 1; i <= 4; i++) {
        // Prepare ICMP echo request message
        send_buf[0] = ICMP_ECHO_REQUEST;
        send_buf[1] = (char)(i & 0xFF);
        send_buf[2] = (char)((i >> 8) & 0xFF);

        // Send the message to the server
        rc = sendto(sockfd, send_buf, sizeof(send_buf), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        if (rc < 0) {
            perror("sendto");
            exit(1);
        }

        // Receive ICMP echo reply message
        ssize_t len = recvfrom(sockfd, receive_buf, sizeof(receive_buf), 0, NULL, NULL);
        if (len < 0) {
            perror("recvfrom");
            exit(1);
        }

        // Check if the received message is an ICMP echo reply
        if (receive_buf[0] == ICMP_ECHO_REPLY) {
            printf("Reply received from %s: time = %d ms\n", inet_ntoa(*((struct in_addr *)(&serv_addr))), i * 500 / 2);
        } else {
            printf("Request sent to %s timed out\n", argv[1]);
            break;
        }

        // Wait for some time before sending the next message
        usleep(500000);
    }

    // Close the socket
    close(sockfd);
    return 0;
}