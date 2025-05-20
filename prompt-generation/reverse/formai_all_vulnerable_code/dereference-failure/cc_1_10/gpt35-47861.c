//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAXSIZE 65536
#define FTP_PORT 21

// Function to receive reply from FTP server
void receive_reply(int sock_fd) {
    char buffer[MAXSIZE];
    int numbytes;
    memset(buffer, 0, MAXSIZE);
    numbytes = recv(sock_fd, buffer, MAXSIZE, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);
}

int main(int argc, char *argv[]) {
    int sock_fd, data_fd, file_fd;
    struct sockaddr_in server_addr, data_addr;
    char user[MAXSIZE], pass[MAXSIZE], filename[MAXSIZE], buffer[MAXSIZE], *cmd;
    int numbytes, data_port;

    // Check for correct number of arguments
    if(argc != 4) {
        printf("Usage: ftp <hostname> <username> <password>\n");
        exit(1);
    }

    // Create socket for FTP connection
    if((sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    if(inet_pton(AF_INET, argv[1], &server_addr.sin_addr) == -1) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to server
    if(connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receive welcome message from FTP server
    receive_reply(sock_fd);

    // Send username
    sprintf(user, "USER %s\r\n", argv[2]);
    send(sock_fd, user, strlen(user), 0);

    // Receive reply
    receive_reply(sock_fd);

    // Send password
    sprintf(pass, "PASS %s\r\n", argv[3]);
    send(sock_fd, pass, strlen(pass), 0);

    // Receive reply
    receive_reply(sock_fd);

    // Set up data socket
    if((data_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set up server address for data connection
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = INADDR_ANY;
    data_addr.sin_port = htons(0);

    // Bind data socket to local address
    if(bind(data_fd, (struct sockaddr *) &data_addr, sizeof(data_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Get port number assigned by OS for data socket
    socklen_t len = sizeof(data_addr);
    getsockname(data_fd, (struct sockaddr *) &data_addr, &len);
    data_port = ntohs(data_addr.sin_port);

    // Send PASV command to FTP server
    send(sock_fd, "PASV\r\n", 6, 0);

    // Receive reply
    receive_reply(sock_fd);

    // Parse reply to get data port number
    char *reply = strdup(buffer);
    strtok(reply, "(");
    strtok(NULL, ",");
    strtok(NULL, ",");
    strtok(NULL, ",");
    strtok(NULL, ",");
    int p1 = atoi(strtok(NULL, ","));
    int p2 = atoi(strtok(NULL, ")"));
    int port = p1*256 + p2;

    // Connect data socket to server's data port
    data_addr.sin_addr.s_addr = server_addr.sin_addr.s_addr;
    data_addr.sin_port = htons(port);
    if(connect(data_fd, (struct sockaddr *) &data_addr, sizeof(data_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Receive reply
    receive_reply(sock_fd);

    // Get filename to download
    printf("Enter filename: ");
    scanf("%s", filename);

    // Send RETR command to FTP server
    sprintf(buffer, "RETR %s\r\n", filename);
    send(sock_fd, buffer, strlen(buffer), 0);

    // Receive reply
    receive_reply(sock_fd);

    // Check reply code to see if file exists
    sscanf(buffer, "%d", &numbytes);
    if(numbytes != 550) {
        // Open file for writing
        file_fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, 0600);

        // Read data from data socket and write to file
        while((numbytes = recv(data_fd, buffer, MAXSIZE, 0)) > 0) {
            write(file_fd, buffer, numbytes);
        }

        // Close file and data socket
        close(file_fd);
        close(data_fd);

        printf("Download complete!\n");
    } else {
        printf("File does not exist!\n");
        close(data_fd);
    }

    // Send QUIT command to FTP server
    send(sock_fd, "QUIT\r\n", 6, 0);

    // Receive reply
    receive_reply(sock_fd);

    // Close control socket
    close(sock_fd);

    return 0;
}