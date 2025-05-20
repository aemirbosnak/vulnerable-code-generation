//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1025];
    struct hostent *server;
    struct timeval tv;
    double t1, t2;
    int i = 0;

    // Get server IP and port number
    if (argc < 3) {
        printf("Usage:./client <server_ip> <port_number>\n");
        exit(0);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("No such host\n");
        exit(0);
    }
    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    // Connect to server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = *(long *)server->h_addr;
    serv_addr.sin_port = htons(portno);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    // Receive data from server
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            printf("Error accepting connection\n");
            exit(0);
        }
        printf("Connection accepted\n");

        while (1) {
            memset(buffer, 0, sizeof(buffer));
            ret = recv(newsockfd, buffer, 1024, 0);
            if (ret <= 0) {
                printf("Disconnected\n");
                close(newsockfd);
                break;
            }
            printf("Received data: %s\n", buffer);
        }
    }

    close(sockfd);
    return 0;
}