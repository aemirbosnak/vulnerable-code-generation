//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_HOST_NAME 100
#define MAX_DATA_SIZE 100

int main(int argc, char *argv[]) {
    char hostname[MAX_HOST_NAME];
    struct hostent *host;
    int sockfd, n, res;
    struct sockaddr_in servaddr;
    char sendData[MAX_DATA_SIZE];
    char recvData[MAX_DATA_SIZE];

    printf("Enter the hostname or IP address: ");
    scanf("%s", hostname);

    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Invalid hostname or IP address.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Socket creation failed.\n");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    servaddr.sin_addr = *((struct in_addr *) host->h_addr);

    res = connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (res == -1) {
        printf("Error: Connection failed.\n");
        exit(1);
    }

    printf("Connection established.\n");

    strcpy(sendData, "GET / HTTP/1.1\r\nHost: ");
    strcat(sendData, hostname);
    strcat(sendData, "\r\nConnection: close\r\n\r\n");

    n = send(sockfd, sendData, strlen(sendData), 0);
    if (n == -1) {
        printf("Error: Data send failed.\n");
        exit(1);
    }

    n = recv(sockfd, recvData, MAX_DATA_SIZE, 0);
    if (n <= 0) {
        printf("Error: No data received from the server.\n");
        exit(1);
    }

    printf("Data received from the server:\n%s", recvData);

    close(sockfd);

    return 0;
}