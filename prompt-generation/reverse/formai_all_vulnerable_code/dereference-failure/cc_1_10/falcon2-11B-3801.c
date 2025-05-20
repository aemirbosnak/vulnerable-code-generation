//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <sys/time.h>
#include <sys/resource.h>

// Global Variables
int sockfd, portno;
struct sockaddr_in serv_addr;
char buffer[4096];

void print_buffer(char *buf, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%02x ", buf[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int opt, n;
    int yes = 1;
    struct hostent *server;
    struct sockaddr_in cli_addr;
    char* hostname = argv[1];
    int port = atoi(argv[2]);

    // Initializing socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Setting up server address
    server = gethostbyname(hostname);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Connecting to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Setting up buffer
    printf("Waiting for data...\n");
    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0)
    {
        printf("Received %d bytes:", n);
        print_buffer(buffer, n);
        printf("\n");
    }

    close(sockfd);
    return 0;
}