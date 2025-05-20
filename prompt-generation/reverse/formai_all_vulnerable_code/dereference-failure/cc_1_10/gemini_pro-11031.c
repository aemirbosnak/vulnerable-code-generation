//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

// Mailgun API credentials.
#define MAILGUN_DOMAIN "YOUR_MAILGUN_DOMAIN"
#define MAILGUN_API_KEY "YOUR_MAILGUN_API_KEY"

// The email message.
typedef struct {
    char *from;
    char *to;
    char *subject;
    char *text;
} Email;

// Free the memory allocated for the email message.
void free_email(Email *email) {
    free(email->from);
    free(email->to);
    free(email->subject);
    free(email->text);
    free(email);
}

// Send the email message using the Mailgun API.
int send_email(Email *email) {
    CURL *curl;
    CURLcode res;
    struct curl_httppost *formpost = NULL;
    struct curl_httppost *lastptr = NULL;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.mailgun.net/v3/" MAILGUN_DOMAIN "/messages");
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
        curl_easy_setopt(curl, CURLOPT_USERPWD, MAILGUN_API_KEY ":api");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, email->text);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "Error sending email: %s\n", curl_easy_strerror(res));
            return 1;
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}

// Prompt the user for the email message details.
int get_email_details(Email *email) {
    char buffer[256];

    printf("From: ");
    fgets(buffer, sizeof(buffer), stdin);
    email->from = strdup(buffer);
    if (email->from == NULL) {
        fprintf(stderr, "Error allocating memory for email sender.\n");
        return 1;
    }
    strtok(email->from, "\n");

    printf("To: ");
    fgets(buffer, sizeof(buffer), stdin);
    email->to = strdup(buffer);
    if (email->to == NULL) {
        fprintf(stderr, "Error allocating memory for email recipient.\n");
        return 1;
    }
    strtok(email->to, "\n");

    printf("Subject: ");
    fgets(buffer, sizeof(buffer), stdin);
    email->subject = strdup(buffer);
    if (email->subject == NULL) {
        fprintf(stderr, "Error allocating memory for email subject.\n");
        return 1;
    }
    strtok(email->subject, "\n");

    printf("Message: ");
    fgets(buffer, sizeof(buffer), stdin);
    email->text = strdup(buffer);
    if (email->text == NULL) {
        fprintf(stderr, "Error allocating memory for email message.\n");
        return 1;
    }
    strtok(email->text, "\n");

    return 0;
}

int main() {
    Email email;
    int status;

    memset(&email, 0, sizeof(Email));

    status = get_email_details(&email);
    if (status != 0) {
        fprintf(stderr, "Error getting email details.\n");
        return 1;
    }

    status = send_email(&email);
    if (status != 0) {
        fprintf(stderr, "Error sending email.\n");
        return 1;
    }

    printf("Email sent successfully.\n");
    free_email(&email);

    return 0;
}