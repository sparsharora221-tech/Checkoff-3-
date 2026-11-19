/*
 * Run-Length Encoding (RLE) classroom demonstration.
 * Input alphabet: uppercase letters A-Z only.
 * Output format: decimal run length followed by the letter (e.g., 5A3B).
 * Restricting the alphabet makes the decimal counts unambiguous to decode.
 * Review, understand, and personalize this demonstration before presenting.
 */
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int valid_input(const char *text) {
    for (const unsigned char *p = (const unsigned char *)text; *p; ++p) {
        if (*p < 'A' || *p > 'Z') return 0;
    }
    return 1;
}

static char *encode(const char *text) {
    size_t n = strlen(text);
    if (n > (SIZE_MAX - 1) / 2) return NULL;
    size_t capacity = 2 * n + 1;  /* Maximum: 1A for each character. */
    char *result = malloc(capacity);
    if (!result) return NULL;

    size_t i = 0, used = 0;
    while (i < n) {
        size_t j = i + 1;
        while (j < n && text[j] == text[i]) ++j;
        int written = snprintf(result + used, capacity - used,
                               "%zu%c", j - i, text[i]);
        if (written < 0 || (size_t)written >= capacity - used) {
            free(result);
            return NULL;
        }
        used += (size_t)written;
        i = j;
    }
    result[used] = '\0';
    return result;
}

static char *decode(const char *encoded) {
    const unsigned char *p = (const unsigned char *)encoded;
    size_t total = 0;
    while (*p) {
        if (!isdigit(*p)) return NULL;
        size_t count = 0;
        while (isdigit(*p)) {
            unsigned int digit = (unsigned int)(*p - '0');
            if (count > (SIZE_MAX - digit) / 10) return NULL;
            count = count * 10 + digit;
            ++p;
        }
        if (count == 0 || *p < 'A' || *p > 'Z') return NULL;
        ++p;
        if (count > SIZE_MAX - total - 1) return NULL;
        total += count;
    }
    char *result = malloc(total + 1);
    if (!result) return NULL;

    p = (const unsigned char *)encoded;
    size_t used = 0;
    while (*p) {
        size_t count = 0;
        while (isdigit(*p)) {
            count = count * 10 + (size_t)(*p - '0');
            ++p;
        }
        memset(result + used, *p, count);
        used += count;
        ++p;
    }
    result[used] = '\0';
    return result;
}

int main(int argc, char **argv) {
    if (argc > 2) {
        fprintf(stderr, "Usage: %s [UPPERCASE_LETTERS]\n", argv[0]);
        return EXIT_FAILURE;
    }
    const char *original = (argc == 2) ? argv[1] : "AAAAABBBCCDAA";
    if (!valid_input(original)) {
        fprintf(stderr, "This teaching demo accepts A-Z uppercase letters only.\n");
        return EXIT_FAILURE;
    }
    char *encoded = encode(original);
    if (!encoded) {
        fprintf(stderr, "Encoding failed.\n");
        return EXIT_FAILURE;
    }
    char *decoded = decode(encoded);
    if (!decoded) {
        fprintf(stderr, "Decoding failed.\n");
        free(encoded);
        return EXIT_FAILURE;
    }
    size_t before = strlen(original);
    size_t after = strlen(encoded);
    printf("Original: %s\n", original);
    printf("Encoded:  %s\n", encoded);
    printf("Decoded:  %s\n", decoded);
    printf("Sizes:    %zu -> %zu characters\n", before, after);
    if (before > 0) {
        double change = 100.0 * ((double)before - (double)after) / (double)before;
        printf("Savings:  %.1f%% (negative means expansion)\n", change);
    }
    printf("Round trip: %s\n", strcmp(original, decoded) == 0 ? "PASS" : "FAIL");
    int ok = strcmp(original, decoded) == 0;
    free(decoded);
    free(encoded);
    return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
