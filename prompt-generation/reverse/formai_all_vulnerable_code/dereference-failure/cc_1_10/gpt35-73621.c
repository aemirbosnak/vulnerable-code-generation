//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_SIZE 200000 // Maximum input text size
#define MAX_SENTENCES 1000 // Maximum number of sentences in summary

typedef struct sentence{
    char* sentence_string; // Pointer to sentence string
    int score; // Score assigned to the sentence for importance
} Sentence;

int count_sentences(char* input_text);
void tokenize_sentences(char* input_text, Sentence* sentences, int num_sentences);
void assign_scores(Sentence* sentences, int num_sentences);
void print_summary(Sentence* sentences, int summary_size);

int main()
{
    // Step 1: Read input text
    char input_text[MAX_INPUT_SIZE];
    printf("Enter text to summarize: ");
    fgets(input_text, sizeof(input_text), stdin);

    // Step 2: Count number of sentences and allocate memory for Sentence array
    int num_sentences = count_sentences(input_text);
    Sentence* sentences = malloc(sizeof(Sentence) * num_sentences);

    // Step 3: Tokenize sentences and store in Sentence array
    tokenize_sentences(input_text, sentences, num_sentences);

    // Step 4: Assign scores to sentences based on importance
    assign_scores(sentences, num_sentences);

    // Step 5: Print summary
    printf("\nSummary:\n");
    print_summary(sentences, 5); // Print top 5 most important sentences

    // Step 6: Free allocated memory
    free(sentences);

    return 0;
}

// Function to count number of sentences in input text
int count_sentences(char* input_text)
{
    int length = strlen(input_text);
    int num_sentences = 0;

    for(int i=0; i<length; i++)
    {
        if(input_text[i] == '.' || input_text[i] == '?' || input_text[i] == '!')
        {
            num_sentences++;
        }
    }

    return num_sentences;
}

// Function to tokenize sentences in input text and store in Sentence array
void tokenize_sentences(char* input_text, Sentence* sentences, int num_sentences)
{
    char* sentence = strtok(input_text, ".?!"); // Tokenize first sentence
    int i = 0;

    while(sentence != NULL && i<num_sentences)
    {
        sentences[i].sentence_string = malloc(strlen(sentence) + 1); // Allocate memory for sentence string
        strcpy(sentences[i].sentence_string, sentence); // Copy sentence string to Sentence struct
        sentence = strtok(NULL, ".?!"); // Tokenize next sentence
        i++;
    }
}

// Function to assign scores to sentences based on importance
void assign_scores(Sentence* sentences, int num_sentences)
{
    // TODO: Use NLP algorithm to assign scores to sentences based on importance
    // For now, assign random scores between 1 and 10
    for(int i=0; i<num_sentences; i++)
    {
        sentences[i].score = rand() % 10 + 1;
    }
}

// Function to print summary
void print_summary(Sentence* sentences, int summary_size)
{
    // Sort sentences by score in descending order
    for(int i=0; i<summary_size; i++)
    {
        for(int j=i+1; j<summary_size; j++)
        {
            if(sentences[j].score > sentences[i].score)
            {
                Sentence temp_sentence = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp_sentence;
            }
        }
    }

    // Print top summary_size most important sentences
    for(int i=0; i<summary_size; i++)
    {
        printf("%s ", sentences[i].sentence_string);
    }
}