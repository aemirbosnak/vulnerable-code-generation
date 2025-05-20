//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define PORT 8080 // Default HTTP port
#define BUFFER_SIZE 1024

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, n, i;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));

    // Set server address family and port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to specified address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    while (1)
    {
        // Wait for incoming connection
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        memset(buffer, 0, BUFFER_SIZE);

        n = read(newsockfd, buffer, BUFFER_SIZE - 1); // Read client request
        if (n < 0)
            error("ERROR reading from socket");

        printf("Received request:\n%s\n", buffer);

        // Parse client request
        char method[10], url[BUFFER_SIZE], version[10];
        sscanf(buffer, "%s %s %s", method, url, version);

        printf("Parsed request:\nMethod: %s\nURL: %s\nVersion: %s\n", method, url, version);

        // Open connection to destination server
        char *dest_host_start = strstr(url, "://") + 3;
        char *dest_host_end = strchr(dest_host_start, '/');
        int dest_host_len = dest_host_end - dest_host_start;
        char dest_host[dest_host_len + 1];
        strncpy(dest_host, dest_host_start, dest_host_len);
        dest_host[dest_host_len] = '\0';

        struct hostent *dest = gethostbyname(dest_host);

        printf("Connecting to: %s\n", dest->h_name);

        struct sockaddr_in dest_addr;
        memset(&dest_addr, 0, sizeof(dest_addr));
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(PORT);
        memcpy(&dest_addr.sin_addr.s_addr, dest->h_addr, dest->h_length);

        int destfd = socket(AF_INET, SOCK_STREAM, 0);
        if (destfd < 0)
            error("ERROR opening socket");

        if (connect(destfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0)
            error("ERROR connecting to server");

        // Send request to destination server
        n = write(destfd, buffer, strlen(buffer));
        if (n < 0)
            error("ERROR writing to socket");

        printf("Sent request:\n%s\n", buffer);

        // Receive response from destination server and relay back to client
        int dest_bytes_read, dest_bytes_written;
        while((dest_bytes_read = read(destfd, buffer, BUFFER_SIZE - 1)) > 0)
        {
            dest_bytes_written = write(newsockfd, buffer, dest_bytes_read);
            if (dest_bytes_written < dest_bytes_read)
                error("ERROR writing to socket");
        }
    }

    close(sockfd);
    return 0;
}