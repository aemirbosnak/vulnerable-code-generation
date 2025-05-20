//FormAI DATASET v1.0 Category: Client Server Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    pid_t pid;

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

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    
    // Starting server by using fork
    pid = fork();
    if (pid == -1) {
        perror("ERROR on fork");
        exit(1);
    }
    
    if (pid == 0) {
        // Child process
        printf("Server started on port %d\n", portno);
        listen(sockfd,5);
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd,
                           (struct sockaddr *) &cli_addr,
                           &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }
        close(sockfd);

        while (1) {
            // Receive message from client
            bzero(buffer,256);
            n = read(newsockfd,buffer,255);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
            printf("Message from client: %s\n",buffer);

            // Send message to client
            n = write(newsockfd,"I got your message",18);
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
        }
    } else {
        // Parent process
        // Wait for child to exit
        wait(NULL);
    }

    return 0;
}