#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"


struct student_t
{
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
};

// struct student_t create_student(char *_id, char *_name, char *_year, enum gender_t _gender);

struct student_t create_student(char *std_id, char *std_name, char *std_year, enum gender_t std_gender);

void student_print_detail(struct student_t *_student, unsigned short int _size);

void student_print_all(struct student_t *_student, unsigned short int _size);

unsigned short int get_index_student (struct student_t *_student, unsigned short int size_std, char *_id);

unsigned short int get_index_dorm (struct dorm_t *_dorm, unsigned short int size_drm, char *_name);

void assign_student(struct student_t *_student, struct dorm_t *_dorm, unsigned short int idx_std, unsigned short int idx_drm);

void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char *dorm_name);

#endif
