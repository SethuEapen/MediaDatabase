//header guard
#ifndef MOVIE_H
#define MOVIE_H
//imports
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media {//class decloration
 public:
  Movie();//constructor
  virtual int getType();//virtual function from the media class
  char* getDirector();
  int* getDuration();
  float* getRating();
 private:
  char director[20];
  int duration;
  float rating;
};
#endif//header guard
