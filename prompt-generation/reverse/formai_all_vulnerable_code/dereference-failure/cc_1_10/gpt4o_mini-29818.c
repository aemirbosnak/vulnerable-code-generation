//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define SMTP_SERVER "smtp://smtp.example.com:587"
#define EMAIL_FROM "your-email@example.com"
#define EMAIL_PASSWORD "your-password"

typedef struct {
    const char *to;
    const char *subject;
    const char *body;
} email_t;

void init_curl() {
    curl_global_init(CURL_GLOBAL_ALL);
}

void cleanup_curl() {
    curl_global_cleanup();
}

CURLcode send_email(email_t *email) {
    CURL *curl;
    CURLcode res = CURLE_OK;
    
    struct curl_slist *recipients = NULL;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, SMTP_SERVER);
        curl_easy_setopt(curl, CURLOPT_USERNAME, EMAIL_FROM);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, EMAIL_PASSWORD);
        
        // Specify email details.
        char email_data[1024];
        snprintf(email_data, sizeof(email_data),
                 "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s",
                 EMAIL_FROM, email->to, email->subject, email->body);
                 
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, EMAIL_FROM);
        
        recipients = curl_slist_append(recipients, email->to);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        curl_easy_setopt(curl, CURLOPT_READDATA, &email_data);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        // Perform the request.
        res = curl_easy_perform(curl);
        
        // Cleanup.
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
    
    return res;
}

void *async_send_email(void *arg) {
    email_t *email = (email_t *) arg;
    CURLcode res = send_email(email);
    
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    } else {
        printf("Email sent to %s\n", email->to);
    }
    free(email);
    return NULL;
}

int main() {
    init_curl();

    // Sample email information
    email_t *email = malloc(sizeof(email_t));
    email->to = "recipient@example.com";
    email->subject = "Test Email";
    email->body = "Hello, this is a test email sent asynchronously!";
    
    // Create a thread to send email asynchronously
    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, async_send_email, (void *) email) != 0) {
        fprintf(stderr, "Failed to create thread\n");
        free(email);
    }
    
    // Wait for the email thread to finish
    pthread_join(thread_id, NULL);
    cleanup_curl();
    
    return 0;
}