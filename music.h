//header guard
#ifndef MUSIC_H
#define MUSIC_H
//imports
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media {//class decloration
 public:
  Music();//constructor
  virtual int getType();//virtual function from media class
  char* getArtist();
  int* getDuration();
  char* getPublisher();
 private:
  char artist[20];
  int duration;
  char publisher[20];
};
#endif//header guard
