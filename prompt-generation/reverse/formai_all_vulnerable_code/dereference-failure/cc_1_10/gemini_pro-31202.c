//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Where we store the love letters
typedef struct {
  char *letter;
  size_t size;
} LoveLetter;

// Our trusty messenger
CURL *Romeo;

// Sanitize the URL
char *sanitizeURL(char *url) {
  char *sanitized = malloc(strlen(url) + 1);
  int i, j = 0;
  for (i = 0; url[i]; i++) {
    switch (url[i]) {
      case '%':
        if (url[i + 1] && url[i + 2]) {
          char hex[3] = {url[i + 1], url[i + 2], '\0'};
          long int ch;
          sscanf(hex, "%lx", &ch);
          sanitized[j] = (char)ch;
          i += 2;
        }
        break;
      default:
        sanitized[j] = url[i];
        break;
    }
    j++;
  }
  sanitized[j] = '\0';
  return sanitized;
}

// Deliver the love letter
size_t deliverLove(void *ptr, size_t size, size_t nmemb, void *stream) {
  LoveLetter *letter = (LoveLetter *)stream;
  size_t written = fwrite(ptr, size, nmemb, letter->letter);
  letter->size += written;
  return written;
}

// Romeo, Romeo, wherefore art thou Romeo?
int main(void) {
  // Initialize the messenger
  Romeo = curl_easy_init();

  // Tis but thy form that is my enemy
  char *url = malloc(100);
  printf("Enter the URL of thy beloved: ");
  scanf("%s", url);

  // Remove the mask of URL-encoding
  char *sanitized = sanitizeURL(url);

  // Set the destination of the love letter
  LoveLetter love;
  love.letter = malloc(1);
  love.size = 0;
  curl_easy_setopt(Romeo, CURLOPT_WRITEDATA, &love);
  curl_easy_setopt(Romeo, CURLOPT_WRITEFUNCTION, deliverLove);

  // Send the love letter
  curl_easy_setopt(Romeo, CURLOPT_URL, sanitized);
  curl_easy_perform(Romeo);

  // Release the messenger
  curl_easy_cleanup(Romeo);

  // Display the love letter
  printf("My love's sweet words:\n%s\n", love.letter);

  // Free the love letter
  free(love.letter);
  free(sanitized);
  free(url);

  return 0;
}