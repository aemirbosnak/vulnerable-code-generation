//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

struct Memory {
    char *response;
    size_t size;
};

// Callback function writes data to the response structure
size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, struct Memory *data) {
    size_t new_len = data->size + size * nmemb;
    data->response = realloc(data->response, new_len + 1);
    if (data->response == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 0;
    }
    memcpy(data->response + data->size, ptr, size * nmemb);
    data->response[new_len] = '\0';
    data->size = new_len;

    return size * nmemb;
}

// Function to fetch the web page
int fetch_page(const char *url, struct Memory *chunk) {
    CURL *curl;
    CURLcode res;

    chunk->response = malloc(1);
    chunk->response[0] = '\0';
    chunk->size = 0;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, chunk);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "libcurl-agent/1.0");

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            free(chunk->response);
            return 1;
        }
    }
    return 0;
}

// Function to count the words in the fetched content
int count_words(const char *content) {
    int in_word = 0;
    int word_count = 0;
    
    while (*content) {
        if (isspace(*content) || ispunct(*content)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            word_count++;
        }
        content++;
    }
    return word_count;
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    struct Memory chunk;
    if (fetch_page(argv[1], &chunk) != 0) {
        return 1;
    }

    int word_count = count_words(chunk.response);
    printf("The web page contains %d words.\n", word_count);
    
    free(chunk.response);
    return 0;
}