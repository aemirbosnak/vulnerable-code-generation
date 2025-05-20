//Falcon-180B DATASET v1.0 Category: Networking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 80

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, len;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error : Socket creation failed \n");
        exit(1);
    }

    printf("Socket created \n");

    // set the server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error : No such host \n");
        exit(1);
    }

    // fill server structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
    serv_addr.sin_port = htons(8080);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error : Connect failed \n");
        exit(1);
    }

    printf("Connected to server \n");

    // send data to server
    send(sockfd, "Hello from client", strlen("Hello from client"), 0);

    // receive data from server
    len = recv(sockfd, buffer, MAX, 0);
    if (len < 0) {
        printf("Error : Receive failed \n");
        exit(1);
    }

    buffer[len] = '\0';
    printf("Received : %s \n", buffer);

    // close socket
    close(sockfd);

    return 0;
}