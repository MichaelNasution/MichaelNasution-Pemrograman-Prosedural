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

    char i_num[3];
    char i_time[7];
    char i_activity[30];
    char i_status[10];

    

    struct todo_t *act = malloc(20 * sizeof(struct todo_t));


    unsigned short int stop = 0;
    unsigned short int size_act = 0;
    unsigned short int num_sts = 0;


    FILE *finput_act = fopen("./storage/todo-repository.txt" , "r");

    // Parse FILE todo
    parse_file_act (finput_act, act, &size_act, num_sts);

    finput_act = fopen("./storage/todo-repository.txt" , "a");

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
    
                fprintf(finput_act,"%d|%s|%s|%s\n",act[size_act].no, act[size_act].time, act[size_act].activity, status_to_text(act[size_act].status));
            
            size_act++;
        


        }else if(strcmp(command, "todo-status") == 0){
            
            strcpy(i_num ,strtok(NULL, "#"));

            int poin_num = atoi(i_num); 

            strcpy(i_status ,strtok(NULL, "#"));
            
            if( act[poin_num-1].status !=  DONE  ){
            int num_stat =  status_to_value(i_status);

        
            act[poin_num -1 ].status = num_stat;
            }

        }
        else if(strcmp(command, "---") == 0){
            stop = 1;
        }
    }
    
    fclose(finput_act);
    free(act);
    


    return 0;
}