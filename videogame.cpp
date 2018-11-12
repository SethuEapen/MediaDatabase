#include <iostream>
#include <cstring>
#include "media.h"
#include "videogame.h"

using namespace std;

Videogame::Videogame()
{
}

/*int getType(){
  return 1;
  }*/

char* Videogame::getPublisher(){
  return publisher;
}

float* Videogame::getRating(){
  return &rating;
}
