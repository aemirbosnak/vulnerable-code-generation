//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>

#define PORT 8080
#define BUFSIZE 1024

int main(int argc, char * argv[]) {
    if(argc != 2) {
        printf("Usage: %s <server address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct hostent * server = gethostbyname(argv[1]);
    if(server == NULL) {
        printf("Error: no such host\n");
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Error: could not create socket\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    int ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if(ret < 0) {
        printf("Error: could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    int flags = fcntl(sockfd, F_GETFL, 0);
    if(flags == -1) {
        printf("Error: could not get socket flags\n");
        exit(EXIT_FAILURE);
    }

    flags |= O_NONBLOCK;
    ret = fcntl(sockfd, F_SETFL, flags);
    if(ret == -1) {
        printf("Error: could not set socket flags\n");
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZE];
    memset(buf, 0, BUFSIZE);

    int total_bytes = 0;

    while(1) {
        int bytes_read = read(sockfd, buf, BUFSIZE);
        if(bytes_read < 0) {
            printf("Info: no data available yet\n");
            continue;
        } else if(bytes_read == 0) {
            break;
        } else {
            total_bytes += bytes_read;
        }
    }

    printf("Total bytes read: %d\n", total_bytes);

    close(sockfd);

    return 0;
}