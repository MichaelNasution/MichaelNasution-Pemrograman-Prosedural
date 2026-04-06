// 12S24003 - Michael P. Nasution
// 12S24019 - Winda N.V. Sitorus

#include "repository.h"
#include "todo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief implement your prototyped functions mentioned in the repository.h.
 *
 */

void parse_file_act ( FILE *f_act, struct todo_t *act, unsigned short int *size_act, int num_act){
    struct data_file data_todo;
    char buff_act[60];
    buff_act[0] = '\0';

    f_act = fopen("./storage/todo-repository.txt" , "r");

    while(fgets(buff_act, sizeof(buff_act), f_act)){
        
                strcpy(data_todo.fno,strtok(buff_act, "|"));
                strcpy(data_todo.ftime ,strtok(NULL, "|"));
                strcpy(data_todo.factivity , strtok(NULL, "|"));
                strcpy(data_todo.fstatus, strtok(NULL, "|"));

                int newline_pos = strcspn(data_todo.fstatus,"\n");
                data_todo.fstatus[newline_pos] = '\0';
                num_act = status_to_value(data_todo.fstatus);
                
                int fnum_act = atoi(data_todo.fno);

                act[*size_act] = create_activity (fnum_act, data_todo.ftime, data_todo.factivity,num_act);
            
            (*size_act)++;

        }

    fflush(f_act);
    fclose(f_act);
} 

void write_to_file( FILE *f_act,struct todo_t *act, unsigned short int _size ){
    
    fprintf(f_act,"%d|%s|%s|%s\n",act[_size].no, act[_size].time, act[_size].activity, status_to_text(act[_size].status));
    
    fflush(f_act);
    fclose(f_act);
}

