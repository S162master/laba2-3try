#include "readfile.h"
#include <cstdio>
#include <iostream>

#define error_file_open -1
#define error_size -2
#define segfault -3
#define error_memory -4

int read_file(dat* information){
    FILE *file;
    file = fopen(information->linePathFile.c_str(),"r");
    alldata* temp_array;
    int result = 0;
    if (file != NULL){

        temp_array = (alldata*)calloc(1,sizeof(alldata));
        if (!temp_array){
            result = error_memory;
        }
        char str_shapka[100] = {0};
        fscanf(file,"%[^\n]",str_shapka);
        size_t index = 0;

        while (!feof(file)){
            char year[10] = {0};
            char name[20] = {0};
            char npg[10] = {0};
            char birth_rate[10] = {0};
            char death_rate[10] = {0};
            char gdw[10] = {0};
            char urbanization[10] = {0};
            char str[100] = {0};
            char tempstr[2] = {0};
            fgets(tempstr,2,file);
            fscanf(file,"%[^\n]",str);
            sscanf(str,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",year,name,npg,birth_rate,death_rate,gdw,urbanization);
            size_t j = 0;
            int _year = atoi(year);
            double _npg = atof(npg);
            double _birth_rate = atof(birth_rate);
            double _death_rate = atof(death_rate);
            double _gdw = atof(gdw);
            double _urbanization = atof(urbanization);
            if (_year != 0 && _npg != 0 && _birth_rate != 0 && _death_rate != 0 && _gdw != 0 && _urbanization != 0 && name == (information->lineNameRegion)){
                temp_array = (alldata*)realloc(temp_array,(index + 1) * sizeof(alldata));
                if (!temp_array){
                    result = segfault;
                }
                temp_array[index]._year = _year;
                temp_array[index]._region = (char*)calloc(30, sizeof(char));
                strcpy(temp_array[index]._region, name);
                temp_array[index]._npg =_npg;
                temp_array[index]._birth_rate = _birth_rate;
                temp_array[index]._death_rate = _death_rate;
                temp_array[index]._gdw = _gdw;
                temp_array[index]._urbanization = _urbanization;
                index++;
            }else
                qDebug("обнаружено неверное значение");
        }
        information->size = index;
        information->massivdata = (alldata*)calloc(information->size,sizeof(alldata));
        if(!information->massivdata){
            result = segfault;
        }
        for (int i = 0; i < information->size; i++){
            information->massivdata[i] = temp_array[i];
        }
        free(temp_array);
        fclose(file);
    }else
        result = error_file_open;
    if (information->size == 0){
        result = error_size;
    }
    return result;
}

