#include <stdio.h>
#include <string.h>

void GetAlphabetOrder(char str[256], int Order[128]);

int main()
{
    char str1[256] = "abcd,aaaa,a,bd,hihiab,ab,aabc.";
    int Ord[128] = {0};
    GetAlphabetOrder(str1, Ord);
}

void GetAlphabetOrder(char str[256], int Order[128])
{
    unsigned short indxOfWords[128] = {0};

    int wordCounter = 0;
    indxOfWords[0] = 0;
    for(int i = 0; str[i] != '.'; i++)
    {
        if(str[i] == '\0')
        {
          printf("Point exception");
          return;
        }

        if(str[i] == ',')
        {
            wordCounter++;
            indxOfWords[wordCounter] = i + 1;
        }
    }

    unsigned short cmpStep = 0;
    for(int i = 0; i <= wordCounter; i++)
    {
      unsigned short tmpMin = 0;
      for(int k = 0; k <= wordCounter; k++)
      {
        if(Order[tmpMin] != 0)
        {
          tmpMin++;
        }
        else if(str[indxOfWords[k] + cmpStep] < str[indxOfWords[tmpMin] + cmpStep] && Order[k] == 0)
        {
          tmpMin = k;
        }
      }

      if(tmpMin <= wordCounter)
        Order[tmpMin] = i + 1;

      for(int k = 0; k <= wordCounter; k++)
      {
        if(str[indxOfWords[k] + cmpStep] == str[indxOfWords[tmpMin] + cmpStep] && Order[k] == 0)
        {
          Order[k] = i + 1;
        }
      }
    }

    for(int i = 0; i < 128; i++)
    {
      printf("%d \n", Order[i]);
    }

}

