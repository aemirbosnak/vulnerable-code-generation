//Falcon-180B DATASET v1.0 Category: Firewall ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define IP "127.0.0.1"
#define LOG_FILE "firewall.log"

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(IP);
    server_addr.sin_port = htons(PORT);

    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        char* request = strtok(buffer, "\r\n");
        while (request!= NULL) {
            char* method = strtok(request, " ");
            char* path = strtok(NULL, " ");

            if (strcmp(method, "GET") == 0) {
                if (strstr(path, ".php")!= NULL) {
                    send(sock, "HTTP/1.1 403 Forbidden\r\nContent-Length: 0\r\n\r\n", strlen("HTTP/1.1 403 Forbidden\r\nContent-Length: 0\r\n\r\n"), 0);
                } else {
                    send(sock, "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n", strlen("HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n"), 0);
                }
            } else {
                send(sock, "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n", strlen("HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n"), 0);
            }

            request = strtok(NULL, "\r\n");
        }
    }

    close(sock);
    return 0;
}