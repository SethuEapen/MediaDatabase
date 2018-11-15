//header guard
#ifndef VIDEOGAME_H
#define VIDEOGAME_H
//imports
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Videogame : public Media {//class decloration
 public:
  Videogame();//constructor
  virtual int getType();//virtual function from media
  char* getPublisher();
  float* getRating();
 private:
  char publisher[20];
  float rating;
};
#endif//header guard
