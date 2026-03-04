#include <stdio.h>

int cmpStrAlphabetOrder(char* str1, char* str2);
int ValidateStr(char* str1);

int main()
{
  char str0[10] = "abcd,";
  char str1[10] = "aacd,";
  char str2[10] = "aa,";
  char str3[10] = "a";
  char o = 234;
  printf("%c \n", o);

  printf("%d \n", cmpStrAlphabetOrder(str3, str2));
}

int cmpStrAlphabetOrder(char* str1, char* str2)
{
  if(str1 && str2)
  {
    for(int i = 0; ; i++)
    {
      if(str1[i] == ',' || str1[i] == '.' || str1[i] == '\0') return 1;
      if(str2[i] == ',' || str2[i] == '.' || str1[i] == '\0') return 0;

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
  else return 2;
}

int ValidateStr(char* str1) // 0 - validation success; 1 - validation failure or invalid str.
{
  if(str1)
  {
    int validationTab[256] = {0}; // 0 - Valid symbol; 1 - Valid symbol-separator; 2 - Invalid symbol.

    for(int i = 65; i <= 90; i++){validationTab[i] = 0;} // A - Z.
    for(int i = 97; i <= 122; i++){validationTab[i] = 0;} // a - z.

    for(int i = 1; i <= 31; i++){validationTab[i] = 2;}
    for(int i = 33; i <= 43; i++){validationTab[i] = 2;}
    for(int i = 45; i <= 31; i++){validationTab[i] = 2;}
    for(int i = 127; i <= 255; i++){validationTab[i] = 2;}
    validationTab[45] = 2;

    validationTab[32] = 1; // ' '
    validationTab[44] = 1; // ','
    validationTab[46] = 1; // '.'


  }
  else
  {
    return 1;
  }
}
