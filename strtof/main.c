#include <stdio.h>
#include <stdint.h>

extern double strToFloat();

double test_strtof(char* str, char** ptr)
{
    uint8_t i=0;
    uint8_t j =0;
    uint8_t z = 0;
    double num = 0;
    char temp_str[20]="";
    static char str_part[50]="";
    while(str[i] != '\0')
    {
        if(str[i]>=48 && str[i]<=57)
        {
            while((str[i]>=48 && str[i]<=57)|| str[i]==46)
            {
                temp_str[j]=str[i];
                str[i]= '\0';
                ++j;
                ++i;
            }
            num = strToFloat(temp_str);
        }
        str_part[z]=str[i];
        ++z;
        ++i;
    }
    *ptr = str_part;
    return num;
}

int main()
{
    double num = 0;
    char string[] = "abc 12.3 dxy"; // <-- Input new string here
    char* ptr;

    num = test_strtof(string, &ptr);
    printf("Float part is: %f\n", num);
    printf("String part is: %s\n", ptr);

    return 0;
}
