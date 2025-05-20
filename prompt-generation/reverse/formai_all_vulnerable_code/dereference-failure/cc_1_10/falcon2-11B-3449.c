//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    // get local machine name
    struct hostent *server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname: unknown host\n");
        exit(1);
    }

    // get port number from command line
    if (argc!= 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    char *port = argv[2];
    int port_num = atoi(port);

    // get address and port number
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port_num);
    memcpy(&address.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // send data to the server
    char data[] = "Hello, server!";
    send(sockfd, data, strlen(data), 0);

    // receive data from the server
    char buffer[1024];
    int num_bytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (num_bytes < 0) {
        perror("recv failed");
        exit(1);
    }

    // print the received data
    printf("Received data: %s\n", buffer);

    // close the socket
    close(sockfd);

    return 0;
}