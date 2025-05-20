//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    // Check for correct usage
    if(argc!= 3) {
        printf("Usage: %s <target_ip> <port>\n", argv[0]);
        return 1;
    }

    // Convert IP address to integer
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    if(connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send data to the server
    int n;
    char msg[] = "GET / HTTP/1.1\r\n";
    send(sockfd, msg, sizeof(msg), 0);

    // Read data from the server
    char buf[1024];
    while(1) {
        if((n = recv(sockfd, buf, sizeof(buf), 0)) <= 0) {
            break;
        }
        printf("%s\n", buf);
    }

    // Close the socket
    close(sockfd);

    return 0;
}