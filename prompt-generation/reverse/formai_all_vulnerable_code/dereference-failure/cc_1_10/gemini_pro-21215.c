//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Callback function to handle server responses
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
  // Cast userdata to a FILE* pointer
  FILE *stream = (FILE*)userdata;

  // Write the response to the file
  fwrite(ptr, size, nmemb, stream);

  // Return the number of bytes written
  return size * nmemb;
}

int main(int argc, char *argv[]) {
  // Check if a URL was provided
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Initialize the CURL library
  CURL *curl = curl_easy_init();

  // Set the URL to fetch
  curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

  // Set the write callback to save the response to a file
  FILE *file = fopen("response.html", "w");
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

  // Perform the HTTP request
  CURLcode res = curl_easy_perform(curl);

  // Check for errors
  if (res != CURLE_OK) {
    fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
    return EXIT_FAILURE;
  }

  // Clean up the CURL library
  curl_easy_cleanup(curl);

  // Close the response file
  fclose(file);

  // Success!
  return EXIT_SUCCESS;
}