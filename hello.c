#include <stdlib.h>
#include <string.h>
#include <stdio.h>  // Added to declare printf

int main(int argc, char *argv[]) {
    char *string = NULL, *string_so_far = NULL;
    int i, length = 0;

    for (i = 0; i < argc; i++) {
        length += strlen(argv[i]) + 1;
        string = malloc(length + 1);
        if (string == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        /* Copy the string built so far. */
        if (string_so_far != NULL)
            strcpy(string, string_so_far);
        else
            *string = '\0';

        strcat(string, argv[i]);
        if (i < argc - 1)
            strcat(string, " ");
        
        free(string_so_far);  // Free the previously allocated memory
        string_so_far = string;
    }

    printf("You entered: %s\n", string_so_far);
    free(string_so_far);  // Free the final allocated memory

    return 0;
}