// 12S24003 - Michael P. Nasution
// 12S24019 - Winda N.V. Sitorus

#include "todo.h"

#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <stdio.h>

struct data_file
{
    char fno[3];
    char ftime[7];
    char factivity[30];
    char fstatus[10];
};

/**
 * @brief define any function prototype, structs, enums, etc. related to stream operations that you need.
 *
 */

void parse_file_act ( FILE *f_act, struct todo_t *act, unsigned short int *size_act, int num_act);
void write_to_file( FILE *f_act,struct todo_t *act, unsigned short int _size );

#endif
