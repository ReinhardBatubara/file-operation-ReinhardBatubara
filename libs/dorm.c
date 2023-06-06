#include "dorm.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender)
{

    struct dorm_t dorm_;

    strcpy(dorm_.name, _name);
    dorm_.capacity = _capacity;
    dorm_.gender = _gender;

    dorm_.residents_num = 0;

    return dorm_;
}

void print_name_dorm (struct dorm_t *dorms, unsigned short int size_dorm){
    for(int i = 0; i< size_dorm; i++){

        printf("%s|%d|%s\n", dorms[i].name, dorms[i].capacity, gender_to_text (dorms[i].gender));
    }
}
void print_all_dorm (struct dorm_t *dorms, unsigned short int size_dorm){

    for(int i = 0; i< size_dorm; i++){

        printf("%s|%d|%s|%d\n", dorms[i].name, dorms[i].capacity, gender_to_text (dorms[i].gender), dorms[i].residents_num);
    }

}