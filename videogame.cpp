//Imports
#include <iostream>
#include <cstring>
#include "media.h"
#include "videogame.h"

using namespace std;

Videogame::Videogame()//constructor
{
}

int Videogame::getType(){//returns 1 for virtual function to indicate a videogame
  return 1;
}

char* Videogame::getPublisher(){//returns publisher
  return publisher;
}

float* Videogame::getRating(){//returns rating
  return &rating;
}
