#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_arguments(int argc, char *argv[], char *decimal_separator, char *list_separator) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0 && i + 1 < argc) {
            *decimal_separator = argv[i + 1][0];
            i++;
        } else if (strcmp(argv[i], "-v") == 0 && i + 1 < argc) {
            *list_separator = argv[i + 1][0];
            i++;
        }
    }
}

void process_file(char decimal_separator, char list_separator) {
    char *line = NULL;
    size_t len = 0;
    double *numbers = NULL;
    size_t numbers_len = 0;

    while (getline(&line, &len, stdin) != -1) {
        for (char *p = line; *p != '\0'; p++) {
            if (*p == decimal_separator) {
                *p = '.';
            } else if (*p == list_separator) {
                *p = ' ';
            }
        }

        char *endptr;
        for (char *p = line; *p != '\0'; p = endptr) {
            double num = strtod(p, &endptr);
            if (p == endptr) {
                break;
            }

            numbers = realloc(numbers, (numbers_len + 1) * sizeof(double));
            numbers[numbers_len++] = num;
        }
    }

    for (size_t i = 0; i < numbers_len; i++) {
        printf("%f\n", numbers[i]);
    }

    free(numbers);
    free(line);
}

int main(int argc, char *argv[]) {
    char decimal_separator = '.';
    char list_separator = ' ';

    parse_arguments(argc, argv, &decimal_separator, &list_separator);

    if (decimal_separator == list_separator || list_separator == '.') {
        fprintf(stderr, "Error: Invalid separators.\n");
        return 1;
    }

    process_file(decimal_separator, list_separator);

    return 0;
}

