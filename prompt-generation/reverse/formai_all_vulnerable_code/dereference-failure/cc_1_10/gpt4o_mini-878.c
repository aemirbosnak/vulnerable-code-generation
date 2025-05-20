//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_TITLE_LENGTH 255
#define OUTPUT_FILE "titles.txt"

// Structure to hold the response from the web page
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function for CURL to write the page content to memory
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *mem) {
    size_t realsize = size * nmemb;
    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        printf("Not enough memory!\n");
        return 0; // Out of memory
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0; // Null-terminate the string
    return realsize;
}

// Function to extract the title from the HTML content
char* extract_title(const char *html) {
    char *title_start = strstr(html, "<title>");
    if (!title_start) return NULL;
    title_start += 7; // Move past "<title>"
    char *title_end = strstr(title_start, "</title>");
    if (!title_end) return NULL;

    size_t title_length = title_end - title_start;
    char *title = malloc(title_length + 1);
    strncpy(title, title_start, title_length);
    title[title_length] = '\0'; // Null-terminate the title
    return title;
}

// Main plugin execution function
void run_plugin(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);  // Initial allocation
    chunk.size = 0;            // No data at this point

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "C Browser Plugin");

        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Successfully fetched the page
            char *title = extract_title(chunk.memory);
            if (title) {
                printf("Page title: %s\n", title);
                FILE *output = fopen(OUTPUT_FILE, "a");
                if (output) {
                    fprintf(output, "%s\n", title);
                    fclose(output);
                } else {
                    fprintf(stderr, "Could not open output file for writing.\n");
                }
                free(title);
            } else {
                printf("No title found in the HTML content.\n");
            }
        }

        // Cleanup
        free(chunk.memory);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

// Entry point of the browser plugin
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    run_plugin(argv[1]);
    return 0;
}