#include <stdio.h>

int cmpStrAlphabetOrder(char* str1, char* str2);

int main()
{
  char str0[10] = "abcd,";
  char str1[10] = "aacd,";
  char str2[10] = "aa,";
  char str3[10] = "a,";

  printf("%d \n", cmpStrAlphabetOrder(str3, str2));
}

int cmpStrAlphabetOrder(char* str1, char* str2)
{
  for(int i = 0; ; i++)
  {
    if(str1[i] == ',' || str1[i] == '.') return 1;
    if(str2[i] == ',' || str2[i] == '.') return 0;

    if(str1[i] < str2[i])
    {
      return 1;
    }

    if(str1[i] > str2[i])
    {
      return 0;
    }
  }
}
