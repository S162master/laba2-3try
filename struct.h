#ifndef STRUCT_H
#define STRUCT_H
#pragma once
#include <QString>
#include <vector>
using namespace std;

enum variants{
 maxandmin, readfile
};


 struct alldata{
      int _year;
      char* _region;
      double _npg;
      double _birth_rate;
      double _death_rate;
      double _gdw;
      double _urbanization;
      //alldata(int year, QString region,double npg,double birth_rate,double death_rate,double gdw, double urbanization);
  };
  struct dat{
      char* stolb;
      string linePathFile, lineNameRegion, Column;
      variants work_file;
      alldata* massivdata;
      size_t size = 0;
      double* maxminavg;
      int kolerrorfile = -1, kolerrorminmaxavd = -1;
      double* drawList;
      };
#endif // STRUCT_H
