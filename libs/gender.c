#include "gender.h"
#include <string.h>
#include <stdlib.h>

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

char *gender_to_text (enum gender_t mhs_gender){
    char *data = malloc(10);
    if(mhs_gender == 0) strcpy(data,"male");
    else if(mhs_gender == 1) strcpy(data,"female");
    return data;
}

unsigned short int gender_to_value (char *_gender){
    unsigned short int _value;
    if(strcmp(_gender, "male") == 0) _value = 0;
    else if(strcmp(_gender, "female") == 0) _value = 1;
    return _value;
}