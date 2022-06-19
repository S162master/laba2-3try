#include "readfile.h"
#include <cstdio>
#include <iostream>

#define segfold -3

int read_file(dat* information){
    FILE *file;
    file = fopen("C:\\table.csv","r");
    alldata* temp_array;
    int result;
    if (1){

        temp_array = (alldata*)calloc(1,sizeof(alldata));
        if (!temp_array){
            result = segfold;
        }

            char* str;
            char str_shapka[100] = {0};
            fscanf(file,"%[^\n]",str_shapka);
            string inregion;
            size_t index = 0;
            int count =2;
            while (!feof(file)){//while (getline(file, str, '\n')) {

                char** mas;
                mas = (char**)calloc(7,sizeof(char*));
                if (!mas){
                    result = segfold;
                }
                int h = 0;
                while (h < 7){
                mas[h] = (char*)calloc(30,sizeof(char));
                if (!mas[h]){
                    result = segfold;
                }
                h++;
                }
                char str[100] = {0};
                char tempstr[2] = {0};
                fgets(tempstr,2,file);
                fscanf(file,"%[^\n]",str);
                sscanf(str,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s",mas[0][0],mas[1][0],mas[2][0],mas[3][0],mas[4][0],mas[5][0],mas[6][0]);
                qDebug<<mas[0][0]<<mas[0][1]<<mas[0][2]<<mas[0][3]<<mas[0][4];
                int i = 0, j=0;



               /* if (mas[0] != "" && mas[2] != "" && mas[3] != "" && mas[4] != "" && mas[5] != "" && mas[6] != "" && mas[1] == (information->lineNameRegion)){
                    temp_array = (alldata*)realloc(temp_array,(index + 1) * sizeof(alldata));
                    temp_array[index]._year = stoi(mas [0]);
                    temp_array[index]._region = new char[mas[1].length()];
                    strcpy(temp_array[index]._region,mas[1].c_str());
                    temp_array[index]._npg = stod(mas [2]);
                    temp_array[index]._birth_rate = stod(mas [3]);
                    temp_array[index]._death_rate = stod(mas [4]);
                    temp_array[index]._gdw = stod(mas [5]);
                    temp_array[index]._urbanization = stod(mas [6]);
                    j++;
                    index++;
                    count++;
                }else
                    qDebug("обнаружено неверное значение");
                    */

            }

            information->size = index;
            information->massivdata = (alldata*)calloc(information->size,sizeof(alldata));
            if(!information->massivdata){
                result = segfold;
            }
            for (int i = 0; i < information->size; i++){
                information->massivdata[i] = temp_array[i];
            }
            free(temp_array);
            fclose(file);
        }else
        result = -1;
    if (information->size == 0){
        result = -2;
    }
    result = 0;
    return result;
}

