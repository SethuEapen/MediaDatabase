#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"
#include "movie.h"
#include "videogame.h"

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
  else
  {
    cout << "Sorry that type of media is not supported" << endl;
  }
  /*Media* media = new Media();
  *media->getYear() = 3455;
  cout << *media->getYear();
  cin >> media->getTitle();
  cout << media->getTitle();
  */
}
int main()
{
  vector<Media*> mediaArr;
  ADD(&mediaArr);
  return 0;
}
