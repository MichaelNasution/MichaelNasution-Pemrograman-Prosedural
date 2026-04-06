// 12S24003 - Michael Pratama Nasution
// 12S24019 - Winda N.V. Sitorus

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "string.h"
#include "stdlib.h"

int main(int _argc, char **_argv)
{
    char input[100];
    char kalimat[100];
    char command[50];

    char mhs_id[10];
    char mhs_name[25];
    char mhs_year[5];
    char mhs_gender[8];
    int ang_gender;

    struct student_t *mhs = malloc(20 * sizeof(struct student_t));
    struct dorm_t *dorms = malloc(20 * sizeof(struct dorm_t));


    unsigned short int stop = 0, i;

    unsigned short int size_mhs = 1, prt_std = 0;
    unsigned short int size_dorm = 1, prt_dorm = 0;
    
    while (stop != 1) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input,"\r\n")] = 0;
        strcpy(kalimat, input);

        strcpy(command , strtok(kalimat, "#"));
        if (strcmp(command, "student-add") == 0){
            
            strcpy(mhs_id ,strtok(NULL, "#"));
            strcpy(mhs_name ,strtok(NULL, "#"));
            strcpy(mhs_year , strtok(NULL, "#"));
            strcpy( mhs_gender, strtok(NULL, "#"));

            if( strcmp(mhs_gender, "male") == 0){
                ang_gender =  GENDER_MALE; 
            }else if(strcmp(mhs_gender, "female") == 0) {
                ang_gender = GENDER_FEMALE; 
            } 
            for(i = prt_std; i<size_mhs; i++){
                mhs[i] = create_student(mhs_id, mhs_name, mhs_year, ang_gender);
            
            }
            size_mhs++;
            prt_std++;

        }else if(strcmp(command, "student-print-all-detail") == 0){
            student_print_detail(mhs, prt_std);

        }else if(strcmp(command, "student-print-all") == 0){
            student_print_all(mhs,prt_std);
            
        }else if(strcmp(command, "dorm-add") == 0){
            strcpy(mhs_id ,strtok(NULL, "#"));
            
            unsigned short int capacity;
            strcpy(mhs_year , strtok(NULL, "#"));
            capacity = atoi(mhs_year);

            strcpy( mhs_gender, strtok(NULL, "#"));

            if( strcmp(mhs_gender, "male") == 0){
                ang_gender =  GENDER_MALE; 
            }else if(strcmp(mhs_gender, "female") == 0) {
                ang_gender = GENDER_FEMALE; 
            }
            for(i = prt_dorm; i<size_dorm; i++){
                dorms[i] = create_dorm(mhs_id, capacity, ang_gender);
            }
            size_dorm++;
            prt_dorm++;

        }else if(strcmp(command, "dorm-print-all-detail") == 0){
            print_all_dorm (dorms, prt_dorm);
            
        }else if(strcmp(command, "dorm-print-all") == 0){
            print_name_dorm (dorms, prt_dorm);
            

        }else if(strcmp(command, "---") == 0){
            stop = 1;
        }
    }
    free(mhs);
    return 0;
    }
