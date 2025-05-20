//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define WAIT_TIME 3

#define GET "GET"
#define QUIT "QUIT"

/* Function Declarations */
int createSocket();
int connectToServer(int sockfd, char *ip_addr, int port);
void receiveResponse(int sockfd, char *server_response);
void sendRequest(int sockfd, char *request);
void runClient(int sockfd);
void quit(int sockfd);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <ip_address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd = createSocket();
    int port = atoi(argv[2]);

    if (connectToServer(sockfd, argv[1], port) == -1) {
        printf("Error: Failed to connect to the server.\n");
        exit(EXIT_FAILURE);
    }

    runClient(sockfd);

    return 0;
}

/* Create Socket */
int createSocket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("Error: Failed to create a socket.\n");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

/* Connect to Server */
int connectToServer(int sockfd, char *ip_addr, int port) {
    struct sockaddr_in server_address;
    server_address.sin_addr.s_addr = inet_addr(ip_addr);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (connect(sockfd , (struct sockaddr *)&server_address , sizeof(server_address)) == -1) {
        perror("Error: Connection failed.");
        return -1;
    }

    return 0;
}

/* Receive Response */
void receiveResponse(int sockfd, char *server_response) {
    memset(server_response, '\0', BUFFER_SIZE);
    read(sockfd, server_response, BUFFER_SIZE);
}

/* Send Request */
void sendRequest(int sockfd, char *request) {
    if (write(sockfd, request, strlen(request)) == -1) {
        perror("Error: Failed to send request.\n");
        exit(EXIT_FAILURE);
    }
}

/* Run FTP Client */
void runClient(int sockfd) {
    char request[BUFFER_SIZE], response[BUFFER_SIZE];

    // Receive welcome message
    receiveResponse(sockfd, response);
    printf("%s", response);

    //Login credentials
    char username[50], password[50];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    //Sending user credentials
    char userauth[100];
    sprintf(userauth, "USER %s\r\n", username);
    sendRequest(sockfd, userauth);
    receiveResponse(sockfd, response);
    printf("%s", response);

    sprintf(userauth, "PASS %s\r\n", password);
    sendRequest(sockfd, userauth);
    receiveResponse(sockfd, response);
    printf("%s", response);

    int connected = 1;
    while(connected) {
        printf("Enter FTP Command: ");
        memset(request, '\0', BUFFER_SIZE);
        scanf("%s", request);

        if(strcmp(request, GET) == 0) {
            // Getting the file from server
            char filename[50];
            printf("Enter Filename: ");
            scanf("%s", filename);

            char download[BUFFER_SIZE] = "";
            sprintf(download, "RETR %s\n", filename);

            // Send the retr command to server
            sendRequest(sockfd, download);
            receiveResponse(sockfd, response);
            printf("%s", response);

            // Check if the file was found on server
            if (strstr(response, "550") != NULL) {
                printf("Error: File not found on server.\n");
                continue;
            }

            // Create new file and download data
            FILE *fd = fopen(filename, "wb");

            while (1) {
                receiveResponse(sockfd, response);

                if (strstr(response, "226") != NULL) {
                    break;
                }

                fwrite(response, sizeof(char), strlen(response), fd);
                memset(response, '\0', BUFFER_SIZE);
            }

            fclose(fd);
        } else if(strcmp(request, QUIT) == 0) {
            // Disconnect from the server
            quit(sockfd);
            connected = 0;
        } else {
            // Send any ftp command that is not GET or QUIT
            sendRequest(sockfd, request);
            receiveResponse(sockfd, response);
            printf("%s", response);
        }

        //Wait for a few seconds
        sleep(WAIT_TIME);
    }
}

/* Quit FTP Client */
void quit(int sockfd) {
    sendRequest(sockfd, "QUIT\r\n");
    char goodbye[BUFFER_SIZE];
    receiveResponse(sockfd, goodbye);
    printf("%s", goodbye);
    close(sockfd);
}