//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    time_t start_time, end_time;
    double elapsed_time;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if ((server = gethostbyname("www.google.com")) == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    start_time = time(NULL);
    send(sockfd, "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n"), 0);

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        if (write(1, buffer, n)!= n) {
            perror("write failed");
            exit(EXIT_FAILURE);
        }
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("Elapsed time: %.2lf seconds\n", elapsed_time);

    close(sockfd);

    return 0;
}