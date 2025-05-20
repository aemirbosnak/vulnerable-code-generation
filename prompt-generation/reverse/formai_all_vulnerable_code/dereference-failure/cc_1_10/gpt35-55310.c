//FormAI DATASET v1.0 Category: Spell checking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_WORDS 100

// Define a linked list to store the dictionary words
typedef struct dict_node {
    char word[MAX_WORD_LEN];
    struct dict_node* next;
} dict_node;

// Function prototypes
int load_dictionary(dict_node** hash_table, char* dict_file);
void add_word_to_dict(dict_node** hash_table, char* word);
void free_dict(dict_node** hash_table);
int check_spelling(dict_node** hash_table, char* input_file, char* output_file);
int is_spelled_correctly(dict_node** hash_table, char* word);

int main(int argc, char* argv[]) {
    printf("Welcome to the Spell Checker!\n");

    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: spell_check <dictionary-file> <input-file>\n");
        exit(1);
    }

    // Load the dictionary
    dict_node* hash_table[MAX_DICT_WORDS] = {NULL};
    int num_words = load_dictionary(hash_table, argv[1]);
    printf("\nLoaded %d words into the dictionary.\n", num_words);

    // Perform spell checking on the input file
    int num_misspelled = check_spelling(hash_table, argv[2], "output.txt");
    printf("\n%d words were misspelled and written to 'output.txt'.\n", num_misspelled);

    // Free the memory used by the dictionary
    free_dict(hash_table);

    return 0;
}

/**
 * @brief Loads dictionary from file into a hash table.
 * 
 * @param hash_table Pointer to the hash table storing the dictionary.
 * @param dict_file The filename of the dictionary file.
 * @return int The number of words loaded into the dictionary.
 */
int load_dictionary(dict_node** hash_table, char* dict_file) {
    FILE* fp = fopen(dict_file, "r");
    if (fp == NULL) {
        printf("Error reading dictionary file.\n");
        exit(1);
    }

    char buffer[MAX_WORD_LEN];
    int num_words = 0;

    // Read each word in the file and add it to the dictionary
    while (fgets(buffer, MAX_WORD_LEN, fp)) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline

        add_word_to_dict(hash_table, buffer);
        num_words++;
    }

    fclose(fp);
    return num_words;
}

/**
 * @brief Adds a word to the dictionary.
 * 
 * @param hash_table Pointer to the hash table storing the dictionary.
 * @param word The word to add.
 */
void add_word_to_dict(dict_node** hash_table, char* word) {
    // Compute hash value for the word
    unsigned int hash_val = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash_val += tolower(word[i]) * (i+1);
    }
    hash_val %= MAX_DICT_WORDS;

    // Create a new node for the word
    dict_node* new_node = (dict_node*) malloc(sizeof(dict_node));
    strcpy(new_node->word, word);
    new_node->next = NULL;

    // Add the node to the hash table
    if (hash_table[hash_val] == NULL) {
        hash_table[hash_val] = new_node;
    }
    else {
        dict_node* curr_node = hash_table[hash_val];
        while (curr_node->next != NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
}

/**
 * @brief Frees memory used by the hash table and its nodes.
 * 
 * @param hash_table Pointer to the hash table storing the dictionary.
 */
void free_dict(dict_node** hash_table) {
    for (int i = 0; i < MAX_DICT_WORDS; i++) {
        dict_node* curr_node = hash_table[i];
        while (curr_node != NULL) {
            dict_node* next_node = curr_node->next;
            free(curr_node);
            curr_node = next_node;
        }
        hash_table[i] = NULL;
    }
}

/**
 * @brief Spell checks an input file and writes misspelled words to an output file.
 * 
 * @param hash_table Pointer to the hash table storing the dictionary.
 * @param input_file The filename of the input file.
 * @param output_file The filename of the output file to write misspelled words to.
 * @return int The number of misspelled words found.
 */
int check_spelling(dict_node** hash_table, char* input_file, char* output_file) {
    FILE* in_fp = fopen(input_file, "r");
    FILE* out_fp = fopen(output_file, "w");
    if (in_fp == NULL || out_fp == NULL) {
        printf("Error reading/writing files.\n");
        exit(1);
    }

    char buffer[MAX_WORD_LEN];
    int num_misspelled = 0;

    // Read each word in the file and check if it's spelled correctly
    while (fscanf(in_fp, "%s", buffer) != EOF) {
        int is_correct = is_spelled_correctly(hash_table, buffer);

        if (!is_correct) {
            fprintf(out_fp, "%s\n", buffer);
            num_misspelled++;
        }
    }

    fclose(in_fp);
    fclose(out_fp);
    return num_misspelled;
}

/**
 * @brief Checks if a word is spelled correctly by searching for it in the hash table.
 * 
 * @param hash_table Pointer to the hash table storing the dictionary.
 * @param word The word to check.
 * @return int 1 if spelled correctly, 0 if misspelled.
 */
int is_spelled_correctly(dict_node** hash_table, char* word) {
    // Compute hash value for the word
    unsigned int hash_val = 0;
    for (int i = 0; i < strlen(word); i++) {
        hash_val += tolower(word[i]) * (i+1);
    }
    hash_val %= MAX_DICT_WORDS;

    // Search for the word in the hash table
    dict_node* curr_node = hash_table[hash_val];
    while (curr_node != NULL) {
        if (strcmp(curr_node->word, word) == 0) {
            return 1; // Word found in dictionary
        }
        curr_node = curr_node->next;
    }

    return 0; // Word not found in dictionary
}