#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    //take string input (max : 30 digits)
    char str[30];
    scanf ("%s", str);

    //reverse the string
    int halfpoint = strlen(str) / 2;
    int str_length = strlen(str);
    for (int i = 0; i < halfpoint; i++ ){
        char temp = str[i];
        str[i] = str[str_length - i - 1];
        str[str_length - i - 1] = temp;
    }


    printf ("%s\n", str);

    int s1 = 0, s2 = 0;
    for (int i = 0; i < strlen(str); i++){

    //s1: sum the odd digits
        if(i % 2 == 0){
            char temp = str[i] - '0';
            int odd = (int) temp;
            //printf("%d\n", odd);
            s1 += odd;
        }

    //s2: multiply even digits by 2. If the product is less than 10, add it to s2. Else, add the sum of two digits to s2.
        else{
            char temp = str[i] - '0';
            int even = (int) temp;
            int product = 2 * even;
            if (product < 10){
                s2 += product;
            }
            else {
                int digit1 = product / 10;
                int digit2 = product % 10;
                s2 = s2+ digit1 + digit2;
            }
        }
    }

    //print s1 & s2.
    printf("%d%s%d\n", s1, " ", s2);

    //check whether (s1 + s2) is divisible by 10.
    if ((s1 + s2) % 10 == 0){
        printf("%s\n", "valid");
    }
    else{
        printf("%s\n", "invalid");
    }

    return 0;
}
