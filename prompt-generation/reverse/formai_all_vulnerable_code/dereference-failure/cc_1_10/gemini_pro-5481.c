//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Mathematical functions
double f(double x) { return x * x + 2 * x + 1; }
double g(double x) { return 2 * x + 1; }

// Server function
void server(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) { perror("socket"); exit(1); }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) { perror("bind"); exit(1); }
    if (listen(sockfd, 5) == -1) { perror("listen"); exit(1); }

    while (1) {
        int clientfd = accept(sockfd, NULL, NULL);
        if (clientfd == -1) { perror("accept"); exit(1); }

        double x;
        if (recv(clientfd, &x, sizeof(x), 0) == -1) { perror("recv"); exit(1); }

        double y = f(x);
        if (send(clientfd, &y, sizeof(y), 0) == -1) { perror("send"); exit(1); }

        close(clientfd);
    }

    close(sockfd);
}

// Client function
void client(char *ip, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) { perror("socket"); exit(1); }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) { perror("connect"); exit(1); }

    double x;
    printf("Enter a value for x: ");
    scanf("%lf", &x);

    if (send(sockfd, &x, sizeof(x), 0) == -1) { perror("send"); exit(1); }

    double y;
    if (recv(sockfd, &y, sizeof(y), 0) == -1) { perror("recv"); exit(1); }

    printf("f(x) = %lf\n", y);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int port = atoi(argv[1]);
        server(port);
    } else if (argc == 3) {
        char *ip = argv[1];
        int port = atoi(argv[2]);
        client(ip, port);
    } else {
        printf("Usage: %s [port] [ip port]\n", argv[0]);
    }

    return 0;
}