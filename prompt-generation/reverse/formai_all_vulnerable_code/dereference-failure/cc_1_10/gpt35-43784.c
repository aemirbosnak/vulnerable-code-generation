//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

void print_menu() {
    printf("------ POP3 Client ------\n");
    printf("1. Connect to server\n");
    printf("2. Send request\n");
    printf("3. Quit\n");
    printf("-------------------------\n");
}

void send_request(int sockfd) {
    char buffer[BUF_SIZE];
    bzero(buffer, BUF_SIZE);
    printf("Enter command: ");
    fgets(buffer, BUF_SIZE-1, stdin);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
        error("ERROR sending message to server");
    bzero(buffer, BUF_SIZE);
    if (recv(sockfd, buffer, BUF_SIZE-1, 0) < 0)
        error("ERROR receiving message from server");
    printf("%s", buffer);
}

int main() {
    int sockfd, portno, n;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    while (1) {
        print_menu();
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        while (getchar() != '\n'); // clear input buffer
        switch (choice) {
            case 1: // connect to server
                portno = 110;
                sockfd = socket(AF_INET, SOCK_STREAM, 0);
                if (sockfd < 0)
                    error("ERROR opening socket");
                server = gethostbyname("pop.example.com");
                if (server == NULL)
                    error("ERROR no such host");
                bzero((char*)&serv_addr, sizeof(serv_addr));
                serv_addr.sin_family = AF_INET;
                bcopy((char*)server->h_addr_list[0],
                      (char*)&serv_addr.sin_addr.s_addr,
                      server->h_length);
                serv_addr.sin_port = htons(portno);
                if (connect(sockfd, (struct sockaddr*)&serv_addr,
                            sizeof(serv_addr)) < 0)
                    error("ERROR connecting");
                break;
            case 2: // send request
                send_request(sockfd);
                break;
            case 3: // quit
                close(sockfd);
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}