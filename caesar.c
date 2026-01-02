#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void rotate(string plaintext, int key)
{
    int n = 0;
    while (plaintext[n] != '\0')
    {
        if (isalpha(plaintext[n]))
        {
            if (islower(plaintext[n]))
            {
                int pos = plaintext[n] - 'a';
                int newpos = (pos + key) % 26;
                plaintext[n] = 'a' + newpos;
            }
            else if (isupper(plaintext[n]))
            {
                int pos = plaintext[n] - 'A';
                int newpos = (pos + key) % 26;
                plaintext[n] = 'A' + newpos;
            }
        }
        n++;
    }
}
int only_digits(string key)
{
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isdigit(key[i]))
        {
            return 0;
        }
    }
    return 1;
}
int main(int args, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (args != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);
    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    // Make rotation
    rotate(plaintext, key);
    // Give output
    printf("ciphertext: %s\n", plaintext);
}
