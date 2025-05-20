//FormAI DATASET v1.0 Category: Email Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <curl/curl.h>

#define BUF_SIZE 1024

// Function to send email using SMTP protocol
int send_email(char *server, int port, char *username, char *password, char *from, char *to, char *subject, char *body) {
    // Connect to SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent *host = gethostbyname(server);
    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    memcpy(&saddr.sin_addr.s_addr, host->h_addr, host->h_length);
    connect(sockfd, (struct sockaddr *)&saddr, sizeof(saddr));
    
    // Receive greeting message from server
    char buf[BUF_SIZE];
    recv(sockfd, buf, BUF_SIZE, 0);
    printf("%s", buf);
    
    // Send HELO command
    char helo_cmd[BUF_SIZE];
    sprintf(helo_cmd, "HELO %s\r\n", server);
    send(sockfd, helo_cmd, strlen(helo_cmd), 0);
    recv(sockfd, buf, BUF_SIZE, 0);
    printf("%s", buf);

    // Send AUTH LOGIN command
    char auth_cmd[BUF_SIZE];
    sprintf(auth_cmd, "AUTH LOGIN\r\n");
    send(sockfd, auth_cmd, strlen(auth_cmd), 0);
    recv(sockfd, buf, BUF_SIZE, 0);
    printf("%s", buf);

    // Send username and password (base64 encoded) for authentication
    char b64_username[BUF_SIZE];
    char b64_password[BUF_SIZE];
    int len_username = strlen(username);
    int len_password = strlen(password);
    int len_b64_username = EVP_EncodeBlock((unsigned char *)b64_username, (const unsigned char *)username, len_username);
    int len_b64_password = EVP_EncodeBlock((unsigned char *)b64_password, (const unsigned char *)password, len_password);
    char username_cmd[BUF_SIZE];
    char password_cmd[BUF_SIZE];
    sprintf(username_cmd, "%s\r\n", b64_username);
    sprintf(password_cmd, "%s\r\n", b64_password);
    send(sockfd, username_cmd, len_b64_username + 2, 0);
    recv(sockfd, buf, BUF_SIZE, 0);
    printf("%s", buf);
    send(sockfd, password_cmd, len_b64_password + 2, 0);
    recv(sockfd, buf, BUF_SIZE, 0);
    printf("%s", buf);

    // Send MAIL FROM command
    char mail_from_cmd[BUF_SIZE];
    sprintf(mail_from_cmd, "MAIL FROM:<%s>\r\n", from);
    send(sockfd, mail_from_cmd, strlen(mail_from_cmd), 0);
    recv(sockfd, buf, BUF_SIZE, 0);
    printf("%s", buf);

    // Send RCPT TO command
    char rcpt_to_cmd[BUF_SIZE];
    sprintf(rcpt_to_cmd, "RCPT TO:<%s>\r\n", to);
    send(sockfd, rcpt_to_cmd, strlen(rcpt_to_cmd), 0);
    recv(sockfd, buf, BUF_SIZE, 0);
    printf("%s", buf);

    // Send DATA command
    char data_cmd[BUF_SIZE];
    sprintf(data_cmd, "DATA\r\n");
    send(sockfd, data_cmd, strlen(data_cmd), 0);
    recv(sockfd, buf, BUF_SIZE, 0);
    printf("%s", buf);

    // Send email body
    char email_body[BUF_SIZE];
    sprintf(email_body, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n%s\r\n.\r\n", from, to, subject, body);
    send(sockfd, email_body, strlen(email_body), 0);
    recv(sockfd, buf, BUF_SIZE, 0);
    printf("%s", buf);

    // Send QUIT command
    char quit_cmd[BUF_SIZE];
    sprintf(quit_cmd, "QUIT\r\n");
    send(sockfd, quit_cmd, strlen(quit_cmd), 0);
    recv(sockfd, buf, BUF_SIZE, 0);
    printf("%s", buf);

    // Close socket
    close(sockfd);

    return 0;
}

// Function to receive email using IMAP protocol
struct MemoryStruct {
  char *memory;
  size_t size;
};
 
static size_t write_memory_callback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
 
  mem->memory = realloc(mem->memory, mem->size + realsize + 1);
  if (mem->memory == NULL) {
    printf("Not enough memory!\n");
    return 0;
  }
 
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
 
  return realsize;
}
 
int receive_email(char *server, int port, char *username, char *password) {
  CURL *curl;
  CURLcode res;
  char url[BUF_SIZE];
  sprintf(url, "imaps://%s:%s@mail.%s/INBOX", username, password, server); // IMAP URL
  char userpass[BUF_SIZE];
  sprintf(userpass, "%s:%s", username, password); // Base64-encoded username:password for authentication
  char auth[BUF_SIZE];
  sprintf(auth, "Authorization: Basic %s", userpass); // Authentication header
  struct MemoryStruct chunk;
  chunk.memory = malloc(1);
  chunk.size = 0;
 
  // Perform IMAP request to fetch email
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_memory_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36");
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, auth);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
 
    res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
 
    curl_easy_cleanup(curl);
  }
  free(chunk.memory);
  return 0;
}

int main() {
    printf("Welcome to C Email Client!\n");
    printf("Please enter the SMTP server address: ");
    char server[BUF_SIZE];
    scanf("%s", server);
    printf("Please enter the SMTP server port: ");
    int port;
    scanf("%d", &port);
    printf("Please enter your email address: ");
    char username[BUF_SIZE];
    scanf("%s", username);
    printf("Please enter your email password: ");
    char password[BUF_SIZE];
    scanf("%s", password);
    printf("Please enter the recipient email address: ");
    char to[BUF_SIZE];
    scanf("%s", to);
    printf("Please enter the email subject: ");
    char subject[BUF_SIZE];
    scanf("%s", subject);
    printf("Please enter the email body: ");
    char body[BUF_SIZE];
    scanf(" %[^\n]", body);
    printf("Sending email...\n");
    send_email(server, port, username, password, username, to, subject, body);
    printf("Email sent!\n");
    printf("Do you want to receive email? (y/n) ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y') {
        printf("Receiving email...\n");
        receive_email(server, 993, username, password);
        printf("Email received!\n");
    }
    return 0;
}