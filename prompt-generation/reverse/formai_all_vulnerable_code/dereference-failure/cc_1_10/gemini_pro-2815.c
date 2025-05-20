//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Our happy URL sanitizer!
char *sanitize_url(char *url) {
  // Check for any naughty characters
  int naughty_found = 0;
  char *naughty_chars = "<>\"";
  for (int i = 0; i < strlen(url); i++) {
    for (int j = 0; j < strlen(naughty_chars); j++) {
      if (url[i] == naughty_chars[j]) {
        naughty_found = 1;
        break;
      }
    }
  }

  // If we found any naughty characters, replace them with happy ones!
  if (naughty_found) {
    char *happy_chars = "*-+";
    for (int i = 0; i < strlen(url); i++) {
      for (int j = 0; j < strlen(naughty_chars); j++) {
        if (url[i] == naughty_chars[j]) {
          url[i] = happy_chars[j];
        }
      }
    }
  }

  // Return our happy, sanitized URL!
  return url;
}

int main() {
  // Initialize our happy CURL session!
  CURL *curl = curl_easy_init();
  if (!curl) {
    printf("Oops, something went wrong while initializing CURL! :((");
    return 1;
  }

  // Set our happy URL to sanitize!
  char *url = "https://example.com/?naughty=<script>alert('Hello!')</script>";
  printf("Before sanitization: %s\n", url);

  // Sanitize the URL with our magical function!
  char *sanitized_url = sanitize_url(url);

  // Set the sanitized URL for our CURL session!
  curl_easy_setopt(curl, CURLOPT_URL, sanitized_url);

  // Perform the happy request!
  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    printf("Oops, something went wrong while performing the request! :((");
    curl_easy_cleanup(curl);
    return 1;
  }

  // Cleanup our happy CURL session!
  curl_easy_cleanup(curl);

  // Print our happy result!
  printf("After sanitization: %s\n", sanitized_url);
  printf("Request performed successfully! Hooray! :D");

  return 0;
}