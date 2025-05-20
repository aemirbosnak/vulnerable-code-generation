//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_LINE 1024

#define PORT "80"

typedef struct {
    char ip[16];
    int port;
    int speed;
} server_t;

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_data[MAX_LINE];
    char recv_data[MAX_LINE];
    int recv_size;
    int speed = 0;

    if (argc!= 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return -1;
    }

    server_t server;
    strcpy(server.ip, argv[1]);
    server.port = atoi(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server.port);
    inet_pton(AF_INET, server.ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return -1;
    }

    time_t start_time, end_time;
    time(&start_time);

    while (TRUE) {
        memset(send_data, 'A', MAX_LINE);
        send(sockfd, send_data, MAX_LINE, 0);

        memset(recv_data, 0, MAX_LINE);
        recv_size = recv(sockfd, recv_data, MAX_LINE, 0);
        if (recv_size <= 0) {
            printf("Error receiving data\n");
            close(sockfd);
            return -1;
        }

        speed += recv_size;

        if (difftime(time(NULL), start_time) >= 5) {
            break;
        }
    }

    close(sockfd);

    speed = speed / (difftime(time(NULL), start_time) * 1000);

    printf("Internet speed: %d kbps\n", speed);

    return 0;
}