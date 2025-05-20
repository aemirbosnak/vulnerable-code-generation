//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define SMTP_SERVER "smtp://smtp.example.com:587" // Change this to your SMTP server
#define USERNAME "your_email@example.com"          // Your email address
#define PASSWORD "your_password"                    // Your email password

void send_email(const char *to, const char *subject, const char *body) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT); // Initialize CURL
    curl = curl_easy_init();                // Set up the CURL session

    if(curl) {
        struct curl_slist *recipients = NULL; // Recipient list

        // Set the SMTP URL
        curl_easy_setopt(curl, CURLOPT_URL, SMTP_SERVER);
        // Enable authentication
        curl_easy_setopt(curl, CURLOPT_USERNAME, USERNAME);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, PASSWORD);
        // Specify the sender email address
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, USERNAME);

        // Add the recipient email address
        recipients = curl_slist_append(recipients, to);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        
        // Create the email body
        char *email_data;
        asprintf(&email_data, "To: %s\r\nFrom: %s\r\nSubject: %s\r\n\r\n%s", to, USERNAME, subject, body);

        // Set the email data
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_READDATA, email_data);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        
        // Perform the email sending
        res = curl_easy_perform(curl);
        
        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Clean up
        free(email_data);
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup(); // Clean up globally
}

int main() {
    char to[100];
    char subject[100];
    char body[500];

    printf("Enter the recipient email address: ");
    fgets(to, sizeof(to), stdin);
    to[strcspn(to, "\n")] = 0; // Remove the newline character

    printf("Enter the subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0; // Remove the newline character

    printf("Enter the email body: ");
    fgets(body, sizeof(body), stdin);
    body[strcspn(body, "\n")] = 0; // Remove the newline character

    send_email(to, subject, body); // Send the email

    printf("Email sent successfully!\n");

    return 0;
}