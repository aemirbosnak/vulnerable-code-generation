//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

// Passive mode (PASV) request
int PASV(int sock) {
    char buf[MAX_BUF_SIZE];
    char* cmd = "PASV\r\n";
    int ret, port;

    if(send(sock, cmd, strlen(cmd), 0) == -1) {
        perror("send");
        return -1;
    }

    if((ret = recv(sock, buf, MAX_BUF_SIZE, 0)) == -1) {
        perror("recv");
        return -1;
    }
    buf[ret] = '\0';

    // Extract server IP and port from the server's response
    const char s[2] = ",";
    char *token, *ip, *port_str;
    token = strtok(buf, s);
    while(token != NULL) {
        ip = token;
        token = strtok(NULL, s);
        ip = strtok(ip, "(");
        if(strcmp(ip, "127.0.0.1") == 0) {
            ip = "localhost";
        }
        if(token == NULL) {
            break;
        }
        token = strtok(NULL, s);
        token = strtok(NULL, s);
        token = strtok(NULL, s);
        token = strtok(NULL, s);
        token = strtok(NULL, s);
        port_str = token;
        break;
    }

    // Extract port number
    port = atoi(port_str);
    port = (port * 256) + atoi(strtok(NULL, s));

    // Create socket for data connection
    struct sockaddr_in data_addr;
    data_addr.sin_family = AF_INET;
    data_addr.sin_addr.s_addr = inet_addr(ip);
    data_addr.sin_port = htons(port);

    int data_sock;
    if((data_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return -1;
    }

    // Connect to data socket
    if(connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) == -1) {
        perror("connect");
        return -1;
    }

    return data_sock;
}

// Download file from server
int get(int sock, const char* filename) {
    char buf[MAX_BUF_SIZE];
    char* cmd = "RETR ";
    strcat(cmd, filename);
    strcat(cmd, "\r\n");
    int ret;

    // Start passive mode
    int data_sock = PASV(sock);

    if(send(sock, cmd, strlen(cmd), 0) == -1) {
        perror("send");
        return -1;
    }

    if((ret = recv(sock, buf, MAX_BUF_SIZE, 0)) == -1) {
        perror("recv");
        return -1;
    }
    buf[ret] = '\0';

    printf("%s", buf);

    // Open file for writing
    int file_fd = open(filename, O_CREAT | O_WRONLY, 0666);
    if(file_fd == -1) {
        perror("open");
        return -1;
    }

    // Download file and write to disk
    int data_read;
    while((data_read = recv(data_sock, buf, MAX_BUF_SIZE, 0)) > 0) {
        if(write(file_fd, buf, data_read) == -1) {
            perror("write");
            return -1;
        }
    }
    if(data_read == -1) {
        perror("recv");
        return -1;
    }

    // Close file and data socket
    close(file_fd);
    close(data_sock);

    if((ret = recv(sock, buf, MAX_BUF_SIZE, 0)) == -1) {
        perror("recv");
        return -1;
    }
    buf[ret] = '\0';

    printf("%s", buf);

    return 0;
}

int main(int argc, char** argv) {
    // Check command line arguments
    if(argc != 4) {
        printf("Usage: ./ftpclient <server> <port> <filename>");
        return -1;
    }

    // Extract command line arguments
    const char* server = argv[1];
    int port = atoi(argv[2]);
    const char* filename = argv[3];

    // Create socket for control connection
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("socket");
        return -1;
    }

    // Connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server);
    server_addr.sin_port = htons(port);
    if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return -1;
    }

    int data_sock = PASV(sock);

    // Send username and password
    char username[MAX_BUF_SIZE];
    char password[MAX_BUF_SIZE];
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    char auth[MAX_BUF_SIZE];
    sprintf(auth, "USER %s\r\nPASS %s\r\n", username, password);
    if(send(sock, auth, strlen(auth), 0) == -1) {
        perror("send");
        return -1;
    }

    char buf[MAX_BUF_SIZE];
    int ret;
    if((ret = recv(sock, buf, MAX_BUF_SIZE, 0)) == -1) {
        perror("recv");
        return -1;
    }
    buf[ret] = '\0';

    printf("%s", buf);

    // Request file
    if(get(sock, filename) == -1) {
        printf("Error downloading file.\n");
        return -1;
    }

    // Close control connection
    if(close(sock) == -1) {
        perror("close");
        return -1;
    }

    return 0;
}