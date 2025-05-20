//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    if (argc!= 2) {
        printf("Usage: %s <target_ip>\n", argv[0]);
        return 1;
    }

    struct hostent* he = gethostbyname(argv[1]);
    if (he == NULL) {
        fprintf(stderr, "Error: Unable to resolve hostname\n");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&serv_addr.sin_addr.s_addr, he->h_addr_list[0], he->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: Failed to create socket");
        return 1;
    }

    int status = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (status == -1) {
        perror("Error: Failed to connect to server");
        return 1;
    }

    char buffer[1024];
    int nread;
    while ((nread = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received data: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}