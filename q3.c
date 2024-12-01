q3:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email) {
    if (email == NULL || email[0] == '\0') {
        return 0;
    }
    
    char* at = strchr(email, '@');
    if (at == NULL || strchr(at + 1, '@') != NULL) {
        return 0;
    }

    char* dot = strchr(at + 1, '.');
    if (dot == NULL) {
        return 0;
    }

    return 1;
}

int main() {
    char* email;
    size_t size;

    printf("Type your email: ");
    email = NULL;
    getline(&email, &size, stdin);

    if (email != NULL) {
        size_t len = strlen(email);
        if (len > 0 && email[len - 1] == '\n') {
            email[len - 1] = '\0';
        }
    }

    if (validateEmail(email) == 1) {
        printf("This is a valid email.\n");
    } else {
        printf("This is not a valid email.\n");
    }

    free(email);
    return 0;
}
