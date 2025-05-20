//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Cyberpunk
// Welcome to the neon-drenched metropolis of Cyber City, where data flows like illicit substances.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Step into the neon-lit alleyways and retrieve the article.
char *fetch_article() {
    char *article_path = "shadowy_article.txt";
    FILE *article_stream = fopen(article_path, "r");
    if (article_stream == NULL) {
        printf("Error: Unable to access the article. Perhaps it's hidden in a secret safe house?\n");
        return NULL;
    }
    fseek(article_stream, 0L, SEEK_END);
    long article_size = ftell(article_stream);
    fseek(article_stream, 0L, SEEK_SET);
    char *article = malloc(article_size + 1);
    fread(article, 1, article_size, article_stream);
    fclose(article_stream);
    return article;
}

// In the dimly lit bar, we parse the article using our neural implants.
int summarize_article(char *article) {
    // Initialize the summary. Careful, it's as fragile as a neon sign in a typhoon.
    char *summary = malloc(strlen(article) / 2 + 1);
    int summary_index = 0;

    // Tokenize the article, treating spaces as the gateway to new worlds.
    char *token = strtok(article, " ");
    while (token != NULL) {
        // Apply advanced algorithms to filter out the noise.
        if (strlen(token) >= 4 && !strchr(".,:;?!", token[strlen(token) - 1])) {
            // Inject the token into the summary.
            int token_length = strlen(token);
            memcpy(summary + summary_index, token, token_length);
            summary_index += token_length;
            summary[summary_index++] = ' ';
        }
        token = strtok(NULL, " ");
    }

    // Trim the excess, leaving behind only the essence.
    summary[summary_index] = '\0';

    // Display the summary on the holographic screen, flickering amidst the neon haze.
    printf("**Summary:**\n%s\n", summary);

    free(summary);
    return 0;
}

int main() {
    // Dive into the article, where secrets lurk in every byte.
    char *article = fetch_article();
    if (article == NULL) {
        return 1;
    }

    // Analyze the article, extracting its core like a skilled thief.
    int summarize_status = summarize_article(article);
    if (summarize_status != 0) {
        printf("Error: Something went wrong in the neon-lit alleys of my mind.\n");
        free(article);
        return 1;
    }

    // Release the article back into the digital abyss.
    free(article);

    // Exit the Cyberpunk realm, leaving behind a trail of neon and summary.
    return 0;
}