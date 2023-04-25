#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(const char *input, const char *delimiter, int *num_tokens)
{

    size_t input_len = strlen(input);
    int *num_tokens = 0;
    char **tokens = malloc(input_len * sizeof(char *));
    if (tokens == NULL) {
        return NULL;
    }

    const char *start = input;
    const char *end = input;
    while (*end != '\0') {
        // Find the next occurrence of the delimiter.
        end = strstr(start, delimiter);
        if (end == NULL) {
            end = input + input_len;
        }

        // Calculate the length of the token.
        size_t token_len = end - start;

        // Allocate memory for the token and copy it.
        char *token = malloc((token_len + 1) * sizeof(char));
        if (token == NULL) {
            // Free memory for all previously allocated tokens.
            for (int i = 0; i < *num_tokens; i++) {
                free(tokens[i]);
            }
            free(tokens);
            return NULL;
        }
        strncpy(token, start, token_len);
        token[token_len] = '\0';

        // Add the token to the output array.
        tokens[*num_tokens] = token;
        (*num_tokens)++;

        // Move the start pointer to the next character.
        start = end + strlen(delimiter);
    }

    return tokens;
}

int main()
{
    const char input[] = "This is a test string.";
    const char delimiter[] = " ";
    int num_tokens = 0;

    char **tokens = split_string(input, delimiter, &num_tokens);
    if (tokens != NULL) {
        for (int i = 0; i < num_tokens; i++) {
            printf("%s\n", tokens[i]);
        }
    }

    // Free memory for the tokens.
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}

