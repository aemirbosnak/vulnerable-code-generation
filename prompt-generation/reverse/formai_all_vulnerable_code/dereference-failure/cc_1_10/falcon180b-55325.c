//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT "80"

int main(int argc, char *argv[]) {
    char *host;
    int sock, ret, i;
    struct hostent *he;
    struct sockaddr_in serv_addr;
    char send_buf[BUF_SIZE];
    char recv_buf[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <host> <packet-size>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock == -1) {
        printf("socket failed: %s\n", strerror(errno));
        exit(1);
    }

    he = gethostbyname(host);

    if (he == NULL) {
        printf("gethostbyname failed: %s\n", strerror(errno));
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(PORT));
    serv_addr.sin_addr = *((struct in_addr *)he->h_addr);

    for (i = 0; i < atoi(argv[2]); i++) {
        sprintf(send_buf, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);
        ret = sendto(sock, send_buf, strlen(send_buf), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

        if (ret == -1) {
            printf("sendto failed: %s\n", strerror(errno));
            exit(1);
        }
    }

    memset(recv_buf, 0, sizeof(recv_buf));

    while (1) {
        ret = recvfrom(sock, recv_buf, BUF_SIZE, 0, NULL, NULL);

        if (ret == -1) {
            printf("recvfrom failed: %s\n", strerror(errno));
            exit(1);
        }

        if (strstr(recv_buf, "200 OK")!= NULL) {
            printf("Server is up and running\n");
            exit(0);
        }
    }

    return 0;
}