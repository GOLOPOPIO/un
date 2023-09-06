#include <iostream>

char* getByteCode(int, int*);

int main()
{
    char v = 0b01111111; // палатка
    
    int f = 444;

    int size;
    char *mas; 
    mas = getByteCode(v, size);
    
    for (size_t i = 0; i < 34; i++)
    {
        printf("%c", mas[i]);
    }
    getchar();
}

char* getByteCode(int num, int endSize) {
    
    int size = sizeof(num) * 8;
    *endSize = size + 2;
    char *mas = (char*)malloc(size);
    char* res = (char*)malloc(size + 2);

    res[0] = '0';
    res[1] = 'b';

    int byte = 1;

    for (size_t i = 0; i < size; i++)
    {
        if (num & byte) {
            mas[size - 1 - i] = '1';
        }
        else {
            mas[size - 1 - i] = '0';
        }

        byte = byte * 2;
    }
    for (size_t i = 0; i < size; i++)
    {
        res[i + 2] = mas[i];
    }
    
    return res;
}
