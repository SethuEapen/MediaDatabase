//imports
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

Media::Media()//blank constructor
{
}

int Media::getType(){//returns int corresponding to the
  return 0;
}

int* Media::getYear(){//returns pointer to year 
  return &year;
}

char* Media::getTitle(){//returns pointer to csting
  return title;
}
