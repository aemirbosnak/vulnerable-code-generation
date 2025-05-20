//GPT-4o-mini DATASET v1.0 Category: QR code generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <openssl/md5.h>

// Function to calculate the MD5 hash of a string
void calculate_md5(const char *str, unsigned char output[MD5_DIGEST_LENGTH]) {
    MD5((unsigned char *) str, strlen(str), output);
}

// Function to convert MD5 hash to hexadecimal string
void md5_to_hex(unsigned char *md, char *output) {
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(&output[i * 2], "%02x", (unsigned int)md[i]);
    }
}

// Function to generate a QR code using the Go QR Code API
void generate_qr_code(const char *data) {
    CURL *curl;
    CURLcode res;

    // URL-encode the data
    char *encoded_data = curl_easy_escape(curl, data, strlen(data));
    char url[256] = "https://api.qrserver.com/v1/create-qr-code/?data=";
    strcat(url, encoded_data);
    strcat(url, "&size=200x200");

    // Initialize curl
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        
        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }
    curl_free(encoded_data);
}

// Main function
int main() {
    char data[256];
    unsigned char md[MD5_DIGEST_LENGTH];
    char md_string[MD5_DIGEST_LENGTH * 2 + 1];
    
    printf("Enter the data you want to encode into a QR Code: ");
    fgets(data, sizeof(data), stdin);
    
    // Remove newline character at the end
    data[strcspn(data, "\n")] = 0;

    // Calculate the MD5 hash of the data
    calculate_md5(data, md);
    md5_to_hex(md, md_string);
    
    printf("MD5 Hash of the input data: %s\n", md_string);
    
    // Generate QR code
    printf("Generating QR code...\n");
    generate_qr_code(data);
    
    return 0;
}