//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>

int main(int argc, char *argv[])
{
        int sockfd, n;
        int portno=80;
        char buffer[4096];

        //create a socket
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
        {
                perror("Error creating socket");
                exit(1);
        }

        //create a socket address structure
        struct sockaddr_in serv_addr;
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(portno);

        struct hostent *server;
        server = gethostbyname(argv[1]);
        if (server == NULL) {
                printf("Error: no such host\n");
                exit(0);
        }

        //convert IP address from text to binary form
        inet_pton(AF_INET, inet_ntoa(*(struct in_addr*)server->h_addr_list[0]), &serv_addr.sin_addr);

        //connect to server
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
                perror("Error connecting to server");
                exit(1);
        }

        //send http request
        char request[1024];
        sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
        if (send(sockfd, request, strlen(request), 0) < 0) {
                printf("Error: failed to send request\n");
                exit(1);
        }

        //read http response
        FILE *fp = fopen("http_response.html", "w");
        if (fp == NULL) {
                printf("Error: failed to create file\n");
                exit(1);
        }
        while ((n = recv(sockfd, buffer, 4096, 0)) > 0)
        {
                fwrite(buffer, sizeof(char), n, fp);
        }
        if (n < 0)
        {
                perror("Error receiving data");
                exit(1);
        }
        fclose(fp);

        //close socket
        close(sockfd);

        return 0;
}