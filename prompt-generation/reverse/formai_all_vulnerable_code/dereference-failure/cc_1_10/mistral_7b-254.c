//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define ICMP_ECHO 8
#define ICMP_ECHOREPLY 0
#define TIMEOUT 500

int main(int argc, char **argv) {
    int sockfd, opt = 1, len, i, status;
    char send_buf[BUFFER_SIZE];
    char recv_buf[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc != 2) {
        printf("Usage: %s <hostname/IP address>\n", argv[0]);
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Unknown host %s.\n", argv[1]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(ICMP_ECHO);
    serv_addr.sin_addr.s_addr = *((unsigned long *)server->h_addr);

    for (i = 0; i < 4; i++) {
        send_buf[0] = ICMP_ECHO;
        sendto(sockfd, send_buf, sizeof(send_buf), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

        len = recvfrom(sockfd, recv_buf, BUFFER_SIZE, 0, NULL, NULL);
        if (len > 0) {
            if (recv_buf[len - 1] == ICMP_ECHOREPLY) {
                status = 1;
                printf("%s is up!\n", argv[1]);
                break;
            }
        }

        usleep(TIMEOUT * 1000);
    }

    if (status == 0) {
        printf("%s is down!\n", argv[1]);
    }

    close(sockfd);
    return 0;
}