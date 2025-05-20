//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 1024

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

int main(int argc, char *argv[])
{
  CURL *curl;
  CURLcode res;
  char *url;
  FILE *fp;
  long code;

  if (argc < 3)
  {
    fprintf(stderr, "Usage: %s <url> <output file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  url = argv[1];
  fp = fopen(argv[2], "wb");
  if (!fp)
  {
    perror("fopen");
    return EXIT_FAILURE;
  }

  curl = curl_easy_init();
  if (!curl)
  {
    fprintf(stderr, "curl_easy_init failed\n");
    return EXIT_FAILURE;
  }

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 10L);
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
  curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.149 Safari/537.36");
  curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "gzip, deflate");
  curl_easy_setopt(curl, CURLOPT_ENCODING, "");
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);
  curl_easy_setopt(curl, CURLOPT_CAINFO, "cacert.pem");

  res = curl_easy_perform(curl);

  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
  printf("Response code: %ld\n", code);

  curl_easy_cleanup(curl);
  fclose(fp);

  return EXIT_SUCCESS;
}