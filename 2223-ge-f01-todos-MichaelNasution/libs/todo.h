// 12S24003 - Michael P. Nasution
// 12S24019 - Winda N.V. Sitorus

#ifndef TODO_H
#define TODO_H

/**
 * @brief define any function prototype, structs, enums, etc. related to the core domain, the to-do.
 *
 */
enum status_t
{
    DONE,
    CANCELED,
    NONE
};

struct todo_t
{
    int no;
    char time[7];
    char activity[30];
    enum status_t status;
};

struct todo_t create_activity(int no, char *time, char *activity, enum status_t status);
void activity_print_all(struct todo_t *act_p, unsigned short int _size);
char *status_to_text (enum status_t act_status);
unsigned short int status_to_value (char *_status);
void change_status (struct todo_t *_act, int idx_act, char *status);

#endif
