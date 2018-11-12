#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media {
 public:
  Movie();
  //  int getType();
  char* getDirector();
  int* getDuration();
  float* getRating();
 private:
  char director[20];
  int duration;
  float rating;
};
#endif