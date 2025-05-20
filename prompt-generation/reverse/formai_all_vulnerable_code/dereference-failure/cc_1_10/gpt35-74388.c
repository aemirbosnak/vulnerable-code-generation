//FormAI DATASET v1.0 Category: Client Server Application ; Style: inquisitive
#include <stdio.h> // standard input output header file
#include <stdlib.h> // for dynamic memory allocation
#include <string.h> // for string operations
#include <unistd.h> // for close function
#include <sys/types.h> // for system types
#include <sys/socket.h> // for socket related functions
#include <netinet/in.h> // for internet protocol related functions

void error(const char *msg) // error handling function
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno; // socket file descriptors and port number
    socklen_t clilen; // client address length
    char buffer[256]; // buffer to store message
    struct sockaddr_in serv_addr, cli_addr; // server and client address structures 
    int n; // number of bytes read or written

    if (argc < 2) { // checking if port number is provided
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    /* Creating socket file descriptor */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) // error handling for socket creation
        error("ERROR opening socket");

    memset((char *) &serv_addr, 0, sizeof(serv_addr)); // filling server address structure with 0s

    /* Setting up server address structure */
    portno = atoi(argv[1]); // getting port number from command line arguments
    serv_addr.sin_family = AF_INET; // setting address family
    serv_addr.sin_addr.s_addr = INADDR_ANY; // setting any available IP address of the server
    serv_addr.sin_port = htons(portno); // setting port number in network byte order

    /* Binding socket to server address */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) // error handling for socket binding
        error("ERROR on binding");

    /* Starting to listen for incoming connections */
    listen(sockfd,5); // setting maximum number of clients to be served

    clilen = sizeof(cli_addr); // setting client address length

    while (1) { // infinite loop to keep server running
        /* Accepting incoming connection */
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen); 

        if (newsockfd < 0) { // error handling for accepting incoming connection
            error("ERROR on accept");
            continue; // jump to next iteration of loop in case of error
        }

        /* Starting message communication with client */
        memset(buffer, 0, 256); // filling buffer with 0s
        n = read(newsockfd,buffer,255); // reading message from client

        if (n < 0) { // error handling for message reading
            error("ERROR reading from socket");
            close(newsockfd); // closing connection
            continue; // jump to next iteration of loop in case of error
        }

        printf("Here is the message: %s\n",buffer); // printing received message

        /* Sending message to client */
        n = write(newsockfd,"I got your message",18); 

        if (n < 0) { // error handling for message sending
            error("ERROR writing to socket");
            close(newsockfd); // closing connection
            continue; // jump to next iteration of loop in case of error
        }

        close(newsockfd); // closing connection with client
    }

    close(sockfd); // closing socket
    return 0; // exiting program
}