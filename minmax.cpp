#include "minmax.h"


int minmaxavg(dat* information){
    double* temp_array = (double*)calloc(information->size,sizeof(double));
    for(int i=0;i < information->size;i++){
        if (information->stolb == "3")
            temp_array[i] = information->massivdata[i]._npg;
        else if (information->stolb == "4")
            temp_array[i] = information->massivdata[i]._birth_rate;
        else if (information->stolb == "5")
            temp_array[i] = information->massivdata[i]._death_rate;
        else if (information->stolb == "6")
            temp_array[i] = information->massivdata[i]._gdw;
        else if (information->stolb == "7")
            temp_array[i] = information->massivdata[i]._urbanization;
        else
            return -1;
    }
    information->drawList = (double*)calloc(information->size,sizeof(double));
    for (int i = 0; i < information->size; i++){
        information->drawList[i] = temp_array[i];
    }
    for (int i = 0; i < information->size-1; i++){
        for (int j = 0; j < information->size-1; j++){
            if (temp_array[j+1] < temp_array[j]){
                double tmp = temp_array[j];
                temp_array[j] = temp_array[j+1];
                temp_array[j+1] = tmp;
            }
        }
    }
    double median;
    double min = temp_array[0];
    double max = temp_array[information->size-1];
    if (information->size % 2 == 1)
        median = temp_array[information->size/2];
    else
        median = (temp_array[information->size/2]+ temp_array[information->size/2 -1])/2;
    information->maxminavg[0]=min;
    information->maxminavg[1]=max;
    information->maxminavg[2]=median;
    free(temp_array);
    return 0;
}
