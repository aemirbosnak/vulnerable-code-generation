//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
  char *data;
  size_t size;
} response_buffer;

size_t write_response(char *ptr, size_t size, size_t nmemb, void *stream) {
  response_buffer *buffer = (response_buffer *)stream;
  size_t bytes = size * nmemb;

  buffer->data = realloc(buffer->data, buffer->size + bytes + 1);
  if (!buffer->data) {
    return 0;
  }

  memcpy(buffer->data + buffer->size, ptr, bytes);
  buffer->size += bytes;
  buffer->data[buffer->size] = '\0';

  return bytes;
}

int main(int argc, char **argv) {
  if (argc != 5) {
    printf("Usage: %s <imap server> <username> <password> <mailbox>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *imap_server = argv[1];
  char *username = argv[2];
  char *password = argv[3];
  char *mailbox = argv[4];

  CURL *curl = curl_easy_init();
  if (!curl) {
    printf("Failed to initialize CURL\n");
    return EXIT_FAILURE;
  }

  response_buffer response = {NULL, 0};

  const char *url = malloc(strlen(imap_server) + strlen(mailbox) + 50);
  sprintf(url, "imaps://%s/INBOX", imap_server);

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
  curl_easy_setopt(curl, CURLOPT_USERNAME, username);
  curl_easy_setopt(curl, CURLOPT_PASSWORD, password);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_response);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    printf("Failed to perform IMAP operation: %s\n", curl_easy_strerror(res));
    free(response.data);
    curl_easy_cleanup(curl);
    return EXIT_FAILURE;
  }

  printf("%s", response.data);

  free(response.data);
  curl_easy_cleanup(curl);
  free(url);

  return EXIT_SUCCESS;
}