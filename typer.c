#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: ./typer <filepath>\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror("fopen"); 
        sleep(5);         
        return 1;
    }

    int c;
    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }
    fclose(f);

    printf("\n");
    sleep(5);
    return 0;
}