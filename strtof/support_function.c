#include <stdio.h>
#include <stdint.h>
#include <math.h>

double strToFloat(char* str)
{
    uint8_t int_num = 0;
    uint8_t float_num = 0;
    uint8_t dot_num = 0;
    uint8_t counter_char = 0;
    while (str[counter_char] != '\0')
    {
        if(str[counter_char]>=48 && str[counter_char]<=57)
        {
            if(dot_num < 1)
            {
                ++int_num;
            }
            else{
                ++float_num;
            }

        }
        else if(str[counter_char]==46 && dot_num < 1)
        {
            ++dot_num;
        }
        else{
            printf("Chuoi khong hop le!. Status code: ");
            return -1;
        }
        ++counter_char;
    }
    uint32_t int_val = 0;
    uint32_t float_val = 0.0;
    uint32_t temp =0;
    double value = 0.0;

    for(int i=1; i<=int_num; i++)
    {
        temp = str[i-1] - 48;
        int_val += temp * pow(10, int_num-i);
    }
    
    for(int i=1; i<=float_num; i++)
    {
        temp = str[int_num+i] - 48;
        
        float_val += temp * pow(10, float_num-i);
    }
    value = (double)float_val / (pow(10, float_num));
    value += (double)int_val;

    return value;
}
