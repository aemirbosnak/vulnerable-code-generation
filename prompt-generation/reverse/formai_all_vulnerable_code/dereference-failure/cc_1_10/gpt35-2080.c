//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAXDATASIZE 1024

// Function to receive message from server
void receiving(int sockfd, char* buffer, int size) {
    int n = recv(sockfd, buffer, size, 0);
    if (n < 0) {
        perror("Error receiving message from server.\n");
        exit(1);
    }
    buffer[n] = '\0';
}

// Function to send message to server
void sending(int sockfd, char* message) {
    int n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("Error sending message to server.\n");
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    struct hostent *he;
    struct sockaddr_in their_addr;

    if (argc != 3) {
        fprintf(stderr,"usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    if ((he=gethostbyname(argv[1])) == NULL) {
        perror("Error getting host by name.\n");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket.\n");
        exit(1);
    }

    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(atoi(argv[2]));
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);

    memset(&(their_addr.sin_zero), '\0', 8);

    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("Error connecting.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    // Login
    char user[MAXDATASIZE], password[MAXDATASIZE];
    memset(user, 0, MAXDATASIZE);
    memset(password, 0, MAXDATASIZE);

    printf("Username: ");
    scanf("%s", user);

    printf("Password: ");
    scanf("%s", password);

    char loginMessage[MAXDATASIZE];
    sprintf(loginMessage, "USER %s\r\n", user);
    sending(sockfd, loginMessage);
    receiving(sockfd, buf, MAXDATASIZE);

    if (strncmp(buf, "331", 3) != 0) {
        printf("Invalid username. Disconnecting...\n");
        close(sockfd);
        exit(0);
    }

    sprintf(loginMessage, "PASS %s\r\n", password);
    sending(sockfd, loginMessage);
    receiving(sockfd, buf, MAXDATASIZE);

    if (strncmp(buf, "230", 3) != 0) {
        printf("Invalid password. Disconnecting...\n");
        close(sockfd);
        exit(0);
    }

    printf("Successfully logged in.\n");

    // Menu
    while (1) {
        printf("Choose an option:\n");
        printf("1. List files\n");
        printf("2. Download file\n");
        printf("3. Upload file\n");
        printf("4. Quit\n");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            sending(sockfd, "LIST\r\n");
            receiving(sockfd, buf, MAXDATASIZE);
            printf("%s\n", buf);
        } else if (option == 2) {
            printf("Enter filename: ");
            char filename[MAXDATASIZE];
            scanf("%s", filename);
            char message[MAXDATASIZE];
            sprintf(message, "RETR %s\r\n", filename);
            sending(sockfd, message);
            receiving(sockfd, buf, MAXDATASIZE);
            if (strncmp(buf, "550", 3) == 0) {
                printf("File not found.\n");
                continue;
            }
            FILE* file = fopen(filename, "w");
            while ((numbytes = recv(sockfd, buf, MAXDATASIZE, 0)) > 0) {
                fwrite(buf, sizeof(char), numbytes, file);
            }
            fclose(file);
            printf("File downloaded.\n");
        } else if (option == 3) {
            printf("Enter filename: ");
            char filename[MAXDATASIZE];
            scanf("%s", filename);
            FILE* file = fopen(filename, "r");
            if (file == NULL) {
                printf("File not found.\n");
                continue;
            }
            char message[MAXDATASIZE];
            sprintf(message, "STOR %s\r\n", filename);
            sending(sockfd, message);
            receiving(sockfd, buf, MAXDATASIZE);
            if (strncmp(buf, "553", 3) == 0) {
                printf("Permission denied.\n");
                continue;
            }
            while ((numbytes = fread(buf, sizeof(char), MAXDATASIZE, file)) > 0) {
                send(sockfd, buf, numbytes, 0);
            }
            fclose(file);
            printf("File uploaded.\n");
        } else if (option == 4) {
            printf("Disconnecting...\n");
            break;
        }
    }

    close(sockfd);

    return 0;
}