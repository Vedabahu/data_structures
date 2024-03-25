// return the longest palindromic substring in the given string
#include <stdio.h>
#include <string.h>

char stack[500];
int top = -1;

void find_palindrome(int left, int right, int length, char* str, char* palindrome) {
    while (left > -1 && right < length) {
        if (str[left] != str[right]) {
            break;
        }
        left -= 1;
        right += 1;
    }
    int i, flag = 0;
    for (i = 0, left += 1; i < right - left - 1; i++) {
        palindrome[i] = str[left + i];
        flag = 1;
    }
    palindrome[i] = flag ? str[left + i] : palindrome[i];
}

int main(void) {
    char str[500];
    printf("Enter a string : ");
    scanf(" %s", str);

    char palindrome[500] = "", final[500] = "";
    int left = 0;
    int right = 1, length = strlen(str), longst = 0;

    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        left = i - 1;
        right = i + 1;

        find_palindrome(left, right, length, str, palindrome);

        if (strlen(palindrome) > longst) {
            strcpy(final, palindrome);
            longst = strlen(palindrome);
        }
    }

    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        left = i - 1;
        right = i;

        find_palindrome(left, right, length, str, palindrome);

        if (strlen(palindrome) > longst) {
            strcpy(final, palindrome);
            longst = strlen(palindrome);
        }
    }

    printf("The longest palindrome is %s.\n", final);
    printf("Its length is %d\n", longst);

    return 0;
}
