#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

void calculate_Readability(string text);

int main(void)
{
    string text;
    do
    {
        text = get_string("Text: ");
    } 
    while (strlen(text) < 20);
    
    calculate_Readability(text);
}

void calculate_Readability(string text)
{
    int word_count = 1;
    int sentence_count = 0;
    int letters_count = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
       if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
       {
           letters_count++;
       }
       else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
       {
           sentence_count++;
       }
       else if (text[i] == ' ')
       {
           word_count++;
       }
    }
    
    float grade = 0.0588 * (100 * (float) letters_count / (float) word_count) - 0.296 * (100 * (float) sentence_count / (float) word_count) - 15.8;
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}
