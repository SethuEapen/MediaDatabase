#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"
#include "movie.h"
#include "videogame.h"
#include "music.h"

using namespace std;

void ADD(vector<Media*>* media)
{
  char input[12];
  cout << "What kind of Media would you like to add?: ";
  cin.get(input, 12);
  cin.clear();
  cin.ignore(10000, '\n');
  if(strcmp(input, "movie") == 0){
    Movie* movie = new Movie();
    cout << "Title: ";
    cin.get(movie->getTitle(), 50);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Year: ";
    cin >> *movie->getYear();
    cin.clear();
    cin.ignore(10000,'\n');
    cout << "Director: ";
    cin.get(movie->getDirector(), 20);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Duration: ";
    cin >> *movie->getDuration();
    cin.clear();
    cin.ignore(10000,'\n');
    cout << "Rating: ";
    cin >> *movie->getRating();
    cin.clear();
    cin.ignore(10000,'\n');
    media->push_back(movie);
  }
  else if(strcmp(input, "video game") == 0){
    Videogame* videogame = new Videogame();
    cout << "Title: ";
    cin.get(videogame->getTitle(), 50);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Year: ";
    cin >> *videogame->getYear();
    cin.clear();
    cin.ignore(10000,'\n');
    cout << "Publisher: ";
    cin.get(videogame->getPublisher(), 20);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Rating: ";
    cin >> *videogame->getRating();
    cin.clear();
    cin.ignore(10000, '\n');
    media->push_back(videogame);
  }
  else if(strcmp(input, "music") == 0){
    Music* music = new Music();
    cout << "Title: ";
    cin.get(music->getTitle(), 50);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Year: ";
    cin >> *music->getYear();
    cin.clear();
    cin.ignore(10000,'\n');
    cout << "Artist: ";
    cin.get(music->getArtist(), 20);
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Duration: ";
    cin >> *music->getDuration();
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Publisher: ";
    cin.get(music->getPublisher(), 20);
    cin.clear();
    cin.ignore(10000, '\n');
    media->push_back(music);
  }
  else
  {
    cout << "Sorry that type of media is not supported" << endl;
  }
}

vector<char*> SEARCH(char* title, vector<Media*>* media)
{
  vector<char*> titles;
  vector<Media*>::iterator it;
  for(it = media->begin(); it != media->end(); ++it){
    //titles->push_back(
    cout << (*it)->getTitle();
  }
  return titles;
}

int main()
{
  bool exit = false;
  while(!exit){
    vector<Media*> mediaArr;
    char input[7];
    cout << "Do you wnat to add, search, delete, or exit:";
    cin.get(input, 7);
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(input, "add") == 0){
      ADD(&mediaArr);
    }
    else if(strcmp(input, "search") == 0){
      char input2[50];
      cin >> input2;
      vector<char*> titles = SEARCH(input2, &mediaArr);
      //vector<char*>::iterator it;
      //for(it = 
    }
    else if(strcmp(input, "exit") == 0){
      exit = true;
    }
    else{
      cout << "Sorry I dont know what you mean" << endl;
    }
    return 0;
  }
}
