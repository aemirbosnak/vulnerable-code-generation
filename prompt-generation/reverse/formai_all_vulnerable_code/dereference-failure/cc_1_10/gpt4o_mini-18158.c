//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <event2/event.h>

#define MAX_EMAIL_LEN 256
#define MAX_MESSAGE_LEN 1024

typedef struct {
    CURL *curl;
    struct curl_slist *recipients;
    const char *from;
    const char *to;
    const char *subject;
    const char *message;
} EmailData;

void send_email(EmailData *emailData) {
    curl_easy_setopt(emailData->curl, CURLOPT_URL, "smtp://smtp.example.com:587");
    curl_easy_setopt(emailData->curl, CURLOPT_USERNAME, "your_username");
    curl_easy_setopt(emailData->curl, CURLOPT_PASSWORD, "your_password");

    curl_easy_setopt(emailData->curl, CURLOPT_MAIL_FROM, emailData->from);
    emailData->recipients = curl_slist_append(emailData->recipients, emailData->to);
    curl_easy_setopt(emailData->curl, CURLOPT_MAIL_RCPT, emailData->recipients);

    // Create message
    char messageBuffer[MAX_MESSAGE_LEN];
    snprintf(messageBuffer, sizeof(messageBuffer),
             "To: %s\r\n"
             "From: %s\r\n"
             "Subject: %s\r\n"
             "\r\n"
             "%s\r\n",
             emailData->to, emailData->from, emailData->subject, emailData->message);

    curl_easy_setopt(emailData->curl, CURLOPT_READDATA, messageBuffer);
    curl_easy_setopt(emailData->curl, CURLOPT_UPLOAD, 1L);

    CURLcode res = curl_easy_perform(emailData->curl);

    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    } else {
        printf("Email sent successfully!\n");
    }

    curl_slist_free_all(emailData->recipients);
}

void on_event(evutil_socket_t fd, short events, void *arg) {
    EmailData *emailData = (EmailData *)arg;
    send_email(emailData);
    
    curl_easy_cleanup(emailData->curl);
    free(emailData);
    event_base_loopbreak((struct event_base *)arg);
}

int main() {
    struct event_base *base = event_base_new();
    if (!base) {
        fprintf(stderr, "Could not initialize event base\n");
        return 1;
    }

    EmailData *emailData = (EmailData *)malloc(sizeof(EmailData));
    emailData->curl = curl_easy_init();
    if (!emailData->curl) {
        fprintf(stderr, "Could not initialize curl\n");
        free(emailData);
        return 1;
    }

    emailData->from = "from@example.com";
    emailData->to = "to@example.com";
    emailData->subject = "Test Email";
    emailData->message = "Hello! This is a test email sent asynchronously.";

    // Set up the event to send email at a later time
    struct evbuffer *buffer = evbuffer_new();
    evbuffer_add_printf(buffer, "Sending email from %s to %s...\n", emailData->from, emailData->to);
    
    // Execute the send_email function as an event
    struct event *ev = event_new(base, -1, EV_TIMEOUT | EV_PERSIST, on_event, emailData);
    struct timeval tv = {1, 0}; // 1 second timeout
    event_add(ev, &tv);

    printf("Event loop starting...\n");
    event_base_dispatch(base);

    // Cleanup
    event_free(ev);
    event_base_free(base);
    curl_global_cleanup();

    return 0;
}