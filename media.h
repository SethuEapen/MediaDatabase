//header guard
#ifndef MEDIA_H
#define MEDIA_H
//imports
#include <iostream>
#include <cstring>

using namespace std;

class Media{//class definition
 public:
  Media();//constructor
  int* getYear();//returns pointer to year int
  char* getTitle();//returns pointer to title rray
  virtual int getType();//virual function will return a int that corresponds to each type of Media
 private:
  int year;//where year is stored
  char title[50];//where the title is stored
};
#endif//end of header guard
