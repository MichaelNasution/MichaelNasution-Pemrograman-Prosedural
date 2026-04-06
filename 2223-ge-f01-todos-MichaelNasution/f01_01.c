// 12S24003 - Michael P. Nasution
// 12S24019 - Winda N.V. Sitorus

#include "./libs/todo.h"
#include "./libs/repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int _argc, char **_argv)
{
    char input[100];
    char kalimat[100];
    char command[50];

    char i_time[7];
    char i_activity[30];

    struct todo_t *act = malloc(20 * sizeof(struct todo_t));
 

    unsigned short int stop = 0;
    unsigned short int size_act = 0;
    unsigned short int num_sts = 0;


    FILE *finput_act = fopen("./storage/todo-repository.txt" , "r");

    // Parse FILE todo
    parse_file_act (finput_act, act, &size_act, num_sts);

    
    while (stop != 1) {
        fflush(stdin);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input,"\r\n")] = 0;
        strcpy(kalimat, input);

        strcpy(command , strtok(kalimat, "#"));
        if (strcmp(command, "todo-print-all") == 0){
            activity_print_all(act, size_act);

        }else if(strcmp(command, "todo-add") == 0){

            strcpy(i_time ,strtok(NULL, "#"));
            strcpy(i_activity ,strtok(NULL, "#"));

            num_sts = NONE;


            int num_act = size_act + 1;
            

            
                act[size_act] = create_activity(num_act, i_time, i_activity, num_sts);
            
            size_act++;
        


        }else if(strcmp(command, "---") == 0){
            stop = 1;
        }
    }
    
    free(act);
    


    return 0;
}