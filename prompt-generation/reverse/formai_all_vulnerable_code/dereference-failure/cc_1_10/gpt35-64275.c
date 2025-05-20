//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<netdb.h>

#define BUFFER_SIZE 1024

void error(const char* message);
void proxyHandler(int clientSocket);

int main(int argc, char *argv[]) {

    //Check if it is run with the port number argument
    if(argc < 2){
        fprintf(stderr,"Port number is missing\n");
        exit(1);
    }

    char* portNumber = argv[1];

    int sockfd, clientSocket, bindResult, listenResult;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        error("ERROR opening socket");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(portNumber));
    bindResult = bind(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr));
    if (bindResult < 0){
        error("ERROR on binding");
    }
    listenResult = listen(sockfd,5);
    if (listenResult < 0){
        error("ERROR on listen");
    }

    while(1){
        struct sockaddr_in cli_addr;
        socklen_t clilen = sizeof(cli_addr);
        clientSocket = accept(sockfd,(struct sockaddr *) &cli_addr,&clilen);
        printf("Connection Established\n");
        if (clientSocket < 0){
           error("ERROR on accept");
        }
        proxyHandler(clientSocket);
    }

    return 0;
}

void proxyHandler(int clientSocket){

    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    int nbytes;
    nbytes = read(clientSocket, buffer, BUFFER_SIZE);
    if(nbytes < 0){
        error("Error on read");
    }
    char* host;
    host = strtok(buffer," ");
    host = strtok(NULL," ");

    char* httpPos = strstr(host,"http://");
    char* httpsPos = strstr(host,"https://");

    if(httpPos == NULL && httpsPos == NULL){
        error("Error in URL");
    }else if(httpsPos){
        host = httpsPos + 8;
    }else{
        host = httpPos + 7;
    }

    char* rest = strstr(host,"/");
    if(rest != NULL){
        *rest = '\0';
        rest = rest + 1;
    }else{
        rest = "";
    }

    struct hostent *server;
    server = gethostbyname(host);
    if (server == NULL) {
        error("ERROR, no such host\n");
    }

    int serverSocket, connectionResult;
    struct sockaddr_in serv_addr;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0){
        error("ERROR opening socket");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);
    connectionResult = connect(serverSocket,(struct sockaddr *) &serv_addr,sizeof(serv_addr));
    if (connectionResult < 0){
        error("ERROR connecting");
    }

    //Write to server
    nbytes = write(serverSocket, buffer, strlen(buffer));
    if(nbytes < 0){
        error("Error in writing to server socket");
    }

    //Read from server and send to client
    while(1){
        bzero(buffer,BUFFER_SIZE);
        int readSize = read(serverSocket,buffer,BUFFER_SIZE);
        if(readSize == 0){
            break;
        }
        int writeSize = write(clientSocket, buffer, strlen(buffer));
        if(writeSize < 0){
            error("Error in writing to client socket");
        }
    }

    close(serverSocket);
    close(clientSocket);
}

void error(const char* message){
    perror(message);
    exit(1);
}