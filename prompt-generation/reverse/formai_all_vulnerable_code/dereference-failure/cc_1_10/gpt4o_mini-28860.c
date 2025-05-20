//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_ftp_server(const char *hostname, int port) {
    struct sockaddr_in server_addr;
    int sockfd;
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("ERROR opening socket");
    }

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void send_command(int sockfd, const char *command) {
    write(sockfd, command, strlen(command));
    write(sockfd, "\r\n", 2);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
        if (n < BUFFER_SIZE - 1) {
            break;
        }
    }
    if (n < 0) {
        error("ERROR reading from socket");
    }
}

void login(int sockfd) {
    char username[128], password[128];
    
    printf("Enter FTP username: ");
    fgets(username, sizeof(username), stdin);
    strtok(username, "\n"); // Strip newline character

    send_command(sockfd, "USER");
    send_command(sockfd, username);
    receive_response(sockfd);

    printf("Enter FTP password: ");
    fgets(password, sizeof(password), stdin);
    strtok(password, "\n"); // Strip newline character

    send_command(sockfd, "PASS");
    send_command(sockfd, password);
    receive_response(sockfd);
}

void list_files(int sockfd) {
    send_command(sockfd, "PASV");
    receive_response(sockfd);

    // Assume response contains the data connection port
    // For simplicity, assume fixed port for this example. 
    int data_sock = connect_to_ftp_server("127.0.0.1", 2121); // Example data port

    send_command(sockfd, "LIST");
    receive_response(data_sock);
    close(data_sock);
}

void quit_ftp(int sockfd) {
    send_command(sockfd, "QUIT");
    receive_response(sockfd);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(0);
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);

    int sockfd = connect_to_ftp_server(hostname, port);
    receive_response(sockfd); // Receive server greeting

    login(sockfd);
    
    char choice[10];
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. List files\n");
        printf("2. Quit\n");
        printf("Your choice: ");
        fgets(choice, sizeof(choice), stdin);
        strtok(choice, "\n"); // Strip newline character

        if (strcmp(choice, "1") == 0) {
            list_files(sockfd);
        } else if (strcmp(choice, "2") == 0) {
            quit_ftp(sockfd);
            break;
        } else {
            printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}