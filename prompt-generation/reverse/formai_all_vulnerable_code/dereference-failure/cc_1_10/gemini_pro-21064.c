//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: future-proof
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Callback function to handle incoming data
size_t write_callback(void *buffer, size_t size, size_t nmemb, void *userp) {
  // Cast the user pointer back to the output string
  char **output = (char **)userp;

  // Calculate the total size of the data received
  size_t total_size = size * nmemb;

  // Append the received data to the output string
  *output = realloc(*output, strlen(*output) + total_size + 1);
  memcpy(*output + strlen(*output), buffer, total_size);

  // Add a null terminator to the end of the string
  *(*output + strlen(*output)) = '\0';

  return total_size;
}

int main(int argc, char **argv) {
  // Check if the URL was provided as an argument
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Initialize the cURL library
  CURL *curl = curl_easy_init();

  // Set the URL to fetch
  curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

  // Set the callback function to handle incoming data
  char *output = malloc(1);
  *output = '\0';
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);

  // Perform the HTTP request
  CURLcode res = curl_easy_perform(curl);

  // Check if the request was successful
  if (res != CURLE_OK) {
    fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
    free(output);
    curl_easy_cleanup(curl);
    return EXIT_FAILURE;
  }

  // Print the response
  printf("%s", output);

  // Free the allocated memory
  free(output);

  // Cleanup the cURL library
  curl_easy_cleanup(curl);

  return EXIT_SUCCESS;
}