// 12S24003 - Michael P. Nasution
// 12S24019 - Winda N.V. Sitorus

#include "todo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief implement your prototyped functions mentioned in the todo.h.
 *
 */

struct todo_t create_activity(int no, char *time, char *activity, enum status_t status){
    struct todo_t act;
    act.no = no;
    strcpy (act.time, time);
    strcpy (act.activity, activity);
    act.status = status;
    return act;
    }


void activity_print_all(struct todo_t *act_p, unsigned short int _size){

    for(int i = 0 ; i < _size; i++){
    printf("%d|%s|%s|%s\n", act_p[i].no, act_p[i].time, act_p[i].activity, status_to_text(act_p[i].status));
    }
}

char *status_to_text (enum status_t act_status){
    char *data = malloc(10);
    if(act_status == 0) strcpy(data,"done");
    else if(act_status == 1) strcpy(data,"canceled");
    else if(act_status == 2) strcpy(data,"none");
    return data;
}

 unsigned short int status_to_value (char *_status){
    unsigned short int _value;
    if(strcmp(_status, "done") == 0) _value = DONE;
    else if(strcmp(_status, "canceled") == 0) _value = CANCELED;
    else if (strcmp(_status, "none") == 0) _value = NONE;

    return _value;
}


void change_status (struct todo_t *_act, int idx_act, char *status)
{       
    int num_stat =  status_to_value(status);
    printf("%d\n", num_stat);    
    _act[idx_act].status = num_stat;
}
