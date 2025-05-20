//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

void thank_you_message() {
    printf("Thank you for using this simple email client in C!\n");
    printf("Your coded creativity brings forth collaboration and communication!\n");
}

void send_email(const char* from, const char* to, const char* subject, const char* body, const char* smtp_server, const char* username, const char* password) {
    CURL *curl;
    CURLcode res;
    
    struct curl_slist *recipients = NULL;
    
    curl = curl_easy_init();
    if(curl) {
        // Set the SMTP server
        curl_easy_setopt(curl, CURLOPT_URL, smtp_server);
        
        // Enable username and password authentication
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);

        // Set email data
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from);
        recipients = curl_slist_append(recipients, to);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        // Set the email subject and body
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        
        // Create a temporary file for the email content
        FILE *emailfile = fopen("email.txt", "w");
        if(emailfile == NULL) {
            perror("Unable to open email file");
            return;
        }
        fprintf(emailfile, "To: %s\n", to);
        fprintf(emailfile, "From: %s\n", from);
        fprintf(emailfile, "Subject: %s\n\n", subject);
        fprintf(emailfile, "%s\n", body);
        fclose(emailfile);

        // Specify the file containing the email data
        curl_easy_setopt(curl, CURLOPT_READDATA, fopen("email.txt", "r"));
        curl_easy_setopt(curl, CURLOPT_INFILESIZE, -1L);
        
        // Perform the mail sending operation
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Clean up
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
        
        // Cleanup temporary email file
        remove("email.txt");
    }
}

int main() {
    thank_you_message();

    // Input email data
    const char *from = "your_email@example.com";  // Replace with your email
    const char *to = "recipient_email@example.com";  // Replace with recipient's email

    // Subject and Body
    const char *subject = "Greetings from C Email Client!";
    const char *body = "Hello,\n\nThis is a test email sent from a simple email client written in C.\n\nThank you!\n";

    // SMTP server details
    const char *smtp_server = "smtp://smtp.example.com:587";  // Replace with your SMTP server
    const char *username = "your_email@example.com";  // Replace with your email username
    const char *password = "your_password";  // Replace with your email password

    // Send the email
    send_email(from, to, subject, body, smtp_server, username, password);

    printf("Email sent successfully! Thank you for utilizing this email client!\n");
    return 0;
}