#include <stdio.h>
#include <string.h>
#define size 256
#define wLen 128
#define separSize 7
#define arr arr6

int CountWordInStr(char* str1, char* word);

int main()
{
    // For wLen == 4
    char arr0[size] = "abcd abcd abcd, ughabcd - hababcd: abcd-abcd-h acbd abcd"; //6
    char arr1[size] = "abcd, ..abcd.. (abcd), ughabcd:- - hababcd: ()abcd-abcd-h acbd abcd"; //6
    char arr2[size] = "abcdabcd-abcd"; //1
    char arr3[size] = "abcd abcd abcd abcd"; //4
    char arr4[size] = "abcd acbd acdb abdc adcb acbd adbc acdb"; //1
    char arr5[size] = "abcd123 abcd abcd, ughabcd - hababcd: abcd-abcd-h acbd 123abcd"; //4
    char arr6[size] = "abcd123 фпыпавп abcd, .фпыпавп.фпыпавпфпыпавпabcd - фпыпавп фпыпавп фпыпавп"; //5
    // For wLen == 1
    char arr7[size] = "a a   a a a  a a  a a aa  a a a"; //12

    char buff[wLen] = "фпыпавп";

    printf("count of words is: %d \n", CountWordInStr(arr, buff));//
    return 0;
}

int CountWordInStr(char* str1, char* word)
{
  if(str1 && word)
  {
    int Tab[256] = {0}; // 0 - Normal symbol, 1 - symbol-separator.
    Tab[(int)' '] = 1;
    Tab[(int)','] = 1;
    Tab[(int)':'] = 1;
    Tab[(int)'-'] = 1;
    Tab[(int)'('] = 1;
    Tab[(int)')'] = 1;
    Tab[(int)'.'] = 1;

    int count = 0;

    int j = 0;
    int i = 0;
    while(str1[i] != '\0')
    {
      if(!Tab[(unsigned char)str1[i]]) // If symbol is not separator
      {
        if(!(j == 0 && i - 1 >= 0) || Tab[(unsigned char)str1[i - 1]]) // Implication (If str1[j] is potencial begin of word and str1[i-1]
        {                                                              // exists, that str1[i-1] must be separator).Word not is cont. of anth. word.
          if(word[j] == str1[i] && word[j + 1] != '\0') // Equal matching symbols of str1 and word.
          {
            j++;
            i++;
          }
          else if(word[j] == str1[i] && (str1[i + 1] == '\0' || Tab[(unsigned char)str1[i + 1]])) // What is stop reason?
          { // And word is not a beginig of another word checking.
            count++; // Than its a word
            i++;
            j = 0;
          }
          else if(j == 0) // If begining of current word is not equeal with symbol in str1, than this symbol not in word.
          {
            i++; // Checking this symbol is not reasonable, than skip sybol.
          }
          else // Else current symbol not a begining of word, than need to check symbol as the begining.
          {
            j = 0;
          }
        }
        else // If word is continue of another word than skip.
        {
          i++;
        }
      }
      else // if symbol is separator than skip.
      {
        j = 0;
        i++;
      }
    }
    return count;
  }
  else
  {
    return -1; // Error code.
  }
}
