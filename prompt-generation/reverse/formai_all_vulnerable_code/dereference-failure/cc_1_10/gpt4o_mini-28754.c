//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BUFFER_SIZE 1024

// Function to display error message and exit
void handle_error(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

// Callback function for writing data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

// Function to list files on the FTP server
void list_files(CURL *curl, const char *ftp_url, const char *username, const char *password) {
    CURLcode res;

    curl_easy_setopt(curl, CURLOPT_URL, ftp_url);
    curl_easy_setopt(curl, CURLOPT_USERPWD, username);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We only want the headers

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        handle_error(curl_easy_strerror(res));
    }
}

// Function to download a file from the FTP server
void download_file(CURL *curl, const char *ftp_url, const char *filename, const char *username, const char *password) {
    CURLcode res;
    FILE *file;

    file = fopen(filename, "wb");
    if (!file) {
        handle_error("Failed to open file for writing");
    }

    curl_easy_setopt(curl, CURLOPT_URL, ftp_url);
    curl_easy_setopt(curl, CURLOPT_USERPWD, username);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        handle_error(curl_easy_strerror(res));
    }

    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <ftp_url> <username> <password> <action>\n", argv[0]);
        fprintf(stderr, "Action can be 'list' or 'download <filename>'\n");
        exit(EXIT_FAILURE);
    }

    const char *ftp_url = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];
    const char *action = argv[4];

    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (!curl) {
        handle_error("Failed to initialize CURL");
    }

    if (strcmp(action, "list") == 0) {
        list_files(curl, ftp_url, username, password);
    } else if (strncmp(action, "download", 8) == 0) {
        const char *filename = action + 9; // Get filename from action string
        download_file(curl, ftp_url, filename, username, password);
    } else {
        fprintf(stderr, "Invalid action\n");
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        exit(EXIT_FAILURE);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    
    return 0;
}