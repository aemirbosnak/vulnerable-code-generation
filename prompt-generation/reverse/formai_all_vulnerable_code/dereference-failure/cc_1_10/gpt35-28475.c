//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
 
#define BUFFER_SIZE  (256 * 1024)  /* 256 KB */
 
/* Function to handle response from the server */
size_t responseHandler(void *ptr, size_t size, size_t nmemb, void *userData)
{
    size_t totalSize = size * nmemb;
    char *buffer = (char *)userData;
 
    if (totalSize < BUFFER_SIZE - 1)
    {
        memcpy(buffer, ptr, totalSize);
        buffer[totalSize] = '\0';
    }
 
    return totalSize;
}
 
/* Function to send the IMAP command */
int sendCommand(CURL *curl, const char *command)
{
    CURLcode res;
 
    res = curl_easy_setopt(curl, CURLOPT_URL, command);
    if (res != CURLE_OK)
    {
        fprintf(stderr, "Error setting URL option: %s\n", curl_easy_strerror(res));
        return 1;
    }
 
    res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        fprintf(stderr, "Error sending IMAP command: %s\n", curl_easy_strerror(res));
        return 1;
    }
 
    return 0;
}
 
int main(void)
{
    CURL *curl;
    int result = 0;
 
    curl = curl_easy_init();
    if (!curl)
    {
        fprintf(stderr, "Error initializing curl.\n");
        return 1;
    }
 
    const char *username = "yourEmail@gmail.com";
    const char *password = "yourPassword";
 
    /* Log in to the IMAP server */
    char loginCommand[256];
    snprintf(loginCommand, 256, "LOGIN \"%s\" \"%s\"", username, password);
    result = sendCommand(curl, loginCommand);
    if (result)
    {
        fprintf(stderr, "Error logging in: %d\n", result);
        return 1;
    }
 
    /* Select the INBOX folder */
    result = sendCommand(curl, "SELECT INBOX");
    if (result)
    {
        fprintf(stderr, "Error selecting INBOX folder: %d\n", result);
        return 1;
    }
 
    /* Search for messages */
    result = sendCommand(curl, "SEARCH ALL");
    if (result)
    {
        fprintf(stderr, "Error searching for messages: %d\n", result);
        return 1;
    }
 
    /* Get the list of message IDs */
    char buffer[BUFFER_SIZE];
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, responseHandler);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);
    result = sendCommand(curl, "FETCH 1:* (UID)");
    if (result)
    {
        fprintf(stderr, "Error getting message IDs: %d\n", result);
        return 1;
    }
 
    /* Parse the list of message IDs */
    char *token, *saveptr;
    token = strtok_r(buffer, " \t\r\n()", &saveptr);
    while (token != NULL)
    {
        if (isdigit(token[0]))
        {
            long uid = atol(token);
            printf("Message UID: %ld\n", uid);
        }
        token = strtok_r(NULL, " \t\r\n()", &saveptr);
    }
 
    /* Log out */
    result = sendCommand(curl, "LOGOUT");
    if (result)
    {
        fprintf(stderr, "Error logging out: %d\n", result);
        return 1;
    }
 
    /* Clean up */
    curl_easy_cleanup(curl);
 
    return 0;
}