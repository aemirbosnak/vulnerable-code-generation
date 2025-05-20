//FormAI DATASET v1.0 Category: Chat server ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n, i, j;
    char * welcome_message = "Welcome to the Chat Server. Type 'QUIT' to exit.\n";
    fd_set read_fds, active_fds;
    int fdmax, listener;
    int client_fds[MAX_CLIENTS];
    char * client_names[MAX_CLIENTS];
    int num_clients = 0;
    
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    
    listen(sockfd, MAX_CLIENTS);
    
    FD_ZERO(&active_fds);
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &active_fds);
    fdmax = sockfd;
    
    while(1) {
        read_fds = active_fds;
        if(select(fdmax + 1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("ERROR selecting");
            exit(1);
        }
        for (i = 0; i <= fdmax; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == sockfd) {
                    clilen = sizeof(cli_addr);
                    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
                    if (newsockfd < 0) {
                        perror("ERROR on accept");
                        exit(1);
                    }
                    if (num_clients >= MAX_CLIENTS) {
                        close(newsockfd);
                        continue;
                    }
                    client_fds[num_clients] = newsockfd;
                    num_clients++;
                    FD_SET(newsockfd, &active_fds);
                    if (newsockfd > fdmax) {
                        fdmax = newsockfd;
                    }
                    n = send(newsockfd, welcome_message, strlen(welcome_message), 0);
                    if (n < 0) {
                        perror("ERROR writing to socket");
                        exit(1);
                    }
                } else {
                    bzero(buffer,BUFFER_SIZE);
                    n = recv(i, buffer, BUFFER_SIZE, 0);
                    if (n <= 0) {
                        close(i);
                        FD_CLR(i, &active_fds);
                        for(j=0; j<num_clients; j++) {
                            if(client_fds[j] == i) {
                                num_clients--;
                                client_fds[j] = client_fds[num_clients];
                                client_names[j] = client_names[num_clients];
                            }
                        }
                    } else {
                        if(strncmp(buffer,"QUIT",4) == 0) {
                            close(i);
                            FD_CLR(i, &active_fds);
                            for(j=0; j<num_clients; j++) {
                                if(client_fds[j] == i) {
                                    num_clients--;
                                    client_fds[j] = client_fds[num_clients];
                                    client_names[j] = client_names[num_clients];
                                }
                            }
                        } else {
                            for(j=0; j<num_clients; j++) {
                                if(client_fds[j] != i) {
                                    char message[BUFFER_SIZE+20];
                                    bzero(message, BUFFER_SIZE+20);
                                    sprintf(message, "%s: %s\n", client_names[j], buffer);
                                    n = send(client_fds[j], message, strlen(message), 0);
                                    if (n < 0) {
                                        perror("ERROR writing to socket");
                                        exit(1);
                                    }
                                } else {
                                    if(client_names[j] == NULL) {
                                        client_names[j] = malloc(sizeof(char)*BUFFER_SIZE);
                                    }
                                    strcpy(client_names[j], buffer);
                                    char join_message[BUFFER_SIZE+20];
                                    bzero(join_message, BUFFER_SIZE+20);
                                    sprintf(join_message, "%s has joined the chat\n", client_names[j]);
                                    for(int k=0; k<num_clients; k++) {
                                        if(client_fds[k] != i) {
                                            n = send(client_fds[k], join_message, strlen(join_message), 0);
                                            if (n < 0) {
                                                perror("ERROR writing to socket");
                                                exit(1);
                                            }
                                        }
                                    }
                                }   
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}