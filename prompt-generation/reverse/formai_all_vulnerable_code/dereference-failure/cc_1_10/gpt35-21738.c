//FormAI DATASET v1.0 Category: Simple Web Server ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h> 
#include <netinet/in.h>

int main(int argc, char* argv[])
{
    if(argc != 2) {
        printf("Usage: %s <port>", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    
    struct sockaddr_in serv_addr, cli_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    memset(&cli_addr, 0, sizeof(cli_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    if(listen(sockfd, 5) < 0) {
        perror("Error listening on socket");
        exit(1);
    }

    printf("Server started on port %d!!\n", port);

    while(1) {

        socklen_t cli_len = sizeof(cli_addr);
        int newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &cli_len);

        if(newsockfd < 0) {
            perror("Error accepting connection");
            exit(1);
        }

        printf("Client connected! Processing request...\n");

        char buffer[1024] = {0};
        read(newsockfd, buffer, 1024);

        printf("Request received: \n\n%s\n", buffer);

        char* response = "HTTP/1.1 200 OK\r\n"
                        "Content-Type: text/html; charset=UTF-8\r\n\r\n"
                        "<!DOCTYPE html>\r\n"
                        "<html>\r\n"
                        "<head>\r\n"
                        "    <title>Shocking Server</title>\r\n"
                        "</head>\r\n"
                        "<body>\r\n"
                        "    <h1>Oh my word! It works!</h1>\r\n"
                        "</body>\r\n"
                        "</html>\r\n";

        write(newsockfd, response, strlen(response));

        printf("Response sent! Closing connection...\n");

        close(newsockfd);

    }
    
    return 0;
}