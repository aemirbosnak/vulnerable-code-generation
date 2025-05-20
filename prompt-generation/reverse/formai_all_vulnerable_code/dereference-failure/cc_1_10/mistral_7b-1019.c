//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define PACKET_SIZE 1472

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in serv_addr;

    // Initialize socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        die("socket: cannot create socket");

    // Set up server address information
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &serv_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        die("connect: failed to connect to server");

    clock_t start_time = clock();

    char buffer[BUFFER_SIZE];

    for (size_t i = 0; i < PACKET_SIZE / sizeof(int); i++) {
        // Send a request to the server
        send(sockfd, &i, sizeof(int), 0);

        // Receive the response from the server
        ssize_t bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            die("recv: error receiving data from server");
        }

        // Check if the received data matches the sent request
        if (i != *(int *) buffer) {
            fprintf(stderr, "Data corruption detected\n");
            break;
        }
    }

    clock_t end_time = clock();

    close(sockfd);

    // Calculate and print the internet speed in bytes per second
    double elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    double data_transferred = (double) PACKET_SIZE * (PACKET_SIZE / sizeof(int)) * 8;
    printf("Internet speed: %.2f bytes/second\n", data_transferred / elapsed_time);

    return EXIT_SUCCESS;
}