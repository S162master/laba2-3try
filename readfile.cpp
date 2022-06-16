#include "readfile.h"


int read_file(dat* information){
    fstream file;
     int * values = NULL;
    file.open(information->linePathFile);
    alldata* temp_array;
    int result;
    if (file.is_open()){

        temp_array = (alldata*)calloc(1,sizeof(alldata));
            string str, str_shapka;
            getline(file, str_shapka, '\n');
            string inregion;
            size_t index = 0;
            int count =2;
            while (getline(file, str, '\n')) {

                stringstream inputt(str);
                string mas[7];
                int i = 0, j=0;
                while (getline(inputt, mas[i], ','))
                i++;

                if (mas[0] != "" && mas[2] != "" && mas[3] != "" && mas[4] != "" && mas[5] != "" && mas[6] != "" && mas[1] == (information->lineNameRegion)){
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

            }
            information->size = index;
            information->massivdata = (alldata*)calloc(information->size,sizeof(alldata));
            if(!information->massivdata){
                result = -3;
            }
            for (int i = 0; i < information->size; i++){
                information->massivdata[i] = temp_array[i];
            }
            free(temp_array);
            file.close();
        }else
        result = -1;
    if (information->size == 0){
        result = -2;
    }
    result = 0;
    return result;
}

