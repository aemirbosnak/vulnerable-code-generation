//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[256];
    int n;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send command to server
    printf("Enter command: ");
    fgets(buffer, 255, stdin);

    // Parse command
    char *token;
    token = strtok(buffer, " \n");
    while (token!= NULL) {
        if (strcmp(token, "GET") == 0) {
            printf("Downloading file...\n");
            break;
        }
        token = strtok(NULL, " \n");
    }

    // Download file
    if (strcmp(token, "GET") == 0) {
        FILE *fp;
        char filename[256];

        printf("Enter filename: ");
        fgets(filename, 255, stdin);
        printf("Downloading %s...\n", filename);

        // Open file for writing
        if ((fp = fopen(filename, "w")) == NULL) {
            perror("ERROR opening file");
            exit(1);
        }

        // Read file from server
        while ((n = recv(sockfd, buffer, 256, 0)) > 0) {
            fwrite(buffer, 1, n, fp);
        }
        fclose(fp);
        printf("Download complete.\n");
    }

    // Close socket
    close(sockfd);

    return 0;
}