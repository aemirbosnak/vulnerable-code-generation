//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 1024
#define MAX_BUFF_SIZE 2048
#define BUFFER_SIZE 1024
#define MAX_HOSTNAME_SIZE 100

int main() {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr;
    struct hostent *server;
    int sockfd, portno;
    char hostname[MAX_HOSTNAME_SIZE];
    char host_ip[INET_ADDRSTRLEN];
    int recv_status;
    char *ssid;
    int len;

    printf("Please enter the SSID of the network you want to scan: ");
    scanf("%s", &ssid);

    portno = 80; // HTTP port number

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket");
        return 1;
    }

    bzero((char *)&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(portno);

    server = gethostbyname(ssid);

    if (server == NULL) {
        printf("Hostname not found\n");
        return 1;
    }

    bcopy((char *)server->h_addr, (char *)&client_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
        printf("Error connecting to server");
        return 1;
    }

    printf("Connected to server\n");

    printf("Please enter the SSID of the network you want to scan: ");
    scanf("%s", hostname);

    len = strlen(hostname);

    if (len > MAX_HOSTNAME_SIZE) {
        printf("Hostname too long\n");
        return 1;
    }

    bzero(host_ip, INET_ADDRSTRLEN);

    memset(host_ip, 0, INET_ADDRSTRLEN);

    if (inet_ntop(AF_INET, &client_addr.sin_addr, host_ip, INET_ADDRSTRLEN) == NULL) {
        printf("Error getting host IP\n");
        return 1;
    }

    printf("Host IP: %s\n", host_ip);

    bzero(buffer, BUFFER_SIZE);

    while (1) {
        recv_status = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (recv_status < 0) {
            printf("Error receiving data");
            return 1;
        }

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        printf("%s", buffer);
    }

    printf("Disconnected from server\n");

    close(sockfd);

    return 0;
}