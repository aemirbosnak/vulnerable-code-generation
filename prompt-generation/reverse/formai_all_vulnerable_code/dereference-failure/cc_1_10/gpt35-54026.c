//FormAI DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024 // Maximum size of receive buffer.

void sendRequest(int sockfd, char *request);
void readResponse(int sockfd);
void checkResponse(char *response);
void closeConnection(int sockfd);

int main(int argc, char **argv) {
    int sockfd, port;
    char *hostname, *username, *password, buffer[MAX_BUFFER_SIZE];

    if(argc != 5) {
        printf("Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];

    // Step 1. Create socket.
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        perror("Unable to create socket");
        exit(1);
    }

    // Step 2. Connect to server.
    struct hostent *he;
    struct in_addr **addr_list;

    if((he = gethostbyname(hostname)) == NULL) {
        herror("Unable to resolve hostname");
        exit(1);
    }

    addr_list = (struct in_addr **) he->h_addr_list;

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr = *addr_list[0];

    if(connect(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Unable to connect to server");
        closeConnection(sockfd);
        exit(1);
    }

    // Step 3. Send login request.
    sprintf(buffer, "LOGIN %s %s\n", username, password);
    sendRequest(sockfd, buffer);
    readResponse(sockfd);
    checkResponse(buffer);

    // Step 4. Send email request.
    printf("To: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    char *to = strtok(buffer, "\n");

    printf("Subject: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    char *subject = strtok(buffer, "\n");

    printf("Message: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    char *message = strtok(buffer, "\n");

    sprintf(buffer, "EMAIL %s %s %s\n", to, subject, message);
    sendRequest(sockfd, buffer);
    readResponse(sockfd);
    checkResponse(buffer);

    // Step 5. Close connection.
    closeConnection(sockfd);

    return 0;
}

void sendRequest(int sockfd, char *request) {
    if(write(sockfd, request, strlen(request)) < 0) {
        perror("Unable to send request");
        exit(1);
    }
}

void readResponse(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);

    if(read(sockfd, buffer, MAX_BUFFER_SIZE) < 0) {
        perror("Unable to read response");
        exit(1);
        }

    printf("%s\n", buffer);
}

void checkResponse(char *response) {
    if(strncmp(response, "ERROR", 5) == 0) {
        printf("Wrong Credentials, Please try again.\n");
        exit(1);
    }
}

void closeConnection(int sockfd) {
    close(sockfd);
}