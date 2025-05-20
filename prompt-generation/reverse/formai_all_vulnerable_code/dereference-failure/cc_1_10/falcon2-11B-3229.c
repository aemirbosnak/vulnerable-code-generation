//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 80

int main()
{
    int sockfd, valread, addrlen;
    struct sockaddr_in serv_addr;
    char buffer[256];

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        return 1;
    }

    // set up server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "www.google.com", &serv_addr.sin_addr) <= 0)
    {
        perror("ERROR, could not resolve host");
        return 1;
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR connecting");
        return 1;
    }

    // send ping
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n");
    write(sockfd, buffer, strlen(buffer));

    // receive pong
    valread = read(sockfd, buffer, 256);
    printf("Received %d bytes: %s\n", valread, buffer);

    // close socket
    close(sockfd);

    return 0;
}