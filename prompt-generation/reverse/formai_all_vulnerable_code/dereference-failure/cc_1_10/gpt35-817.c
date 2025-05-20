//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to print error message and exit
void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    // Get port number from command line argument
    portno = atoi(argv[2]);
    
    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Get host by name
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Fill in serv_addr struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Receive greeting message from server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send USER command to server
    char user_input[255] = "";
    printf("Enter your username: ");
    fgets(user_input, 255, stdin);
    char* user_command = "USER ";
    strcat(user_command, user_input);
    n = write(sockfd, user_command, strlen(user_command));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive response to USER command from server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send PASS command to server
    char pass_input[255] = "";
    printf("Enter your password: ");
    fgets(pass_input, 255, stdin);
    char* pass_command = "PASS ";
    strcat(pass_command, pass_input);
    n = write(sockfd, pass_command, strlen(pass_command));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive response to PASS command from server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send LIST command to server
    char* list_command = "LIST\r\n";
    n = write(sockfd, list_command, strlen(list_command));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive response to LIST command from server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}