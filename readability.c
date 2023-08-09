#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string para);
int count_words(string para);
int count_sentences(string para);

int main(void)
{
    string text = get_string("Text: ");
    int l = count_letters(text);
    int w = count_words(text);
    int s = count_sentences(text);
    float L = l / (0.01 * w);
    float S = s / (0.01 * w);
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string para)
{
    int count = 0;
    for (int i = 0; i < strlen(para); i++)
    {
        if (isalpha(para[i]))
        {
            count += 1;
        }
    }
    return count;
}

int count_words(string para)
{
    int count = 1;
    for (int i = 0; i < strlen(para); i++)
    {
        char letter = para[i];
        if (letter == ' ')
        {
            count += 1;
        }
    }
    return count;
}

int count_sentences(string para)
{
    int count = 0;
    for (int i = 0; i < strlen(para); i++)
    {
        char letter = para[i];
        if (letter == '.' || letter == '?' || letter == '!')
        {
            count += 1;
        }
    }
    return count;
}
