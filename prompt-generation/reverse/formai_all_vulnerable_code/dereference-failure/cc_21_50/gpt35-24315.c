//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFFER_SIZE 4096
#define MAX_CLIENTS 10

// main function where HTTP Proxy Server application runs
int main(int argc, char *argv[]){

    int PORT_NUMBER; //HTTP Proxy Server Port Number
    char* DEFAULT_SERVER; //Default Server to connect to if unable to connect to requested hostname
    int serverSocket; //Socket used for Server communication
    int clientSocket[MAX_CLIENTS]; //Array of sockets used for Client communication
    struct sockaddr_in serverAddr; //Address structure used to bind to server
    struct sockaddr_in clientAddr; //Address structure used to bind to client
    int clientAddrlen = sizeof(struct sockaddr_in); //Size of address structure
    fd_set activeSet, readSet; //File descriptor sets where activity is monitored 

    if( argc == 3 ) {
        PORT_NUMBER = atoi(argv[1]);
        DEFAULT_SERVER = argv[2];
    }
    else {
        printf("Invalid Arguments\n");
        exit(EXIT_FAILURE);
    }

    // create server socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    
    // set server address parameters
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT_NUMBER);
    
    // bind socket to address
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("Socket bind error");
        exit(EXIT_FAILURE);
    }
    
    // listen for incoming connections
    if (listen(serverSocket, MAX_CLIENTS) < 0)
    { 
        perror("Listen error");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("HTTP Proxy Server is running on port %d\n", PORT_NUMBER);
    }
    
    // iterate forever to accept incoming connections
    while (1)
    {
        FD_ZERO(&activeSet);
        FD_SET(serverSocket, &activeSet);

        for(int i = 0; i < MAX_CLIENTS; i++){
            if(clientSocket[i] != 0){
                FD_SET(clientSocket[i], &activeSet);
            }
        }

        // wait for activity on sockets using select
        if (select(FD_SETSIZE, &activeSet, NULL, NULL, NULL) < 0)
        {
            perror("Socket select error");
            exit(EXIT_FAILURE);
        }
        
        // check if activity is on server socket
        if (FD_ISSET(serverSocket, &activeSet))
        {
            int newSocket;
            // accept incoming request
            if ((newSocket = accept(serverSocket,(struct sockaddr *)&clientAddr, (socklen_t*)&clientAddrlen)) < 0)
            {
                perror("Accept error");
                exit(EXIT_FAILURE);
            }
            
            // Add new socket to array of client sockets
            printf("Connection established with client %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
            int index = 0;
            while (index < MAX_CLIENTS && clientSocket[index] != 0){
                index++;
            }
            if(index < MAX_CLIENTS){
                clientSocket[index] = newSocket;
            }
            else{
                printf("Limit for maximum clients reached\n");
            }
        }

        // check if activity is on client sockets
        for(int i = 0; i < MAX_CLIENTS; i++){
            if (FD_ISSET(clientSocket[i], &activeSet))
            {
                char buffer[BUFFER_SIZE] = {0};
                int valRead = read(clientSocket[i], buffer, BUFFER_SIZE);
                if (valRead <= 0)
                {
                    // remove client socket from array and close
                    printf("Connection terminated with client %d\n", i);
                    close(clientSocket[i]);
                    clientSocket[i] = 0;
                }
                else
                {
                    // Check for HTTP request and extract hostname
                    char* hostHeader = strstr(buffer, "Host:");
                    char hostname[256];
                    if(hostHeader){
                        sscanf(hostHeader, "%*s %s\n", hostname);
                    }
                    else{
                        strcpy(hostname, DEFAULT_SERVER);
                        printf("Using default server: %s\n", DEFAULT_SERVER);
                    }
                    
                    // create socket to connect to hostname
                    int hostSocket;
                    struct sockaddr_in hostAddr;
                    if ((hostSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
                    {
                        perror("Socket creation error");
                        exit(EXIT_FAILURE);
                    }
                    memset(&hostAddr, 0, sizeof(hostAddr));
                    hostAddr.sin_family = AF_INET;
                    hostAddr.sin_port = htons(80);
                    if(inet_pton(AF_INET, hostname, &hostAddr.sin_addr)<=0)
                    {
                        printf("\nInvalid address/ Address not supported \n");
                        continue;
                    }
                    
                    // connect to hostname
                    if (connect(hostSocket, (struct sockaddr *)&hostAddr, sizeof(hostAddr)) < 0)
                    {
                        perror("Connect error");
                        continue;
                    }
                    
                    // forward HTTP request to hostname and read response
                    if (write(hostSocket, buffer, strlen(buffer)) < 0)
                    {
                        perror("HTTP Request not sent error");
                        continue;
                    }
                    char hostBuffer[BUFFER_SIZE] = {0};
                    valRead = read(hostSocket, hostBuffer, BUFFER_SIZE);
                    if (valRead <= 0)
                    {
                        perror("HTTP Response Note received error");
                        continue;
                    }
                    
                    // forward HTTP response to client
                    if (write(clientSocket[i], hostBuffer, strlen(hostBuffer)) < 0)
                    {
                        perror("HTTP Response not forwarded error");
                        continue;
                    }

                    close(hostSocket);
                }
            }
        }
    }
    return 0;
}