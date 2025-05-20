//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: statistical
// Building an FTP Client - A Statistical Adventure

// Preamble: Embark on a statistical quest to establish an FTP connection.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

// Constants: Defining the dimensions of our statistical expedition.

#define FTP_PORT 21
#define BUFF_SIZE 1024

// Function Declarations: Charting our course through the FTP landscape.

int connect_ftp(char *hostname, int port);
void send_command(int sock, char *cmd, char *args);
int get_response(int sock, char *buf, int size);

// Main Function: The epicenter of our statistical endeavors.

int main(int argc, char **argv) {
    // Hypothesis 1: Test if the user has provided sufficient arguments.
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Hypothesis 2: Attempt to establish an FTP connection.
    int sock = connect_ftp(argv[1], atoi(argv[2]));
    if (sock == -1) {
        printf("Error: Could not connect to FTP server.\n");
        return 1;
    }

    // Hypothesis 3: Send a USER command to the FTP server.
    send_command(sock, "USER", argv[3]);

    // Hypothesis 4: Collect the server's response.
    char buf[BUFF_SIZE];
    int resp = get_response(sock, buf, BUFF_SIZE);

    // Hypothesis 5: Analyze the response to determine if login was successful.
    if (resp == 230) {
        printf("Logged in successfully.\n");
    } else {
        printf("Login failed: %s\n", buf);
    }

    // Hypothesis 6: Close the FTP connection.
    close(sock);

    return 0;
}

// Function Implementations: Navigating the intricacies of FTP protocols.

int connect_ftp(char *hostname, int port) {
    // Hypothesis A: Resolve the hostname to an IP address.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        return -1;
    }

    // Hypothesis B: Create a socket for communication.
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        return -1;
    }

    // Hypothesis C: Connect the socket to the FTP server.
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        return -1;
    }

    return sock;
}

void send_command(int sock, char *cmd, char *args) {
    // Hypothesis A: Concatenate the command and arguments into a buffer.
    char buf[BUFF_SIZE];
    sprintf(buf, "%s %s\r\n", cmd, args);

    // Hypothesis B: Send the command buffer to the FTP server.
    send(sock, buf, strlen(buf), 0);
}

int get_response(int sock, char *buf, int size) {
    // Hypothesis A: Receive the server's response into a buffer.
    int len = recv(sock, buf, size, 0);
    if (len <= 0) {
        return -1;
    }

    // Hypothesis B: Convert the response code to an integer.
    int code = atoi(buf + 3);

    return code;
}