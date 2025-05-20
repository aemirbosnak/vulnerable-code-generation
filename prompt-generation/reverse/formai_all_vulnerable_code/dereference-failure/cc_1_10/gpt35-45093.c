//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 4096

char* read_file(char* file_name)
{
    FILE* file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Error opening file %s\n", file_name);
        exit(-1);
    }
    char* buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    int i = 0;
    while (!feof(file))
    {
        buffer[i] = fgetc(file);
        i++;
    }
    buffer[i] = '\0';
    fclose(file);
    return buffer;
}

char* beautify_html(char* html)
{
    char* beautified_html = (char*)malloc(BUFFER_SIZE * sizeof(char));
    int beautified_index = 0;
    int indent_level = 0;
    char current_char = '\0';
    char previous_char = '\0';
    int in_tag = 0;
    int in_quotes = 0;
    while (*html != '\0')
    {
        current_char = *html;
        if (current_char == '<' && previous_char != '<')
        {
            in_tag = 1;
            beautified_html[beautified_index] = '\n';
            beautified_index++;
            for (int i = 0; i < indent_level; i++)
            {
                beautified_html[beautified_index] = ' ';
                beautified_index++;
            }
        }
        beautified_html[beautified_index] = current_char;
        beautified_index++;
        if (current_char == '"' && previous_char != '\\')
        {
            in_quotes = !in_quotes;
        }
        if (current_char == '>' && !in_quotes && previous_char != '>')
        {
            in_tag = 0;
            indent_level++;
        }
        if (current_char == '/' && previous_char == '<')
        {
            indent_level--;
        }
        previous_char = current_char;
        html++;
    }
    beautified_html[beautified_index] = '\0';
    return beautified_html;
}

void* beautify_html_thread(void* arg)
{
    char* file_name = (char*)arg;
    char* html = read_file(file_name);
    char* beautified_html = beautify_html(html);
    printf("%s:\n%s\n", file_name, beautified_html);
    free(html);
    free(beautified_html);
    return NULL;
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <file1> [<file2> ...]\n", argv[0]);
        exit(-1);
    }
    pthread_t* threads = (pthread_t*)malloc(argc * sizeof(pthread_t));
    for (int i = 1; i < argc; i++)
    {
        pthread_create(&threads[i], NULL, beautify_html_thread, argv[i]);
    }
    for (int i = 1; i < argc; i++)
    {
        pthread_join(threads[i], NULL);
    }
    free(threads);
    return 0;
}