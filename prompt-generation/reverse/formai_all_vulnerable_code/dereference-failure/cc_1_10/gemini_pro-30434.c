//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// The almighty functions:

// Write the response to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  size_t written = fwrite(ptr, size, nmemb, stream);
  return written;
}

// Read the file into a buffer
size_t read_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  size_t read = fread(ptr, size, nmemb, stream);
  return read;
}

int main(void) {
  CURL *curl;
  CURLcode res;

  // Prepare the almighty handler:
  curl = curl_easy_init();
  if (curl) {
    // Set the URL for the celestial request:
    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");

    // Prepare the data we're sending:
    const char *data = "This is my magnificent post!";
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

    // Add the callback functions:
    FILE *file = fopen("response.txt", "wb");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    // Execute the celestial request:
    res = curl_easy_perform(curl);

    // Check for any cosmic errors:
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
      return EXIT_FAILURE;
    }

    // Close the connection to the celestial realm:
    curl_easy_cleanup(curl);

    // Close the file:
    fclose(file);
  }

  return EXIT_SUCCESS;
}