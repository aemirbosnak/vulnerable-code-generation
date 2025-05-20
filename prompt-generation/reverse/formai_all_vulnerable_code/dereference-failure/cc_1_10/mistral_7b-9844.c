//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <time.h>

#define SERVER_ADDRESS "8.8.8.8"
#define SERVER_PORT 53
#define BUFFER_SIZE 1024
#define PACKET_SIZE 1024
#define TIMEOUT 5000

int main() {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    double start_time, end_time, elapsed_time, send_time, receive_time;
    struct hostent *server;
    int i, j;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(SERVER_ADDRESS);
    if (server == NULL) {
        fprintf(stderr, "Error, unknown server\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    printf("Internet Speed Test Application\n");
    printf("------------------------------\n");

    for (i = 0; i < 5; i++) {
        start_time = time(NULL);
        send_time = time(NULL);

        memset(buffer, 0, PACKET_SIZE);
        strncat(buffer, "this is a test", 14);

        if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Error sending UDP datagram");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, BUFFER_SIZE);
        n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);

        if (n < 0) {
            perror("Error receiving UDP datagram");
            exit(EXIT_FAILURE);
        }

        end_time = time(NULL);
        receive_time = end_time - start_time;
        elapsed_time = end_time - send_time;

        printf("Test %d:\n", i + 1);
        printf("  Data sent: %s\n", buffer);
        printf("  Data received: %s\n", buffer);
        printf("  Send time: %f seconds\n", elapsed_time);
        printf("  Receive time: %f seconds\n", receive_time);
        printf("  Round trip time: %f seconds\n", elapsed_time + receive_time);
        printf("  Throughput: %.2f KB/s\n\n", (PACKET_SIZE * 8 * 5) / (elapsed_time + receive_time * 2));

        sleep(1);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}