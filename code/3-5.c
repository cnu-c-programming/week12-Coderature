#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    char token[256];

    while (fscanf(fp, "%255s", token) == 1) {
        int value;
        char extra;

        if (sscanf(token, "%d%c", &value, &extra) == 1) {
            sum += value;
        } else {
            fprintf(stderr, "invalid input %s\n", token);
        }
    }

    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}