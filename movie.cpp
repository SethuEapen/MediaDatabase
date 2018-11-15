//imports
#include <iostream>
#include <cstring>
#include "media.h"
#include "movie.h"

using namespace std;

Movie::Movie()//constructer
{
}

int Movie::getType(){//returns 0 to indicate a movie
  return 0;
}

char* Movie::getDirector(){//retuns pointer to director
  return director;
}

int* Movie::getDuration(){//returns pointer to durration
  return &duration;
}

float* Movie::getRating(){//returns pointer to rating
  return &rating;
}
