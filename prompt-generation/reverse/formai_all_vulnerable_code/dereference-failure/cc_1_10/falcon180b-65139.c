//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <SSID>\n", argv[0]);
        exit(1);
    }

    char *ssid = argv[1];
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9);

    if (inet_pton(AF_INET, "224.0.0.251", &server_addr.sin_addr) <= 0) {
        printf("Error converting IP address: %s\n", strerror(errno));
        exit(1);
    }

    char buf[BUF_SIZE];
    snprintf(buf, BUF_SIZE, "M-SEARCH * HTTP/1.1\r\n"
                             "HOST: %s\r\n"
                             "MAN: \"ssdp:discover\"\r\n"
                             "ST: wifi_radar\r\n"
                             "MX: 1\r\n", ssid);

    sendto(sock, buf, strlen(buf), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    char recv_buf[BUF_SIZE];
    memset(recv_buf, 0, BUF_SIZE);

    int recv_len = recvfrom(sock, recv_buf, BUF_SIZE, 0, NULL, NULL);

    if (recv_len <= 0) {
        printf("Error receiving data: %s\n", strerror(errno));
        exit(1);
    }

    recv_buf[recv_len] = '\0';
    printf("Received data: %s\n", recv_buf);

    close(sock);
    return 0;
}