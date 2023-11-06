#include <stdio.h>
#include <string.h>

int main() {
    char destination[20] = "Hello, ";
    const char *source = "World!";

    size_t result = strlcat(destination, source, 30);

    printf("Chaîne concaténée : %s\n", destination);
    printf("Nombre de caractères qui auraient été concaténés : %zu\n", result);

    return 0;
}

