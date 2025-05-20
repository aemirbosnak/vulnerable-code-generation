//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 1024

int main(int argc, char **argv) {
        char url[MAX_URL_LENGTH];
        int port;
        int timeout;
        char response[MAX_RESPONSE_LENGTH];
        char *host;
        char *path;
        struct hostent *server;
        struct sockaddr_in serv_addr;
        int sockfd;
        int n;
        time_t start_time;
        time_t end_time;

        if (argc != 4) {
                fprintf(stderr, "Usage: %s <url> <port> <timeout>\n", argv[0]);
                exit(EXIT_FAILURE);
        }

        strcpy(url, argv[1]);
        port = atoi(argv[2]);
        timeout = atoi(argv[3]);

        // Parse the URL into host and path
        host = strtok(url, "/");
        path = strtok(NULL, "");

        // Get the server's IP address
        server = gethostbyname(host);
        if (server == NULL) {
                fprintf(stderr, "Error: could not resolve hostname '%s'\n", host);
                exit(EXIT_FAILURE);
        }

        // Create a socket
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
                fprintf(stderr, "Error: could not create socket\n");
                exit(EXIT_FAILURE);
        }

        // Set the socket timeout
        struct timeval tv;
        tv.tv_sec = timeout;
        tv.tv_usec = 0;
        if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) < 0) {
                fprintf(stderr, "Error: could not set socket timeout\n");
                exit(EXIT_FAILURE);
        }

        // Connect to the server
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
                fprintf(stderr, "Error: could not connect to server\n");
                exit(EXIT_FAILURE);
        }

        // Send the HTTP request
        char request[MAX_RESPONSE_LENGTH];
        sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
        n = write(sockfd, request, strlen(request));
        if (n < 0) {
                fprintf(stderr, "Error: could not send HTTP request\n");
                exit(EXIT_FAILURE);
        }

        // Start the timer
        start_time = time(NULL);

        // Read the HTTP response
        n = read(sockfd, response, MAX_RESPONSE_LENGTH);
        if (n < 0) {
                fprintf(stderr, "Error: could not read HTTP response\n");
                exit(EXIT_FAILURE);
        }

        // Stop the timer
        end_time = time(NULL);

        // Print the HTTP response
        printf("%s\n", response);

        // Check the HTTP status code
        char *status_code = strtok(response, " ");
        if (strcmp(status_code, "200") != 0) {
                fprintf(stderr, "Error: server returned HTTP status code %s\n", status_code);
                exit(EXIT_FAILURE);
        }

        // Calculate the response time
        double response_time = difftime(end_time, start_time);

        // Print the response time
        printf("Response time: %.3f seconds\n", response_time);

        // Close the socket
        close(sockfd);

        return EXIT_SUCCESS;
}