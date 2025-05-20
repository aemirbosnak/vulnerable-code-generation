//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5

void print_error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* ip_address = argv[1];
    int port = atoi(argv[2]);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        print_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    time_t start_time = time(NULL);

    while (bytes_received < BUFFER_SIZE) {
        int bytes_sent = send(socket_fd, "PING", strlen("PING"), 0);
        if (bytes_sent == -1) {
            print_error("send");
        }

        int timeout = TIMEOUT;
        while (timeout > 0) {
            int bytes_available = recv(socket_fd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
            if (bytes_available == -1) {
                if (errno == EAGAIN) {
                    usleep(100000); // 100ms
                } else {
                    print_error("recv");
                }
            } else if (bytes_available == 0) {
                print_error("Connection closed by server");
            } else {
                bytes_received += bytes_available;
            }

            timeout--;
        }
    }

    close(socket_fd);

    if (bytes_received == BUFFER_SIZE) {
        printf("Ping successful\n");
    } else {
        printf("Ping failed\n");
    }

    return 0;
}