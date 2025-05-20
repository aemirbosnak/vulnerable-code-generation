//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFSIZE 4096

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <html_file>\n", argv[0]);
        return 1;
    }

    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFSIZE];
    char filename[1024];
    char response[BUFFSIZE];
    int response_len;

    if (argc!= 2) {
        printf("Usage: %s <html_file>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 3);

    while (1) {
        portno = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (portno < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, BUFFSIZE);
            clilen = read(portno, buffer, BUFFSIZE);
            if (clilen <= 0) {
                printf("ERROR reading from socket\n");
                break;
            }
            printf("Received: %s\n", buffer);

            strcpy(response, "HTTP/1.1 200 OK\r\n");
            strcat(response, "Content-Type: text/html\r\n\r\n");

            strcat(response, "<html>\r\n");
            strcat(response, "<head><title>Welcome to the Cyberpunk Web Server</title></head>\r\n");
            strcat(response, "<body>\r\n");
            strcat(response, "<h1>Welcome to the Cyberpunk Web Server</h1>\r\n");
            strcat(response, "<p>This is a simple web server written in C in a Cyberpunk style.</p>\r\n");
            strcat(response, "<p>The server is running on port 8080 and serving the ");
            strcat(response, filename);
            strcat(response, " file.</p>\r\n");
            strcat(response, "</body>\r\n");
            strcat(response, "</html>\r\n");

            response_len = strlen(response);
            write(portno, response, response_len);
            printf("Sent: %s\n", response);
        }
        close(portno);
    }
    return 0;
}