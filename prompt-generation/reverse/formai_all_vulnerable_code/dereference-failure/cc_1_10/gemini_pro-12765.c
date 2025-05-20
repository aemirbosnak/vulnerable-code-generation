//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// The following callback function writes the received data to a file
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *stream) {
  // Get the file pointer from the stream
  FILE *fp = (FILE *)stream;
  // Write the data to the file
  size_t written = fwrite(ptr, size, nmemb, fp);
  return written;
}

int main(int argc, char *argv[]) {
  // Check for the correct number of arguments
  if (argc < 3) {
    printf("Usage: %s <URL> <output file>\n", argv[0]);
    return 1;
  }

  // Initialize the curl session
  CURL *curl = curl_easy_init();
  if (curl == NULL) {
    fprintf(stderr, "curl_easy_init() failed\n");
    return 1;
  }

  // Set the URL to fetch
  curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

  // Open the output file
  FILE *fp = fopen(argv[2], "wb");
  if (fp == NULL) {
    fprintf(stderr, "fopen() failed\n");
    return 1;
  }

  // Set the callback function to write the received data to the file
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

  // Perform the request
  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    return 1;
  }

  // Clean up
  curl_easy_cleanup(curl);
  fclose(fp);
  return 0;
}