//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <openssl/ssl.h>

// Custom error handling function
static void handle_error(char *err)
{
    // Print the error message
    fprintf(stderr, "%s\n", err);

    // Exit with error code
    exit(1);
}

// Custom write function for the response body
static size_t write_response(void *ptr, size_t size, size_t nmemb, void *stream)
{
    // Cast the stream to a FILE pointer
    FILE *fp = (FILE *)stream;

    // Write the data to the file
    size_t written = fwrite(ptr, size, nmemb, fp);
    if (written != size*nmemb) {
        handle_error("Error writing to file");
    }

    // Return the number of bytes written
    return written;
}

// SSL certificate verification callback
static int verify_cert(int preverify_ok, X509_STORE_CTX *ctx)
{
    // Allow self-signed certificates
    return 1;
}

// Main function
int main(int argc, char *argv[])
{
    // Check for required arguments
    if (argc < 3) {
        handle_error("Usage: http_client <url> <output_file>");
    }

    // Initialize the SSL library
    SSL_library_init();

    // Create a new curl handle
    CURL *curl = curl_easy_init();
    if (!curl) {
        handle_error("Error initializing curl");
    }

    // Set the URL to fetch
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

    // Set the write function for the response body
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response);

    // Set the output file for the response body
    FILE *fp = fopen(argv[2], "wb");
    if (!fp) {
        handle_error("Error opening file");
    }
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

    // Set SSL certificate verification callback
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
    curl_easy_setopt(curl, CURLOPT_SSL_CTX_FUNCTION, verify_cert);

    // Perform the HTTP request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        handle_error(curl_easy_strerror(res));
    }

    // Cleanup
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    fclose(fp);

    return 0;
}