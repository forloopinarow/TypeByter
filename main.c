#include <stdio.h>
#include <unistd.h>    // sleep, fork, execlp, _exit
#include <sys/wait.h>  // waitpid

int main(void) {
    int userInput;
    printf("Welcome to TypeByter \nPlease pick the mode you want to do! \n");
    printf("1) TypingTest\n2) CarrerMode (doesnt work)\n");

    scanf("%d", &userInput);

    if (userInput == 1) {
        printf("\nYou picked the typing test, a second terminal should open.\n");
        sleep(1);
        printf("Please wait a few seconds\n");
        sleep(2);

        //pid_t variable typ,
        //pid ist ne variable
        //fork kopiert programm, und halt returned nummer von dem pid
        
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            return 1;
        }

        if (pid == 0) {
            execlp("gnome-terminal", "gnome-terminal", "--wait", "--", "./typer", (char *)NULL);
            perror("execlp");   // only runs if execlp failed
            _exit(1);
        }
        waitpid(pid, NULL, 0);
        printf("Typing test finished, back in the menu.\n");
    }

    return 0;
}