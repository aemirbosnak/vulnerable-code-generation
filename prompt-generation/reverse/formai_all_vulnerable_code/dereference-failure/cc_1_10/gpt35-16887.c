//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// PUZZLE CLUE 1: The POP3 port number is hidden within this string
const char challenge[] = "SolveMeIfYouCan POP3 server is running on port number %d. Access it now!\n";

int main(int argc, char* argv[]) {
    // PUZZLE CLUE 2: The IP address of the POP3 server is hidden in the name of the program
    char* program_name = argv[0];
    char* ip_str = strtok(program_name, ".");
    ip_str = strtok(NULL, ".");
    ip_str = strtok(NULL, ".");
    ip_str = strtok(NULL, ".");
    char* pop3_ip = ip_str;

    // PUZZLE CLUE 3: The POP3 username and password are hidden within these variables
    char username[128];
    char password[128];

    // Prompt user for their username and password to authenticate with the POP3 server
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    int pop3_port = 0; // initialize port number to 0

    // Parse command line arguments for the POP3 port number
    if (argc == 2) {
        pop3_port = atoi(argv[1]);
    } else {
        printf("Usage: %s <pop3_port>\n", argv[0]);
        exit(1);
    }

    // Create a TCP socket to connect to the POP3 server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Construct the server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(pop3_ip);
    server_addr.sin_port = htons(pop3_port);

    // Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char recv_buf[1024]; // buffer to receive server responses
    int num_bytes;

    // PUZZLE CLUE 4: A secret command to retrieve a list of emails is hidden within this message
    char* list_cmd = "LIST Please"; 

    // Send the POP3 "USER" command to the server
    char user_cmd[128];
    sprintf(user_cmd, "USER %s\r\n", username);
    send(sockfd, user_cmd, strlen(user_cmd), 0);

    // Receive server response to "USER" command
    num_bytes = recv(sockfd, recv_buf, sizeof(recv_buf), 0);
    recv_buf[num_bytes] = '\0';
    printf("%s", recv_buf);

    // Send the POP3 "PASS" command to the server
    char pass_cmd[128];
    sprintf(pass_cmd, "PASS %s\r\n", password);
    send(sockfd, pass_cmd, strlen(pass_cmd), 0);

    // Receive server response to "PASS" command
    num_bytes = recv(sockfd, recv_buf, sizeof(recv_buf), 0);
    recv_buf[num_bytes] = '\0';
    printf("%s", recv_buf);

    // PUZZLE CLUE 5: A hint to the user on how to access their emails is hidden within this message
    printf("Successfully authenticated with the POP3 server. Type \"%s\" to retrieve list of emails.\n", list_cmd);

    // Keep receiving input from the user until they type "quit" or encounter an error
    char input[128];
    while (1) {
        printf("> ");
        scanf("%s", input);

        // If user types "QUIT", send the command to the server and exit
        if (strcmp(input, "QUIT") == 0) {
            char quit_cmd[128];
            sprintf(quit_cmd, "QUIT\r\n");
            send(sockfd, quit_cmd, strlen(quit_cmd), 0);

            num_bytes = recv(sockfd, recv_buf, sizeof(recv_buf), 0);
            recv_buf[num_bytes] = '\0';
            printf("%s", recv_buf);

            close(sockfd);
            break;
        }

        // If user types the secret command, send it to the server to retrieve the list of emails
        if (strcmp(input, list_cmd) == 0) {
            send(sockfd, input, strlen(input), 0);

            num_bytes = recv(sockfd, recv_buf, sizeof(recv_buf), 0);
            recv_buf[num_bytes] = '\0';
            printf("%s", recv_buf);
        }
    }

    return 0;
}