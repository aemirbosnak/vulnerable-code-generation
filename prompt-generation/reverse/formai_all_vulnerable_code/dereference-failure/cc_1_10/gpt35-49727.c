//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: happy
// Welcome to my IMAP client example program, it's gonna be an amazing journey!
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024

void login(int sockfd); // function to authenticate with IMAP server
void logout(int sockfd); // function to logout from IMAP server
void list(int sockfd); // function to list all available folders in the mailbox
void select_folder(int sockfd); // function to select a specific folder
void search(int sockfd); // function to search for emails in a selected folder
void fetch(int sockfd); // function to fetch a specific email from a selected folder

int main(int argc, char const *argv[]) {
    // let's start by creating a socket and establish a connection with the IMAP server
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        printf("Error: Cannot create socket.\n");
        exit(1);
    }
    
    server = gethostbyname("imap.googlemail.com");
    
    if (server == NULL) {
        printf("Error: Host not found.\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(993);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Cannot connect to server.\n");
        exit(1);
    }

    printf("Welcome to my IMAP client example program! Let's get started :)\n");

    login(sockfd); // let's authenticate with the IMAP server

    char choice;
    do {
        // let's show the user the available options
        printf("\n\n##############################\n");
        printf("What would you like to do?\n");
        printf("L - List available folders\n");
        printf("S - Select a specific folder\n");
        printf("R - Search for an email in a folder\n");
        printf("F - Fetch an email from a folder\n");
        printf("O - Logout\n");
        printf("##############################\n");
        printf("Your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'L': // listing available folders
                list(sockfd);
                break;
            
            case 'S': // selecting a specific folder
                select_folder(sockfd);
                break;

            case 'R': // searching for an email in a folder
                search(sockfd);
                break;

            case 'F': // fetching an email from a folder
                fetch(sockfd);
                break;

            case 'O': // logging out from IMAP server
                logout(sockfd);
                break;

            default: // invalid choice
                printf("Error: Invalid choice.\n");
                break;
        }

    } while (choice != 'O');

    close(sockfd); // close the socket connection
    printf("\n\nThank you for using my IMAP client example program. Have a great day :)\n");
    
    return 0;
}

void login(int sockfd) {
    // let's authenticate with the IMAP server
    char username[MAX_SIZE], password[MAX_SIZE];

    printf("\n\nPlease enter your email and password:\n");
    printf("Email: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    // send the login command to IMAP server
    char login_string[MAX_SIZE];
    sprintf(login_string, "LOGIN %s %s\r\n", username, password);

    if (send(sockfd, login_string, strlen(login_string), 0) < 0) {
        printf("Error: Cannot send data to server.\n");
        exit(1);
    }

    // let's receive the response from IMAP server
    char buffer[MAX_SIZE];
    int n = recv(sockfd, buffer, MAX_SIZE, 0);

    if (n < 0) {
        printf("Error: Cannot receive data from server.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("\n%s", buffer);
}

void logout(int sockfd) {
    // let's logout from IMAP server
    char logout_string[MAX_SIZE] = "LOGOUT\r\n";

    if (send(sockfd, logout_string, strlen(logout_string), 0) < 0) {
        printf("Error: Cannot send data to server.\n");
        exit(1);
    }

    // let's receive the response from IMAP server
    char buffer[MAX_SIZE];
    int n = recv(sockfd, buffer, MAX_SIZE, 0);

    if (n < 0) {
        printf("Error: Cannot receive data from server.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("\n%s", buffer);
}

void list(int sockfd) {
    // let's list all available folders in the mailbox
    char list_string[MAX_SIZE] = "LIST \"\" *\r\n";

    if (send(sockfd, list_string, strlen(list_string), 0) < 0) {
        printf("Error: Cannot send data to server.\n");
        exit(1);
    }

    // let's receive the response from IMAP server
    char buffer[MAX_SIZE];
    int n = recv(sockfd, buffer, MAX_SIZE, 0);

    if (n < 0) {
        printf("Error: Cannot receive data from server.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("\n%s", buffer);
}

void select_folder(int sockfd) {
    // let's select a specific folder
    char folder_name[MAX_SIZE];

    printf("\n\nPlease enter the name of the folder you want to select:\n");
    printf("Folder name: ");
    scanf("%s", folder_name);

    // send the select command to IMAP server
    char select_string[MAX_SIZE];
    sprintf(select_string, "SELECT %s\r\n", folder_name);

    if (send(sockfd, select_string, strlen(select_string), 0) < 0) {
        printf("Error: Cannot send data to server.\n");
        exit(1);
    }

    // let's receive the response from IMAP server
    char buffer[MAX_SIZE];
    int n = recv(sockfd, buffer, MAX_SIZE, 0);

    if (n < 0) {
        printf("Error: Cannot receive data from server.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("\n%s", buffer);
}

void search(int sockfd) {
    // let's search for an email in a selected folder
    char search_criteria[MAX_SIZE];

    printf("\n\nPlease enter the search criteria:\n");
    printf("Search criteria: ");
    getchar();
    fgets(search_criteria, MAX_SIZE, stdin); // use fgets to allow spaces in the search criteria
    search_criteria[strcspn(search_criteria, "\n")] = '\0';

    // send the search command to IMAP server
    char search_string[MAX_SIZE];
    sprintf(search_string, "SEARCH %s\r\n", search_criteria);

    if (send(sockfd, search_string, strlen(search_string), 0) < 0) {
        printf("Error: Cannot send data to server.\n");
        exit(1);
    }

    // let's receive the response from IMAP server
    char buffer[MAX_SIZE];
    int n = recv(sockfd, buffer, MAX_SIZE, 0);

    if (n < 0) {
        printf("Error: Cannot receive data from server.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("\n%s", buffer);
}

void fetch(int sockfd) {
    // let's fetch a specific email from a selected folder
    int email_id;

    printf("\n\nPlease enter the id of the email:\n");
    printf("Email id: ");
    scanf("%d", &email_id);

    // send the fetch command to IMAP server
    char fetch_string[MAX_SIZE];
    sprintf(fetch_string, "FETCH %d BODY[TEXT]\r\n", email_id);

    if (send(sockfd, fetch_string, strlen(fetch_string), 0) < 0) {
        printf("Error: Cannot send data to server.\n");
        exit(1);
    }

    // let's receive the response from IMAP server
    char buffer[MAX_SIZE];
    int n = recv(sockfd, buffer, MAX_SIZE, 0);

    if (n < 0) {
        printf("Error: Cannot receive data from server.\n");
        exit(1);
    }

    buffer[n] = '\0';
    printf("\n%s", buffer);
}