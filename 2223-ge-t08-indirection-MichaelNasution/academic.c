// 12S24003 - Michael Pratama Nasution
// 12S24019 - Winda N. V. Sitorus

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *grade_to_text(enum grade_t _grade) {
    char *text = malloc(8);
    text[0] = '\0';
    if (_grade == GRADE_A) strcpy(text, "A");
    else if (_grade == GRADE_AB) strcpy(text, "AB");
    else if (_grade == GRADE_B) strcpy(text, "B");
    else if (_grade == GRADE_BC) strcpy(text, "BC");
    else if (_grade == GRADE_C) strcpy(text, "C");
    else if (_grade == GRADE_D) strcpy(text, "D");
    else if (_grade == GRADE_E) strcpy(text, "E");
    else if (_grade == GRADE_T) strcpy(text, "T");
    else strcpy(text, "None");
    return text;
}

float calculate_performance(enum grade_t _grade, unsigned short _credit) {
    float multiplier = 0.0;
    switch (_grade) {
        case GRADE_A: multiplier = 4.0; break;
        case GRADE_AB: multiplier = 3.5; break;
        case GRADE_B: multiplier = 3.0; break;
        case GRADE_BC: multiplier = 2.5; break;
        case GRADE_C: multiplier = 2.0; break;
        case GRADE_D: multiplier = 1.0; break;
        case GRADE_E: multiplier = 0.0; break;
        default: multiplier = 0.0; break;
    }
    return _credit * multiplier;
}

void print_course(struct course_t _course) {
    char *text = grade_to_text(_course.passing_grade);
    printf("%s|%s|%d|%s\n", _course.code, _course.name, _course.credit, text);
    free(text);
}

void print_student(struct student_t _student) {
    printf("%s|%s|%s|%s|%.2f\n", _student.id, _student.name, _student.year, _student.study_program, _student.gpa);
}

void print_enrollment(struct enrollment_t _enrollment) {
    float performance = calculate_performance(_enrollment.grade, _enrollment.course.credit);
    char *text = grade_to_text(_enrollment.grade);
    printf("%s|%s|%s|%.2f\n", _enrollment.course.code, _enrollment.student.id, text, performance);
    free(text);
}

void print_enrollments(struct enrollment_t *_enrollments, unsigned short int _enrollment_size) {
    for (int i = 0; i < _enrollment_size; i++) {
        print_enrollment(_enrollments[i]);
    }
}

struct course_t create_course(char *_code, char *_name, unsigned short _credit, enum grade_t _passing_grade) {
    struct course_t crs;
    strcpy(crs.code, _code);
    strcpy(crs.name, _name);
    crs.credit = _credit;
    crs.passing_grade = _passing_grade;
    return crs;
}

struct student_t create_student(char *_id, char *_name, char *_year, char *_study_program) {
    struct student_t std;
    strcpy(std.id, _id);
    strcpy(std.name, _name);
    strcpy(std.year, _year);
    strcpy(std.study_program, _study_program);
    std.gpa = 0.0;
    return std;
}

struct enrollment_t create_enrollment(struct course_t _course, struct student_t _student, char *_year, enum semester_t _semester) {
    struct enrollment_t emt;
    emt.course = _course;
    emt.student = _student;
    strcpy(emt.year, _year);
    emt.semester = _semester;
    emt.grade = GRADE_NONE;
    return emt;
}

void calculate_gpa(struct student_t *_student,
                   struct enrollment_t *_enrollments,
                   unsigned short int _enrollment_size)
{
    // codes
    float total_performance = 0.0;
    unsigned short total_credits = 0;

    for (int i = 0; i < _enrollment_size; i++) {
        if (strcmp(_enrollments[i].student.id, _student->id) == 0) {
            float perf = calculate_performance(_enrollments[i].grade, _enrollments[i].course.credit);
            if (_enrollments[i].grade != GRADE_NONE && _enrollments[i].grade != GRADE_T) {
                total_performance += perf;
                total_credits += _enrollments[i].course.credit;
            }
        }
    }

    _student->gpa = (total_credits > 0) ? total_performance / total_credits : 0.0;
}

void set_enrollment_grade(struct course_t _course, struct student_t _student,
                          struct enrollment_t *_enrollments,
                          unsigned short int _enrollment_size,
                          enum grade_t _grade)
{
    // codes
    for (int i = _enrollment_size - 1; i >= 0; i--) {
        if (strcmp(_enrollments[i].course.code, _course.code) == 0 &&
            strcmp(_enrollments[i].student.id, _student.id) == 0) {
            _enrollments[i].grade = _grade;
            break;
        }
    }
}
