#include "academic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int _argc, char **_argv) {
    struct student_t *students = NULL;
    unsigned short int student_size = 0;

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        buffer[strcspn(buffer, "\n")] = 0;
        if (strcmp(buffer, "---") == 0) break;

        char *command = strtok(buffer, "#");

        if (strcmp(command, "create-student") == 0) {
            char *id = strtok(NULL, "#");
            char *name = strtok(NULL, "#");
            char *year = strtok(NULL, "#");
            char *study_program = strtok(NULL, "#");

            students = realloc(students, (student_size + 1) * sizeof(struct student_t));
            students[student_size] = create_student(id, name, year, study_program);
            student_size++;
        } else if (strcmp(command, "print-students") == 0) {
            for (int i = 0; i < student_size; i++) {
                print_student(students[i]);
            }
        }
    }

    free(students);
    return 0;
}
