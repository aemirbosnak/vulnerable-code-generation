//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void test_internet_speed(const char* server_ip) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    long long start_time = time(NULL);
    send(sockfd, "GET / HTTP/1.1\r\nHost: localhost\r\nUser-Agent: Minimalistic-C-Speed-Test\r\nAccept: */*\r\n\r\n", 49, 0);

    long long data_received = 0;
    while (1) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received <= 0) {
            break;
        }

        data_received += bytes_received;
        memset(buffer + bytes_received, 0, bytes_received);
    }

    close(sockfd);

    long long end_time = time(NULL);
    double transfer_rate = (data_received / (end_time - start_time));
    printf("Internet Speed Test Result:\nTransfer rate: %.2f KB/s\n", transfer_rate / 1024.0);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    test_internet_speed(argv[1]);

    return EXIT_SUCCESS;
}