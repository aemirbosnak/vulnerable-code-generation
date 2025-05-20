//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char**argv) {

    int sockfd = 0, n = 0, port = 0;
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in serv_addr;
    char server_address[100] = {0};
    char user_name[100] = {0};
    char password[100] = {0};

    if (argc != 3) {
        printf("\n Usage: %s <Server Address> <Port Number>\n", argv[0]);
        return 1;
    }

    strcpy(server_address, argv[1]);
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("\n Error : Could not create socket \n");
        return 1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, server_address, &serv_addr.sin_addr) <= 0) {
        printf("\n Error : Invalid Server Address \n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n Error : Connection Failed \n");
        return 1;
    }

    printf("\n Connected to Server \n");

    // Fetching Login Details
    printf("\n Enter the Email ID : ");
    fgets(user_name, 99, stdin);
    user_name[strcspn(user_name, "\n")] = 0; //Removing the trailing New Line character

    printf("\n Enter the Password : ");
    fgets(password, 99, stdin);
    password[strcspn(password, "\n")] = 0; //Removing the trailing New Line character

    // Sending Login Credentials
    sprintf(buffer, "a001 LOGIN %s %s\r\n", user_name, password);
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, '0', sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        printf("\n Error : Unable to Login \n");
        return 1;
    }

    printf("\n Server Response : %s", buffer);

    //Fetching Inbox List
    sprintf(buffer, "a002 LIST \"\" *\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, '0', sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        printf("\n Error : Unable to fetch Inbox List \n");
        return 1;
    }

    printf("\n Server Response : %s", buffer);

    //Fetching Inbox Messages
    sprintf(buffer, "a003 SELECT INBOX\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, '0', sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        printf("\n Error : Unable to fetch Inbox Messages \n");
        return 1;
    }

    printf("\n Server Response : %s", buffer);

    // Closing Connection
    sprintf(buffer, "a004 LOGOUT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    memset(buffer, '0', sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        printf("\n Error : Unable to Logout \n");
        return 1;
    }

    printf("\n Server Response : %s", buffer);

    close(sockfd);
    return 0;
}