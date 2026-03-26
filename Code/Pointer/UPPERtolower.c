#include <stdio.h>
#include <ctype.h>

int main() 
{
    char str[80], *p;

    printf("Enter a string in uppercase: ");
    fgets(str, sizeof(str), stdin);

    printf("Here's the string in lowercase:\n");

    p = str;
    while (*p) {
        printf("%c", tolower(*p));
        p++;
    }

    return 0;
}