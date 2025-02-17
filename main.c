#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAXX_INPUT_LENGTH 15
int main(){
    char input[MAXX_INPUT_LENGTH];
    printf("Simple Shell \n");
    while (1)
    {

        fgets(input, MAXX_INPUT_LENGTH, stdin);
        if(input[0] =='\n'){
            continue;
        }

        //Remove \n character from string
        input[strcspn(input, "\n")] = '\0';

        //Exit 
        if(strcmp(input, "exit")==0 || strcmp(input, "quit")==0){
            printf("Exiting the shell....\n");
            break;
        }
    
        //Tokenize the input command and argments
        char* command=strtok(input, " ");
        char* arguments[MAXX_INPUT_LENGTH];
        int arg_count=0;
        while(command!=NULL){
          //  printf("cmd:%s\n",command);
            arguments[arg_count++]=command;
            command=strtok(NULL, " ");//Tokenize same string
        }
        arguments[arg_count]=NULL;
    
        //Fork a child process
        pid_t child_pid;
        child_pid=fork();//create process
        if(child_pid<0){
            //Error occuring during fork
            fprintf(stderr, "Fork failed\n");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0){
            //child process
            char* argv[]={NULL};
            execvp(arguments[0], arguments);
            perror("Execution Filed!\n");
            exit(EXIT_FAILURE);
        }
        else{
            //Parent process
            int status;
            waitpid(child_pid, &status, 0);
            printf("status is:%d \n",status);
        }
        printf("---------------------------------------------\n");

    }
    return  0;
}   