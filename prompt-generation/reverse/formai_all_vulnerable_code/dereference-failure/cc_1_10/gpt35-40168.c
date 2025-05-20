//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_DOWNLOAD_SIZE 10485760   // 10 MB in bytes
#define TIME_OUT 30                  // Time out value in seconds

typedef struct {
   char* data;
   size_t size;
} BUFFER;

// Callback function for storing response data in buffer
static size_t write_callback(char* data, size_t size, size_t nmemb, void* user_data) {
   size_t actual_size = size * nmemb;
   BUFFER* buffer = (BUFFER*)user_data;
   if (buffer->size + actual_size >= MAX_DOWNLOAD_SIZE) {
      return 0;
   }
   memcpy(buffer->data + buffer->size, data, actual_size);
   buffer->size += actual_size;
   return actual_size;
}

// Get current date and time as string
char* current_date_time() {
   time_t current_time;
   time(&current_time);
   return ctime(&current_time);
}

// Speed test function
double speed_test(char* url) {
   CURL* curl_handle;
   CURLcode res;
   BUFFER buffer = { malloc(MAX_DOWNLOAD_SIZE), 0 };
   
   // Set up curl handle
   curl_handle = curl_easy_init();
   if (!curl_handle) {
      return -1.0;
   }
   curl_easy_setopt(curl_handle, CURLOPT_URL, url);
   curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, TIME_OUT);
   curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);
   curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &buffer);
   
   // Perform the request
   res = curl_easy_perform(curl_handle);
   if (res != CURLE_OK || buffer.size == 0) {
      printf("Speed test failed: %s\n", curl_easy_strerror(res));
      return -1.0;
   }
   
   // Calculate download speed
   double elapsed_time = 0, download_speed = -1.0;
   long download_size = (long)buffer.size;
   res = curl_easy_getinfo(curl_handle, CURLINFO_TOTAL_TIME, &elapsed_time);
   if (res == CURLE_OK && elapsed_time > 0) {
      download_speed = (double)download_size / (elapsed_time * 1048576);
   }
   
   // Clean up
   curl_easy_cleanup(curl_handle);
   free(buffer.data);
   
   return download_speed;
}

int main() {
   char url[256];
   printf("Enter the URL to test (e.g. http://example.com): ");
   fgets(url, sizeof(url), stdin);
   url[strcspn(url, "\n")] = '\0';  // Remove newline character
   
   // Perform speed test
   double download_speed = speed_test(url);
   if (download_speed >= 0) {
      printf("Speed test successful!\n");
      printf("Download speed: %.2f Mbps\n", download_speed);
   }
   printf("Test completed at %s", current_date_time());
   return 0;
}