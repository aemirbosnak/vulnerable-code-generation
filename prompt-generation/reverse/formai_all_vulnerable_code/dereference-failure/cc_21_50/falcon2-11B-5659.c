//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];

    // Allocate memory for the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure the socket
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);
    portno = htons(atoi(getenv("PORT")));

    // Accept connections
    while (1) {
        socklen_t clilen = sizeof(cli_addr);
        n = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (n < 0) {
            perror("accept failed");
            continue;
        }

        FILE *file = fopen("/etc/myapp/myapp.txt", "rb");
        if (file == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        char *filename = "index.html";
        char *command[1] = { filename };

        if (send(n, "HTTP/1.1 200 OK\r\n", 23, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        int len = strlen(filename);
        if (send(n, "\r\n", 2, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "Content-Type: text/html\r\n", 28, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "Content-Length: ", 16, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "Connection: close\r\n\r\n", 38, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, filename, len, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "<!DOCTYPE html>\n", 16, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "<html>\n", 8, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "<head>\n", 8, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "<title>Web Server</title>\n", 23, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "</head>\n", 8, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "<body>\n", 8, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "<h1>Welcome to my Web Server</h1>\n", 42, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "</body>\n", 8, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "</html>\n", 11, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "\r\n", 2, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "Content-Length: ", 18, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, "\r\n\r\n", 6, 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        if (send(n, buffer, strlen(buffer), 0) == -1) {
            perror("send");
            close(n);
            continue;
        }

        close(n);
    }

    close(sockfd);

    return 0;
}