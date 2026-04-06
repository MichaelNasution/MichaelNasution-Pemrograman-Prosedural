#include "academic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int _argc, char **_argv) {
    struct student_t *students = NULL;
    unsigned short int student_size = 0;
    struct course_t *courses = NULL;
    unsigned short int course_size = 0;

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
            students[student_size++] = create_student(id, name, year, study_program);
        } else if (strcmp(command, "print-students") == 0) {
            for (int i = 0; i < student_size; i++) print_student(students[i]);
        } else if (strcmp(command, "create-course") == 0) {
            char *code = strtok(NULL, "#");
            char *name = strtok(NULL, "#");
            unsigned short credit = atoi(strtok(NULL, "#"));
            char *grade_str = strtok(NULL, "#");

            enum grade_t grade = GRADE_T;
            if (strcmp(grade_str, "A") == 0) grade = GRADE_A;
            else if (strcmp(grade_str, "AB") == 0) grade = GRADE_AB;
            else if (strcmp(grade_str, "B") == 0) grade = GRADE_B;
            else if (strcmp(grade_str, "BC") == 0) grade = GRADE_BC;
            else if (strcmp(grade_str, "C") == 0) grade = GRADE_C;
            else if (strcmp(grade_str, "D") == 0) grade = GRADE_D;
            else if (strcmp(grade_str, "E") == 0) grade = GRADE_E;

            courses = realloc(courses, (course_size + 1) * sizeof(struct course_t));
            courses[course_size++] = create_course(code, name, credit, grade);
        } else if (strcmp(command, "print-courses") == 0) {
            for (int i = 0; i < course_size; i++) print_course(courses[i]);
        } else if (strcmp(command, "find-student-by-id") == 0) {
            char *id = strtok(NULL, "#");
            struct student_t s = find_student_by_id(students, student_size, id);
            if (strlen(s.id) > 0) print_student(s);
        }
    }

    free(students);
    free(courses);
    return 0;
}
