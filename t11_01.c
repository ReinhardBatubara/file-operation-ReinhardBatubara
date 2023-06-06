// 12S22012 - Reinhard Batubara
// 12S22001 - Winfrey H.M. Nainggolan

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/repository.h"

int main(int _argc, char **_argv)
{
    char input[100];
    char kalimat[100];
    char command[50];

    char data_id[10];
    char data_name[25];
    char data_year[5];
    char data_gender[8];
    int ang_gender;

    struct student_t *mhs = malloc(20 * sizeof(struct student_t));
    struct dorm_t *dorms = malloc(20 * sizeof(struct dorm_t));


    unsigned short int stop = 0, i;

    unsigned short int size_mhs = 1, prt_std = 0;
    unsigned short int size_dorm = 1, prt_dorm = 0;

    char buff_std[60];
    buff_std[0] = '\0';

    char buff_drm[20];
    buff_drm[0] = '\0';
    

    FILE *finput_std = fopen("./storage/student-repository.txt" , "r");
    FILE *finput_drm = fopen("./storage/dorm-repository.txt" , "r");

    // Parse FILE STD
    while(fgets(buff_std, sizeof(buff_std), finput_std)){
                strcpy(data_id ,strtok(buff_std, "|"));
                strcpy(data_name ,strtok(NULL, "|"));
                strcpy(data_year , strtok(NULL, "|"));
                strcpy( data_gender, strtok(NULL, "|"));

                ang_gender = gender_to_value(data_gender);

            for(i = prt_std; i<size_mhs; i++){
                mhs[i] = create_student(data_id, data_name, data_year, ang_gender);
            
            }
            size_mhs++;
            prt_std++;
                    }
        fflush(finput_std);

    // Parse FILE dorm
    while(fgets(buff_drm, sizeof(buff_drm), finput_drm)){
                strcpy(data_id ,strtok(buff_drm, "|"));
            
                unsigned short int capacity;
                strcpy(data_year , strtok(NULL, "|"));
                capacity = atoi(data_year);

                strcpy(data_gender, strtok(NULL, "|"));

                ang_gender = gender_to_value (data_gender);

            for(i = prt_dorm; i<size_dorm; i++){
                dorms[i] = create_dorm(data_id, capacity, ang_gender);
            }
            size_dorm++;
            prt_dorm++;
            }
        fflush(finput_drm);
    
    while (stop != 1) {
        fflush(stdin);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input,"\r\n")] = 0;
        strcpy(kalimat, input);

        strcpy(command , strtok(kalimat, "#"));
        if (strcmp(command, "student-print-all-detail") == 0){
            student_print_detail(mhs, prt_std);

        }else if(strcmp(command, "dorm-print-all-detail") == 0){
            print_all_dorm (dorms, prt_dorm);
            
        }else if(strcmp(command, "---") == 0){
            stop = 1;
        }
    }
    fclose(finput_std);
    fclose(finput_drm);
    free(mhs);
    free(dorms);

    return 0;
}

