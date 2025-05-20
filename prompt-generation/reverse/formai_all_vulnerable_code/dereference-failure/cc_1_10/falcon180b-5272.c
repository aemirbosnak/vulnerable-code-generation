//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, retval, i, host_len;
    char *host_name;
    struct hostent *host_info;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    host_name = argv[1];
    host_len = strlen(host_name);
    if (host_len > MAX_HOST_NAME) {
        printf("Hostname too long.\n");
        exit(1);
    }

    host_info = gethostbyname(host_name);
    if (host_info == NULL) {
        printf("Host not found.\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = *(unsigned long *) host_info->h_addr;
    server_addr.sin_port = htons(atoi(argv[2]));

    retval = connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (retval == -1) {
        printf("Connection failed.\n");
        exit(1);
    }

    printf("Connected to %s:%d\n", host_name, atoi(argv[2]));

    while (TRUE) {
        memset(data, 0, sizeof(data));
        retval = read(sockfd, data, MAX_DATA_SIZE);
        if (retval <= 0) {
            printf("Disconnected from server.\n");
            break;
        }
        printf("%s", data);
    }

    close(sockfd);
    return 0;
}