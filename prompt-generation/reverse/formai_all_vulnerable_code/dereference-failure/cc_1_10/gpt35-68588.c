//FormAI DATASET v1.0 Category: Socket programming ; Style: medieval
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX_CLIENTS 10

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char **argv){
    int sockfd, newsockfd, portno, clientlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[256];
    int n, i, j, k;
    int client_sock[MAX_CLIENTS] = {0};
    fd_set readfds;

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error("Could not create socket!");

    memset((char *)&server_addr, 0, sizeof(server_addr));
    portno = atoi(argv[1]);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        error("Bind failed!");

    if(listen(sockfd, MAX_CLIENTS) == -1)
        error("Listen failed!");

    printf("Server started on port %d...\n", portno);

    clientlen = sizeof(client_addr);

    while(1){
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        for(i=0; i<MAX_CLIENTS; i++){
            if(client_sock[i] > 0){
                FD_SET(client_sock[i], &readfds);
            }
        }
        if(select(FD_SETSIZE, &readfds, NULL, NULL, NULL) == -1){
            error("Select failed!");
        }

        if(FD_ISSET(sockfd, &readfds)){
            if((newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen)) == -1){
                error("Accept failed!");
            }
            printf("New client connected with the IP address: %s and port number: %d\n", 
                    inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            // Add new client to the list
            for(i=0; i<MAX_CLIENTS; i++){
                if(client_sock[i] == 0){
                    client_sock[i] = newsockfd;
                    break;
                }
            }
        }

        for(i=0; i<MAX_CLIENTS; i++){
            if(FD_ISSET(client_sock[i], &readfds)){
                if((n = read(client_sock[i], buffer, 255)) == -1){
                    error("Read failed!");
                }
                buffer[n] = '\0';
                printf("Client(%d): %s", i+1, buffer);
                for(j=0; j<MAX_CLIENTS; j++){
                    if(client_sock[j] > 0 && j != i){
                        // Let other clients know what this client has sent
                        if(write(client_sock[j], buffer, strlen(buffer)) == -1){
                            error("Write failed!");
                        }
                    }
                }
            }
        }
    }

    return 0;
}