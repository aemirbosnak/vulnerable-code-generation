//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surprised
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    // Initialize socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return 1;
    }

    // Get local machine name
    struct hostent *server;
    if ((server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "gethostbyname failed\n");
        return 2;
    }

    // Initialize server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(5000);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        return 3;
    }

    // Send data
    printf("Enter data to send: ");
    fgets(buffer, sizeof(buffer), stdin);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write failed");
        return 4;
    }

    // Receive data
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read failed");
        return 5;
    }
    buffer[n] = '\0';
    printf("Received: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}