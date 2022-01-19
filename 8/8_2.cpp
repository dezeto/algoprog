#include <stdio.h>
#include <string.h>

void write(char nama[101][101], int harga[101], int size)
{
    // open
    FILE *f = fopen("menu.txt", "w");

    // logic
    for (int i = 0; i < size; ++i)
    {
        fprintf(f, "%s#%d\n", nama[i], harga[i]);
    }

    // close
    fclose(f);
}

void read()
{
    FILE *f = fopen("menu.txt", "r");

    if (f == NULL)
    {
        printf("File not found !\n");
        return;
    }

    while (!feof(f))
    {
        char nama[101];
        int price;
        fscanf(f, "%[^#]#%d\n", nama, &price);
        printf("%s - %d\n", nama, price);
    }
    fclose(f);
}

void append(char nama[101][101], int harga[101], int size)
{
    // open
    FILE *f = fopen("menu.txt", "a");

    // logic
    for (int i = 0; i < size; ++i)
    {
        fprintf(f, "%s#%d\n", nama[i], harga[i]);
    }

    // close
    fclose(f);
}

int main()
{
    char nama[][101] = {"Pisang Goreng", "Mie Goreng", "Lumpia"};
    int price[] = {10000, 20000, 30000};

    int size = sizeof(nama) / sizeof(nama[0]);
    // write(nama, price, size);
    read();
    append(nama, price, size);

    return 0;
}