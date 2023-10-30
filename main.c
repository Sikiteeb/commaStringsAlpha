#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int compareStrings(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;


    char trimmedStr1[1000];
    char trimmedStr2[1000];

    strcpy(trimmedStr1, str1);
    strcpy(trimmedStr2, str2);

    char *ptr1 = trimmedStr1;
    char *ptr2 = trimmedStr2;

    while (*ptr1 && (*ptr1 == ' ' || *ptr1 == '\t')) {
        ptr1++;
    }

    while (*ptr2 && (*ptr2 == ' ' || *ptr2 == '\t')) {
        ptr2++;
    }


    return strcasecmp(ptr1, ptr2);
}

int main() {
    char input[1000];
    printf("Enter a comma-separated list of strings: ");
    fgets(input, sizeof(input), stdin);


    char *token;
    char *strings[100];
    int count = 0;

    token = strtok(input, ",");
    while (token != NULL) {
        strings[count++] = strdup(token);
        token = strtok(NULL, ",");
    }


    qsort(strings, count, sizeof(char *), compareStrings);


    printf("Sorted strings:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }

    return 0;
}
