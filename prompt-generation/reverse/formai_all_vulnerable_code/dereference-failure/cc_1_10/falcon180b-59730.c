//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"
#define PACKET_LOSS_THRESHOLD 5

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];
    int ret;
    int packet_loss = 0;
    int j;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("socket failed: %s\n", strerror(errno));
        return 1;
    }

    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    for (j = 0; j < 10; j++) {
        ret = sendto(sock, "ping", strlen("ping"), 0, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in));
        if (ret!= strlen("ping")) {
            printf("sendto failed: %s\n", strerror(errno));
            close(sock);
            return 1;
        }

        memset(buf, 0, BUF_SIZE);
        ret = recvfrom(sock, buf, BUF_SIZE, 0, NULL, NULL);
        if (ret <= 0) {
            printf("recvfrom failed: %s\n", strerror(errno));
            close(sock);
            return 1;
        }

        if (strncmp(buf, "pong", strlen("pong"))!= 0) {
            printf("packet loss detected\n");
            packet_loss++;
        }
    }

    if (packet_loss >= PACKET_LOSS_THRESHOLD) {
        printf("QoS violation detected\n");
    } else {
        printf("QoS is within acceptable limits\n");
    }

    close(sock);
    return 0;
}