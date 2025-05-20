//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Callback function to handle the data received from the server
size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
  // Cast the userdata pointer to a FILE*
  FILE *fp = (FILE *)userdata;

  // Write the data to the file
  fwrite(ptr, size, nmemb, fp);

  // Return the number of bytes written
  return size * nmemb;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a URL
  if (argc < 2) {
    printf("Usage: %s <URL>\n", argv[0]);
    return 1;
  }

  // Initialize the CURL library
  curl_global_init(CURL_GLOBAL_DEFAULT);

  // Create a new CURL handle
  CURL *curl = curl_easy_init();

  // Set the URL to fetch
  curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

  // Set the write callback function
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

  // Open a file to save the data
  FILE *fp = fopen("output.html", "w");

  // Set the userdata pointer to the file
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

  // Perform the request
  CURLcode res = curl_easy_perform(curl);

  // Check for errors
  if (res != CURLE_OK) {
    printf("Error: %s\n", curl_easy_strerror(res));
    return 1;
  }

  // Close the file
  fclose(fp);

  // Cleanup the CURL handle
  curl_easy_cleanup(curl);

  // Cleanup the CURL library
  curl_global_cleanup();

  return 0;
}