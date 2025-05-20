//Gemma-7B DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

int main() {
    int sockfd, port, n, i, len, recv_len;
    char buffer[1024], filename[256], mail[256], subject[256];
    struct sockaddr_in server_addr;
    FILE *fp;

    // Define port number
    port = 10001;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive mail
    recv_len = recv(sockfd, buffer, 1024, 0);
    if (recv_len > 0) {
        printf("Received mail:\n");
        printf("%s\n", buffer);
    }

    // Extract mail information
    strcpy(mail, strstr(buffer, "From:"));
    strcpy(subject, strstr(buffer, "Subject:"));
    strcpy(filename, strstr(buffer, "Attachment:"));

    // Save mail to file
    fp = fopen(filename, "w");
    fprintf(fp, "%s", buffer);
    fclose(fp);

    // Close socket
    close(sockfd);

    return 0;
}