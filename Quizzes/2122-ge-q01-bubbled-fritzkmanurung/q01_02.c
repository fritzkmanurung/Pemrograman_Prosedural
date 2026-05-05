// 12S21014 - Fritz Kevin Manurung

#include <stdio.h>
#include <string.h>

int main(int _argc, char **_argv)
{
    char text[105];
    if (scanf("%100s", text) != 1) return 0;
            
    char arr[105];
    int count = 0;
    int len = strlen(text);
                            
    for(int i = 0; i < len; i++) {
        if(text[i] != ',') {
            arr[count++] = text[i];
        }
    }
                            
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count - i - 1; j++) {
            if(arr[j] < arr[j+1]) {
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
               
    for(int i = 0; i < count; i++) {
        printf("%c", arr[i]);
        if(i < count - 1) printf(",");
    }
    printf("\n");
                               
    return 0;
}
