//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define SMTP_SERVER "smtp://smtp.example.com:587" // Change to your SMTP server
#define USERNAME "your_email@example.com" // Your email
#define PASSWORD "your_password" // Your email password

// Function to send an email asynchronously
void send_email(const char *to, const char *subject, const char *message) {
    CURL *curl;
    CURLcode res;
    struct curl_slist *recipients = NULL;

    curl = curl_easy_init();
    if (curl) {
        // Set the SMTP server
        curl_easy_setopt(curl, CURLOPT_URL, SMTP_SERVER);

        // Enable the use of SMTP AUTH
        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);

        // Set user credentials
        curl_easy_setopt(curl, CURLOPT_USERNAME, USERNAME);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, PASSWORD);

        // Set email from
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, USERNAME);

        // Set recipients
        recipients = curl_slist_append(recipients, to);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        // Set email subject and body in the payload
        const char *payload_text;
        asprintf(&payload_text,
            "To: %s\r\n"
            "From: %s\r\n"
            "Subject: %s\r\n"
            "\r\n"
            "%s\r\n", to, USERNAME, subject, message);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_READDATA, payload_text);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        // Perform the operation
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Email sent successfully!\n");
        }

        // Cleanup
        free((void *)payload_text);
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Could not initialize CURL\n");
    }
}

int main() {
    const char *to_email = "recipient@example.com"; // Change to the recipient's email
    const char *email_subject = "Hello from Async SMTP Client";
    const char *email_body = "This is a test email sent asynchronously from a C program.";

    printf("Sending email...\n");

    // Call the function to send email asynchronously
    send_email(to_email, email_subject, email_body);

    // Wait for a moment to allow the asynchronous operation to complete
    // In practice, replace this with a proper event loop or a threading model
    sleep(5); 

    return 0;
}