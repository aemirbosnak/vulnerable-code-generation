//FormAI DATASET v1.0 Category: Client Server Application ; Style: imaginative
//Welcome to the Chatting World Application

#include <stdio.h>  // Standard Input/Output Library
#include <stdlib.h> // Standard Library
#include <netdb.h>    // Networking Library
#include <unistd.h> // UNIX Standard Library
#include <string.h>   // String Library

void error(char *msg) // Function for Error Handling
{
    perror(msg);    // Prints the error message
    exit(1);        // Exits the program
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;  // sockfd: File Descriptor ; portno: Port Number ; n: Character Count
    struct sockaddr_in serv_addr;   // Address to store the Server
    struct hostent *server;         // Host Ent refers to the host name

    char buffer[1024];      // Message buffer to store the message
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);  // Usage Parameters
        exit(0);
    }
    portno = atoi(argv[2]);     // Convert the port number from string to integer

    sockfd = socket(AF_INET, SOCK_STREAM, 0);   // Creates a Socket Connection

    if (sockfd < 0)     // Socket Error Handling
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);        // Finds the Host by Name

    if (server == NULL) {       // Host Name Error Handling
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));     // Initialize Structure to Zero

    serv_addr.sin_family = AF_INET;         // Assigning the Socket Family
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);     // Converts the port number from host byte order to network byte order

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)   // Connection Error Handling
        error("ERROR connecting");

    printf("Welcome to the Chatting World. Type 'Bye' to exit.\n");

    while(1) {      // Infinite Loop to Start the Discussion
        printf("You: ");
        bzero(buffer,1024);     // Clears the buffer for next message
        fgets(buffer,1024,stdin);      // Takes the user input message

        n = write(sockfd,buffer,strlen(buffer));       // Sends the message to the Server

        if (n < 0)      // Message Sending Error Handling
            error("ERROR writing to socket");

        if (strcmp(buffer,"Bye\n") == 0)     // Condition to Exit
            break;

        bzero(buffer,1024);     // Clears the buffer for next message
        n = read(sockfd,buffer,1023);   // Receive the message from the server

        if (n < 0)      // Message Receiving Error Handling
            error("ERROR reading from socket");

        printf("Server: %s",buffer);    // Prints the server message
        if (strcmp(buffer,"Bye\n") == 0) // Condition to exit
            break;
    }

    close(sockfd);      // Closes the Socket Connection
    return 0;
}