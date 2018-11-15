//imports
#include <iostream>
#include <cstring>
#include "media.h"
#include "music.h"

using namespace std;

Music::Music()//constructor
{
}

int Music::getType(){//returns 2 to indicate music
  return 2;
}

char* Music::getArtist(){//returns pointer to artist
  return artist;
}

int* Music::getDuration(){//returns pointer to duration
  return &duration;
}

char* Music::getPublisher(){//returns pointer to publisher
  return publisher;
}
