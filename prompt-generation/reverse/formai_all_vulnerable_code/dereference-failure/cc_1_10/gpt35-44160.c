//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>

#define BUFFER_SIZE 8192

void error(char *msg){ // error function to display error message and exit
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, client_fd, len, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    char *temp, *host, *port;
    bool isStarted = false;

    if (argc < 2) {
        printf("Usage: %s <port_number>\n",argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1])) ;

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd,5);
    printf("HTTP proxy is running on port %s\n",argv[1]);

    while (1) {
        len = sizeof(cli_addr);
        client_fd = accept(sockfd, (struct sockaddr *) &cli_addr, &len);

        if (client_fd < 0)
            error("ERROR on accept");

        memset(buffer,0,BUFFER_SIZE);
        n = read(client_fd,buffer,BUFFER_SIZE);
        if (n < 0)
            error("ERROR reading from socket");

        memset(request,0,BUFFER_SIZE);
        strcat(request,buffer);

        temp = strtok(buffer,"\n"); // get the first line
        if (temp != NULL && strstr(temp, "HTTP")) {
            // check if it's a HTTP request
            host = strtok(temp+11, ":"); // get the host name
            port = strtok(NULL," "); // get the port number
            isStarted = true;
            printf("HTTP request: %s:%s\n",host,port);
        } else {
            printf("Unknown request: %s\n",temp);
            isStarted = false;
        }

        memset(response,0,BUFFER_SIZE);
        if (isStarted) {
            // connect to the host server
            struct sockaddr_in serv_addr;
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);
            bzero((char *) &serv_addr, sizeof(serv_addr));
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(atoi(port));
            serv_addr.sin_addr.s_addr = inet_addr(host);

            if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
                error("ERROR connecting");

            // forward the request to the host server
            n = write(sockfd,request,strlen(request));
            if (n < 0)
                error("ERROR writing to socket");

            // read the response from the host server
            while (1) {
                memset(buffer,0,BUFFER_SIZE);
                n = read(sockfd,buffer,BUFFER_SIZE);
                if (n <= 0)
                    break;

                // modify the response and forward it to the client
                for (int i = 0, j = 0; i < n; ++i, ++j) {
                    if (buffer[i] == '\r')
                        --j; // skip '\r'
                    else if (buffer[i] == '\n')
                        response[j++] = '\r', response[j] = buffer[i];
                    else
                        response[j] = buffer[i];
                }

                // forward the response to the client
                n = write(client_fd,response,strlen(response));
                if (n < 0)
                    error("ERROR writing to socket");
            }

            close(sockfd);
        }

        close(client_fd);
    }

    close(sockfd);
    return 0;
}