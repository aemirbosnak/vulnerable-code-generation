//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

/** Function to print error messages **/
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int portno = atoi(argv[1]);

    /** Create socket **/
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    struct sockaddr_in serv_addr, cli_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    /** Set Properties of the Server **/
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    /** Bind the Server to the Port **/
    if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    int clilen = sizeof(cli_addr);

    /** Listen for incoming requests **/
    listen(sockfd, 5);
    
    printf("Server listening on port %d...", portno);

    /** Continuously accept incoming requests **/
    while (1) {
        int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        char buffer[4096];
        bzero(buffer, 4096);
        int n = read(newsockfd, buffer, 4096);
        if (n < 0)
            error("ERROR reading from socket");

	printf("%s\n", buffer);

        /** Extract the Requested URL **/
        char* temp = strtok(buffer, " ");
        temp = strtok(NULL, " ");
        char* url = strtok(temp, "//");
        char* host = strtok(NULL, "/");
        char* path = strtok(NULL, " ");
        strcat(path, url + strlen(host) + strlen("//"));

        printf("%s", "Requested URL: ");
        printf("%s", url);
        printf("%s", "\n");

        /** Get the IP Address of the Host **/
        struct hostent* hostent = gethostbyname(host);
        char* ip = inet_ntoa(*((struct in_addr*) hostent->h_addr_list[0]));

        printf("%s", "Host IP Address: ");
        printf("%s", ip);
        printf("%s", "\n");

        /** Create Connection with the Host **/
        int host_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (host_sockfd < 0)
            error("ERROR opening socket");

        struct sockaddr_in host_addr;
        memset(&host_addr, 0, sizeof(host_addr));

        host_addr.sin_family = AF_INET;
        host_addr.sin_addr.s_addr = inet_addr(ip);
        host_addr.sin_port = htons(80);

        if (connect(host_sockfd, (struct sockaddr*) &host_addr, sizeof(host_addr)) < 0)
            error("ERROR connecting");

        /** Send the Request **/
        char req[4096];
        char* req_format = "%s /%s HTTP/1.0\r\nHost: %s\r\n\r\n";
        sprintf(req, req_format, "GET", path, host);

        printf("%s", "Request: ");
        printf("%s", req);
        printf("%s", "\n");

        if (write(host_sockfd, req, strlen(req)) < 0)
            error("ERROR writing to socket");

        bzero(buffer, 4096);

        /** Read the Response **/
        while (read(host_sockfd, buffer, 4096) > 0) {
            if (write(newsockfd, buffer, strlen(buffer)) < 0)
                error("ERROR writing to socket");

            bzero(buffer, 4096);
        }

        /** Close the Connections **/
        close(host_sockfd);
        close(newsockfd);
    }
    
    return 0;
}