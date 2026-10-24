#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: ./typer <filepath>\n");
        return 1;
    }
    printf("%s\n", argv[1]); // aus argument path printen
    sleep(5);
    return 0;
}