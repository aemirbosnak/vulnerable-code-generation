//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <time.h>

void TypingSpeedTest() {
    int wordsPerMinute = 0;
    int totalWords = 0;
    int totalCharacters = 0;
    int totalTime = 0;
    int numWords;
    int numCharacters;
    int numTime;
    int totalWordsPerMinute = 0;
    int totalTimePerMinute = 0;
    int totalCharactersPerMinute = 0;
    int wordsPerMinuteCalc = 0;
    int charactersPerMinuteCalc = 0;
    int timePerMinuteCalc = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please type the following sentence as fast as you can:\n");
    printf("The quick brown fox jumps over the lazy dog.\n");
    fflush(stdout);

    clock_t start = clock();
    numWords = strlen("The quick brown fox jumps over the lazy dog.");
    numCharacters = strlen("The quick brown fox jumps over the lazy dog.");
    numTime = clock() - start;

    start = clock();
    wordsPerMinute = numWords / (numTime / CLOCKS_PER_SEC);
    totalWords += numWords;
    totalTime += numTime;
    totalWordsPerMinute += wordsPerMinute;
    totalTimePerMinute += (numTime / CLOCKS_PER_SEC);
    totalCharactersPerMinute += numCharacters;

    start = clock();
    charactersPerMinuteCalc = numCharacters / (numTime / CLOCKS_PER_SEC);
    wordsPerMinuteCalc = numWords / (numTime / CLOCKS_PER_SEC);
    timePerMinuteCalc = (numTime / CLOCKS_PER_SEC);

    printf("You typed %d words in %.2f seconds, with an average speed of %.2f words per minute.\n", numWords, numTime, wordsPerMinute);
    printf("You typed %d characters in %.2f seconds, with an average speed of %.2f characters per minute.\n", numCharacters, numTime, charactersPerMinuteCalc);
    printf("Your total words typed is %d and your total time is %.2f seconds.\n", totalWords, totalTime);
    printf("Your total words typed per minute is %.2f and your total characters typed per minute is %.2f.\n", totalWordsPerMinute / totalTimePerMinute, totalCharactersPerMinute / totalTimePerMinute);
}

int main() {
    TypingSpeedTest();
    return 0;
}