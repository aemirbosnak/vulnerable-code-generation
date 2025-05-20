//FormAI DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_EMAILS 100

struct Email {
    char *sender;
    char *recipient;
    char *subject;
    char *body;
};

struct Inbox {
    int num_emails;
    struct Email emails[MAX_EMAILS];
};

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t realsize = size * nmemb;
    char *str = malloc(realsize + 1);
    if (str == NULL) {
        return 0;
    }
    memcpy(str, ptr, realsize);
    str[realsize] = '\0';
    *(char **) userdata = str;
    return realsize;
}

void print_email(struct Email email) {
    printf("From: %s\n", email.sender);
    printf("To: %s\n", email.recipient);
    printf("Subject: %s\n", email.subject);
    printf("%s\n", email.body);
}

void print_inbox(struct Inbox inbox) {
    printf("You have %d emails.\n", inbox.num_emails);
    for (int i = 0; i < inbox.num_emails; i++) {
        print_email(inbox.emails[i]);
        printf("\n");
    }
}

struct Inbox get_inbox(char *username, char *password) {
    struct Inbox inbox;
    inbox.num_emails = 0;
    CURL *curl = curl_easy_init();
    if (curl) {
        char *url = malloc(strlen(username) + 50);
        sprintf(url, "imap://%s:993/INBOX", username);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
        long conn_timeout = 10;
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, conn_timeout);
        char *payload = NULL;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &payload);
        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            char *start = payload;
            char *end = start;
            while ((start = strstr(start, "From: ")) != NULL) {
                struct Email email;
                end = strstr(start, "\n");
                int sender_len = end - start - 6;
                email.sender = malloc(sender_len + 1);
                strncpy(email.sender, start + 6, sender_len);
                email.sender[sender_len] = '\0';
                start = strstr(end, "Subject: ");
                end = strstr(start, "\n");
                if (end == NULL) {
                    end = strstr(start, "\r");
                }
                int subject_len = end - start - 9;
                email.subject = malloc(subject_len + 1);
                strncpy(email.subject, start + 9, subject_len);
                email.subject[subject_len] = '\0';
                start = strstr(end, "\n\n");
                end = strstr(start, ".\n");
                if (end == NULL) {
                    end = strstr(start, "\r\n.");
                }
                int body_len = end - start - 2;
                email.body = malloc(body_len + 1);
                strncpy(email.body, start + 2, body_len);
                email.body[body_len] = '\0';
                inbox.emails[inbox.num_emails++] = email;
            }
        }
        free(url);
        free(payload);
        curl_easy_cleanup(curl);
    }
    return inbox;
}

void send_email(char *username, char *password, char *recipient, char *subject, char *body) {
    CURL *curl = curl_easy_init();
    if (curl) {
        char *payload = malloc(strlen("To: \r\nSubject: \r\n\r\n"));
        sprintf(payload, "To: %s\r\nSubject: %s\r\n\r\n%s", recipient, subject, body);
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, username);
        struct curl_slist *recipients = NULL;
        recipients = curl_slist_append(recipients, recipient);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            printf("Error sending email: %s\n", curl_easy_strerror(res));
        } else {
            printf("Email sent successfully!\n");
        }
        curl_slist_free_all(recipients);
        free(payload);
        curl_easy_cleanup(curl);
    }
}

int main() {
    char username[100];
    char password[100];
    printf("Enter your email address: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    struct Inbox inbox = get_inbox(username, password);
    print_inbox(inbox);
    char recipient[100];
    char subject[100];
    char body[1000];
    printf("Enter the recipient's email address: ");
    scanf("%s", recipient);
    printf("Enter the subject of the email: ");
    scanf("%s", subject);
    printf("Enter the body of the email: ");
    scanf("%s", body);
    send_email(username, password, recipient, subject, body);
    return 0;
}