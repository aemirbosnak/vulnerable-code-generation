//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char send_buf[BUF_SIZE];
    char recv_buf[BUF_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage: %s <IP Address> <Port> <Message>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error: Socket creation failed.\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Connection failed.\n");
        close(sock);
        return 1;
    }

    strcpy(send_buf, argv[3]);
    send(sock, send_buf, strlen(send_buf), 0);

    while (TRUE) {
        memset(recv_buf, 0, BUF_SIZE);
        n = recv(sock, recv_buf, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Error: Receiving data failed.\n");
            close(sock);
            return 1;
        }

        printf("Received data: %s\n", recv_buf);
    }

    close(sock);
    return 0;
}