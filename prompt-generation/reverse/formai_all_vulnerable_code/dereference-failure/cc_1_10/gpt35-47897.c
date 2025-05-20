//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    portno = atoi(argv[2]); // get port number from command line arguments

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // create a new socket

    if (sockfd < 0) { // check if socket was successfully created
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]); // get server address from hostname

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr)); // clear out the server address struct

    serv_addr.sin_family = AF_INET; // set family to Internet

    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length); // set server address

    serv_addr.sin_port = htons(portno); // set server port

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) { // connect to server
        perror("ERROR connecting");
        exit(1);
    }

    printf("Please enter the message: ");

    memset(buffer, 0, sizeof(buffer)); // clear out buffer

    fgets(buffer, sizeof(buffer), stdin); // read message from user

    n = write(sockfd, buffer, strlen(buffer)); // send message to server

    if (n < 0) { // check if message was successfully sent
        perror("ERROR writing to socket");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer)); // clear out buffer

    n = read(sockfd, buffer, sizeof(buffer)); // read message from server

    if (n < 0) { // check if message was successfully received
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Server response: %s\n", buffer); // print server response

    close(sockfd); // close socket

    return 0; // end program
}