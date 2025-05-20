//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUFF 1024
#define MAX_CLIENTS 10

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){
    int sockfd, connfd[MAX_CLIENTS], max_sd, activity, i, valread, sd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX_BUFF];
    fd_set readfds;
    char *msg = "Network QoS Monitor Initialized.\n";

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) 
        error("Error creating socket.\n");

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(atoi(argv[1])); 

    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        error("Error binding socket.\n");
    }

    if ((listen(sockfd, 5)) != 0) { 
        error("Error listening.\n");
    }

    for (i = 0; i < MAX_CLIENTS; i++) {
        connfd[i] = 0; 
    }

    printf("Network QoS Monitor Initialized.\n");

    while (1) {
        FD_ZERO(&readfds);

        FD_SET(sockfd, &readfds); 
        max_sd = sockfd;

        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = connfd[i];

            if (sd > 0) 
                FD_SET(sd, &readfds);

            if (sd > max_sd) 
                max_sd = sd;
        }

        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            error("Error in select.\n");
        }

        if (FD_ISSET(sockfd, &readfds)) {
            int len = sizeof(cliaddr);
            sd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);

            if (sd < 0) {
                error("Error accepting connection.\n");
            }

            for (i = 0; i < MAX_CLIENTS; i++) {
                if (connfd[i] == 0) {
                    connfd[i] = sd;
                    printf("Client %d connected.\n", i + 1);
                    send(connfd[i], msg, strlen(msg), 0);
                    break;
                }
            }
        }

        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = connfd[i];

            if (FD_ISSET(sd, &readfds)) {
                valread = read(sd, buffer, MAX_BUFF);

                if (valread <= 0) {
                    printf("Client %d disconnected.\n", i + 1);
                    close(sd);
                    connfd[i] = 0;
                }
                else {
                    buffer[valread] = '\0';
                    printf("Client %d: %s", i + 1, buffer);
                }
            }
        }
    }

    return 0;
}