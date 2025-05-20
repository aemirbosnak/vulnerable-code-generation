//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 64
#define PORT 80
#define TIMEOUT 5
#define MAX_ATTEMPTS 3

void print_error(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int ping(const char* hostname) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        print_error("socket");
    }

    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        print_error("gethostbyname");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    char buffer[BUFFER_SIZE];
    send(sock, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n"), 0);

    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            if (errno == EINTR) {
                continue;
            }
            print_error("recv");
        }

        if (bytes_received > 0 && strstr(buffer, "200 OK")) {
            close(sock);
            return 1;
        }

        usleep(100000);
        attempts++;
    }

    close(sock);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    int ping_result = ping(hostname);

    if (ping_result == 1) {
        printf("%s is reachable\n", hostname);
    } else {
        printf("%s is not reachable\n", hostname);
    }

    return 0;
}