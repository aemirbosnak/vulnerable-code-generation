//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_ptr;
    char *host_name;
    int port_num;

    if (argc!= 3)
    {
        printf("Usage:./client <hostname> <port number>\n");
        exit(1);
    }

    host_name = argv[1];
    port_num = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    // Get server address
    host_ptr = gethostbyname(host_name);
    if (host_ptr == NULL)
    {
        printf("Error getting host address\n");
        exit(1);
    }

    memcpy(&server_addr.sin_addr, host_ptr->h_addr, host_ptr->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    // Send data to server
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "Hello, World!");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive data from server
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Received from server: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}