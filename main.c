#include <stdio.h>
#include <unistd.h> // for fork apparently
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */

int main(void)
{
    printf("Hello World \n");
    printf("Pick your mode \n");
    printf("1) Testing \n");
    printf("2) Doesnt work \n");

    int userInput;
    char filepath[512];
    if(scanf("%d", &userInput) != 1){
        printf("User Input couldnt be read \n");
        return 1;
    }
    printf("%d \n",userInput);

    switch (userInput) {
        case 1:
        printf("Filepath for the txt that should be tried? \n");
        scanf("%511s", filepath);
        printf("Chosen file path: %s \n",filepath);

        pid_t pid = fork();
        if (pid == 0) {
        //only works for gnomes terminal, might rewrite it later
        // probably not tho
        execlp("gnome-terminal", "gnome-terminal", "--wait", "--", "./typer", filepath, (char *)NULL); 
        perror("execlp");
        _exit(1);
}
        waitpid(pid, NULL, 0);
        break;

        default:
        printf("Only 1 works \n");
    }
    return 0;
    
}