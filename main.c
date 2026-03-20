#include <stdio.h>
#include <string.h>
#define size 256
#define wLen 12
#define separSize 7
#define arr arr0

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
    char arr6[size] = "фаавф abcd фаавф, ughabcd - haфаавфabcd: фаавф abcd-abcd-h acbd фаавф"; //4
    // For wLen == 1
    char arr7[size] = "a a   a a a  a a  a a aa  a a a"; //12

    char buff[wLen] = "abcd";

    printf("count of words is: %d \n", CountWordInStr(arr, buff));

    return 0;
}

int CountWordInStr(char* str1, char* word)
{
  if(str1 && word)
  {
    int Tab[256] = {0};
    Tab[(int)' '] = 1;
    Tab[(int)','] = 1;
    Tab[(int)'.'] = 1;
    Tab[(int)'/'] = 1;
    Tab[(int)':'] = 1;
    Tab[(int)';'] = 1;
    Tab[(int)'-'] = 1;
    Tab[(int)'('] = 1;
    Tab[(int)')'] = 1;

    size_t wordLen = strlen(word);

    int count = 0;
    int j = 0;
    int i = -1;
    do
    {
        i++;
        if(!Tab[(unsigned char)str1[i]] && str1[i] != '\0')
        {
          j++;
        }
        else
        {
          if(j == wordLen)
          {
            int cntr = i - wordLen;
            int m = 0;
            for(; m < wordLen && str1[cntr] == word[m]; m++, cntr++){}
            if(m == wordLen)
            {
              count++;
            }
          }
          j = 0;
        }
    }while(str1[i] != '\0');
    return count;
  }
  else return -1;
}
