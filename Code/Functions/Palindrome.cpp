#include <stdio.h>
#include <string.h>


int ifPalinElse(char str[], int first, int last) {

    if (first >= last)
        return 1;

    if (str[first] != str[last])
        return 0;

    return ifPalinElse(str, first + 1, last - 1);
}

int main() {
    char str[67];
    printf("INPUT: ");
    scanf("%s", str);

    int length = strlen(str);

    if (ifPalinElse(str, 0, length - 1))
        printf("OUTPUT:Palindrome\n");
    else
        printf("OUTPUT:Not a Palindrome\n");

    return 0;
}