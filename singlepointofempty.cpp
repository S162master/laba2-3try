#include "singlepointofempty.h"

void SinglePointOfEmpty(dat* information){
  switch(information->work_file){
      case(0):{
      information->kolerrorminmaxavd = -1;
      information->kolerrorminmaxavd = minmaxavg(information);
      break;
      }
      case(1):{
      information->kolerrorfile = -1;
      information->kolerrorfile = read_file(information);
      break;
      }
  }
};
