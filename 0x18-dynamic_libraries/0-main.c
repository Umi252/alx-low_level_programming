#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main(void)
{
    char s[] = "Hello, World!";
    int len;

    _puts(s);

    len = _strlen(s);
    printf("Length: %d\n", len);

    return (EXIT_SUCCESS);
}

