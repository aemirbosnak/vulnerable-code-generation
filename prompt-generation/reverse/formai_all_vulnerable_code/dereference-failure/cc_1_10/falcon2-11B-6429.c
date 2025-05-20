//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

int main() {
    int sockfd, portno, newsockfd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(1234);

    // Bind socket
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen
    listen(sockfd, 5);

    while (1) {
        // Accept connection
        addrlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        // Receive message
        char buffer[1024];
        bzero(buffer, 1024);
        recv(newsockfd, buffer, 1024, 0);

        // Process message
        if (strcmp(buffer, "create") == 0) {
            // Create file
            printf("Creating file...\n");
            FILE *fp = fopen("test.txt", "w");
            fclose(fp);
        } else if (strcmp(buffer, "read") == 0) {
            // Read file
            printf("Reading file...\n");
            FILE *fp = fopen("test.txt", "r");
            fseek(fp, 0, SEEK_END);
            int size = ftell(fp);
            fseek(fp, 0, SEEK_SET);
            char *content = (char *)malloc(size + 1);
            fread(content, size, 1, fp);
            content[size] = '\0';
            printf("%s\n", content);
            free(content);
        } else if (strcmp(buffer, "write") == 0) {
            // Write file
            printf("Writing to file...\n");
            FILE *fp = fopen("test.txt", "a");
            fwrite(buffer, strlen(buffer), 1, fp);
            fclose(fp);
        } else if (strcmp(buffer, "delete") == 0) {
            // Delete file
            printf("Deleting file...\n");
            remove("test.txt");
        }

        // Close connection
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}