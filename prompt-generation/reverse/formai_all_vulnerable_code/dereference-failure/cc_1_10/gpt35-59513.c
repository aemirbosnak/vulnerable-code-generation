//FormAI DATASET v1.0 Category: Networking ; Style: rigorous
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 512         //Message buffer size.

void errorExit(char *errorMessage) {
    perror(errorMessage);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    int clientSock;            //Socket descriptor for client.
    struct sockaddr_in serverAddr;  //Server address data structure.
    char *serverIPAddr;              //IP address of the server.
    unsigned short serverPortNum;    //Port number of the server.
    char messageBuf[BUF_SIZE];       //Message buffer.

    if ((argc < 3) || (argc > 4)) {
        fprintf(stderr, "Usage: %s <Server IP Address> <Server Port> <Message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    serverIPAddr = argv[1];                                   //Get server IP address from the command-line argument.
    serverPortNum = atoi(argv[2]);                             //Convert the server port number from string to integer.

    memset(&serverAddr, 0, sizeof(serverAddr));                //Zero out the address structure.

    serverAddr.sin_family = AF_INET;                           //Internet address family.
    serverAddr.sin_addr.s_addr = inet_addr(serverIPAddr);      //Server IP address.
    serverAddr.sin_port = htons(serverPortNum);                 //Server port number.

    /* Create a socket for the client */
    clientSock = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSock < 0) {
        errorExit("Socket creation failed");
    }

    /* Connect to the server */
    if (connect(clientSock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)
        errorExit("Connection failed");

    /*
     *  Send the message to server and receive the response.
     */
    memset(&messageBuf, 0, sizeof(messageBuf));                //Zero out the message buffer.

    /* Send the message to the server */
    if ((send(clientSock, argv[3], strlen(argv[3]), 0)) < 0)
        errorExit("Send failed");

    /* Receive the response from the server */
    if ((recv(clientSock, messageBuf, BUF_SIZE - 1, 0)) < 0)
        errorExit("Receive failed");

    printf("Server Echoes : %s\n", messageBuf);

    /* Close the socket */
    close(clientSock);

    return 0;
}