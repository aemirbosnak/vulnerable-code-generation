//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100

int main(int argc, char *argv[]) {
    int sd, valread, i, maxsd;
    struct sockaddr_in serv_addr;
    char send_data[MAX];
    char recv_data[MAX];
    char ip[16];

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Number of Packets>\n", argv[0]);
        exit(0);
    }

    strcpy(ip, argv[1]);
    maxsd = atoi(argv[2]);

    sd = socket(AF_INET, SOCK_STREAM, 0);

    if (sd == -1) {
        perror("socket failed");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(PORT);

    if (connect(sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(0);
    }

    for (i = 0; i < maxsd; i++) {
        sprintf(send_data, "Ping Packet %d", i + 1);
        send(sd, send_data, strlen(send_data), 0);

        memset(recv_data, 0, sizeof(recv_data));
        valread = read(sd, recv_data, sizeof(recv_data));

        if (valread <= 0) {
            printf("No response from the server\n");
            close(sd);
            exit(0);
        }

        printf("Response from the server: %s\n", recv_data);
    }

    close(sd);
    return 0;
}