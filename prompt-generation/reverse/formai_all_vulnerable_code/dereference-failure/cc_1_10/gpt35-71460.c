//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: post-apocalyptic
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>

#define MAXPENDING 5
#define RCVBUFSIZE 32

int main(int argc, char *argv[]) {
    int servSock, clntSock;
    struct sockaddr_in servAddr;
    struct sockaddr_in clntAddr;
    int clntLen;
    char echoBuffer[RCVBUFSIZE];
    unsigned short servPort;

    if (argc != 2) {
        printf("Usage: %s <Server Port>\n", argv[0]);
        exit(1);
    }
    servPort = atoi(argv[1]);
    if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Server Socket Creation Failed");
        exit(1);
    }
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(servPort);

    if (bind(servSock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
        perror("Failed to bind the Server Socket");
        exit(1);
    }

    if (listen(servSock, MAXPENDING) < 0) {
        perror("Failed to Listen on Server Socket");
        exit(1);
    }

    printf("Server Running on Port : %d\n", servPort);

    char welcome[] = "Welcome to Post-Apocalyptic World!";
    int welcome_len = strlen(welcome);

    while (1) {
        clntLen = sizeof(clntAddr);
        if ((clntSock = accept(servSock, (struct sockaddr *) &clntAddr, &clntLen)) < 0) {
            perror("Failed to accept the Client Connection");
            exit(1);
        }

        printf("Client connected: %s\n", inet_ntoa(clntAddr.sin_addr));

        send(clntSock, welcome, welcome_len, 0);

        int recvMsgSize;
        while ((recvMsgSize = recv(clntSock, echoBuffer, RCVBUFSIZE, 0)) > 0) {
            printf("Message Received from the Client: %s\n", echoBuffer);

	    char echoString[RCVBUFSIZE + welcome_len + 1];
	    snprintf(echoString, RCVBUFSIZE + welcome_len + 1, "%s%s", welcome, echoBuffer);

            if ((send(clntSock, echoString, recvMsgSize + welcome_len, 0)) != recvMsgSize + welcome_len) {
                perror("Failed to send the message to the Client");
                exit(1);
            }
        }
        close(clntSock);
    }
    return 0;
}