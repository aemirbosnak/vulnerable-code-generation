//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "pop.server.com"
#define USER "thy_username"
#define PASS "thine_password"
#define PORT 110
#define BUFFER_SIZE 1024

void print_message(const char *message) {
    printf("%s\n", message);
}

int main() {
    int sockfd, port;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    port = PORT;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        print_message("Alas! The socket could not be created!");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        print_message("Sorrowful fate! Unable to connect to the domain!");
        return -1;
    }

    read(sockfd, buffer, sizeof(buffer));
    print_message(buffer);

    // Send USER command
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", USER);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    print_message(buffer);

    // Send PASS command
    snprintf(buffer, sizeof(buffer), "PASS %s\r\n", PASS);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    print_message(buffer);

    // Send LIST command
    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    print_message(buffer);

    // Let us exit the tragic code
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, sizeof(buffer));
    print_message(buffer);

    close(sockfd);
    print_message("Thus exits our humble POP3 client; the ending bittersweet, like love's own tale.");
  
    return 0;
}