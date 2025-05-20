//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_EMAIL_LENGTH 256
#define MAX_SUBJECT_LENGTH 128
#define MAX_BODY_LENGTH 1024

struct Email {
    char recipient[MAX_EMAIL_LENGTH];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
};

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *content, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if (ptr == NULL) {
        printf("Not enough memory to expand buffer!\n");
        return 0; // out of memory
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), content, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0; // null-terminate

    return realsize;
}

void init_memory_struct(struct MemoryStruct *mem) {
    mem->memory = malloc(1); // initial allocation
    mem->memory[0] = '\0';    // empty string
    mem->size = 0;
}

void free_memory_struct(struct MemoryStruct *mem) {
    free(mem->memory);
}

void send_email(struct Email *email) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;

    init_memory_struct(&chunk);

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.your-email-provider.com:587");
        
        // Set email sender and recipient
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "<your-email@example.com>");
        struct curl_slist *recipients = NULL;
        recipients = curl_slist_append(recipients, email->recipient);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        // Compose the email
        char email_data[MAX_BODY_LENGTH + MAX_SUBJECT_LENGTH + MAX_EMAIL_LENGTH];
        snprintf(email_data, sizeof(email_data), "To: %s\r\nSubject: %s\r\n\r\n%s", email->recipient, email->subject, email->body);
        curl_easy_setopt(curl, CURLOPT_READDATA, email_data);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        
        // Perform the send
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    free_memory_struct(&chunk);
}

void input_email(struct Email *email) {
    printf("Enter recipient email: ");
    fgets(email->recipient, sizeof(email->recipient), stdin);
    email->recipient[strcspn(email->recipient, "\n")] = 0; // Remove the newline character

    printf("Enter email subject: ");
    fgets(email->subject, sizeof(email->subject), stdin);
    email->subject[strcspn(email->subject, "\n")] = 0; // Remove the newline character

    printf("Enter email body (max 1024 characters):\n");
    fgets(email->body, sizeof(email->body), stdin);
    email->body[strcspn(email->body, "\n")] = 0; // Remove the newline character
}

int main(void) {
    struct Email email;

    input_email(&email);

    printf("Sending email...\n");
    send_email(&email);

    printf("Email sent successfully!\n");
    return EXIT_SUCCESS;
}