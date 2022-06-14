#include "readfile.h"


int read_file(dat* information){
    fstream file;
    file.open(information->linePathFile.toStdString());
    alldata* temp_array;

    if (file.is_open()){
        temp_array = (alldata*)calloc(3000,sizeof(alldata));
            string str, str_shapka;
            getline(file, str_shapka, '\n');//считываем шапку
            string inregion;
            size_t index = 0;
            while (getline(file, str, '\n')) {//последовательно берем по одной строке
                stringstream inputt(str);
                string mas[7];
                int i = 0, j=0;
                while (getline(inputt, mas[i], ','))//работа со строкой
                    i++;
                if (mas[0] != "" && mas[2] != "" && mas[3] != "" && mas[4] != "" && mas[5] != "" && mas[6] != "" && mas[1] == information->lineNameRegion.toStdString()){
                    temp_array[index]._year = stoi(mas [0]);
                    temp_array[index]._region = QString::fromStdString(mas[1]);
                    temp_array[index]._npg = stod(mas [2]);
                    temp_array[index]._birth_rate = stod(mas [3]);
                    temp_array[index]._death_rate = stod(mas [4]);
                    temp_array[index]._gdw = stod(mas [5]);
                    temp_array[index]._urbanization = stod(mas [6]);
                    j++;
                    index++;
                }else
                    qDebug("обнаружено неверное значение");
            }
            information->size = index;
            information->massivdata = (alldata*)calloc(information->size,sizeof(alldata));
            for (int i = 0; i < information->size; i++){
                information->massivdata[i] = temp_array[i];
            }
            free(temp_array);
        }else
          return -1;
    file.close();
    if (information->size == 0){
        return -2;
    }
    return 0;
}

