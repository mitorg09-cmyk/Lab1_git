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
    int Tab[256] = {0};
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
      if(!Tab[(unsigned char)str1[i]])
      {
        if(!(j == 0 && i - 1 >= 0) || Tab[(unsigned char)str1[i - 1]])
        {
          if(word[j] == str1[i] && word[j + 1] != '\0')
          {
            j++;
            i++;
          }
          else if(word[j] == str1[i] && (str1[i + 1] == '\0' || Tab[(unsigned char)str1[i + 1]]))
          {
            count++;
            i++;
            j = 0;
          }
          else if(j == 0)
          {
            i++;
          }
          else
          {
            j = 0;
          }
        }
        else
        {
          i++;
        }
      }
      else
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
