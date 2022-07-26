#include <stdio.h>
#include <stdint.h>

extern uint32_t strToInt();

uint32_t test_strtod(char* str, char** ptr)
{
    uint8_t i=0;
    uint8_t j =0;
    uint8_t z = 0;
    uint32_t num = 0;
    char temp_str[20]="";
    static char str_part[50]="";
    while(str[i] != '\0')
    {
        if(str[i]>=48 && str[i]<=57)
        {
            while(str[i]>=48 && str[i]<=57)
            {
                temp_str[j]=str[i];
                str[i]= '\0';
                ++j;
                ++i;
            }
            num = strToInt(temp_str);
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
    uint32_t num = 0;
    char string[] = "abc 123 dxy"; // <-- Input new string here
    char* ptr;

    num = test_strtod(string, &ptr);
    printf("Integer part is: %d\n", num);
    printf("String part is: %s\n", ptr);

    return 0;
}
