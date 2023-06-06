#include "student.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"


struct student_t create_student(char *std_id, char *std_name, char *std_year, enum gender_t std_gender){
    struct student_t std;
    strcpy(std.id, std_id);
    strcpy (std.name, std_name);
    strcpy (std.year, std_year);
    std.gender = std_gender;
    std.dorm = NULL;
    return std;
    }


void student_print_detail(struct student_t *_student, unsigned short int _size){

    for(int i = 0 ; i<_size; i++){
        char dorm_name[15];
        if(_student[i].dorm == NULL) strcpy(dorm_name, "unassigned");
        else strcpy(dorm_name, _student[i].dorm->name);


        printf("%s|%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, gender_to_text (_student[i].gender), dorm_name);

    }
}

void student_print_all(struct student_t *_student, unsigned short int _size){

    for(int i = 0 ; i < _size; i++){
    printf("%s|%s|%s|%s\n", _student[i].id, _student[i].name, _student[i].year, gender_to_text (_student[i].gender));
    
    }
}

unsigned short int get_index_student (struct student_t *_student, unsigned short int size_std, char *_idstd){
    unsigned short int counter_std, i;

    for (i = 0; i < size_std; i++){
                if(strcmp(_student[i].id, _idstd) == 0)
                {
                    counter_std = i;
                    break;
                }
    }
    return counter_std;
    
}

unsigned short int get_index_dorm (struct dorm_t *_dorm, unsigned short int size_drm, char *_name){
    unsigned short int counter_drm, i;

    for (i = 0; i < size_drm; i++){
                if(strcmp(_dorm[i].name, _name) == 0)
                {
                    counter_drm = i;
                    break;
                }
    }
    return counter_drm;
    
}
void assign_student(struct student_t *_student, struct dorm_t *_dorm, unsigned short int idx_std, unsigned short int idx_drm)
{       
        
        if (_dorm[idx_drm].capacity > _dorm[idx_drm].residents_num){

            if (_dorm[idx_drm].gender == _student[idx_std].gender){
            _student[idx_std].dorm = &_dorm[idx_drm];
            _dorm[idx_drm].residents_num++;
            }
        }
}

void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char *dorm_name)
{
    if (_dorm->residents_num < _dorm->capacity)
    {
        if (_dorm->gender == _student->gender)
        {   _student->dorm = _dorm;
            old_dorm->residents_num--;
            _dorm->residents_num++;
        }
    }
}