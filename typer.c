#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("Filepath given: %s \n", argv[1]);
    FILE *pFile = fopen(argv[1], "r");
    char buffer[1024] = {0};

    if(pFile == NULL){
        printf("Couldnt open/find the file ig");
        return 1;
    }

    while(fgets(buffer, sizeof(buffer), pFile) != NULL){
        printf("%s\n",buffer);
    }

    sleep(10);
    fclose(pFile);
    return 0;
}