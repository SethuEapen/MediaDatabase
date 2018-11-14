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

void SEARCH(char* title, vector<Media*>* media)
{
  vector<Media*>::iterator it;
  for(it = media->begin(); it != media->end(); ++it){
    if(strcmp(title, (*it)->getTitle()) == 0){
      cout << endl << "Title: " << (*it)->getTitle() << endl;
      cout << "Year: " << *(*it)->getYear() << endl;
      if((*it)->getType() == 0){
	cout << "Director: " << dynamic_cast<Movie*>(*it)->getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movie*>(*it)->getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*it)->getRating() << endl << endl;
      }
      else if((*it)->getType() == 1){
	cout << "Publisher: " << dynamic_cast<Videogame*>(*it)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Videogame*>(*it)->getRating() << endl << endl;
      }
      else if((*it)->getType() == 2){
	cout << "Artist: " << dynamic_cast<Music*>(*it)->getArtist() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*it)->getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*it)->getPublisher() << endl << endl;
      }
    }
  }
}

void SEARCH(int year, vector<Media*>* media)
{
  vector<Media*>::iterator it;
  for(it = media->begin(); it != media->end(); ++it){
    if(year == *(*it)->getYear()){
      cout << endl << "Title: " << (*it)->getTitle() << endl;
      cout << "Year: " << *(*it)->getYear() << endl;
      if((*it)->getType() == 0){
	cout << "Director: " << dynamic_cast<Movie*>(*it)->getDirector() << endl;
	cout << "Duration: " << *dynamic_cast<Movie*>(*it)->getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*it)->getRating() << endl << endl;
      }
      else if((*it)->getType() == 1){
	cout << "Publisher: " << dynamic_cast<Videogame*>(*it)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Videogame*>(*it)->getRating() << endl << endl;
      }
      else if((*it)->getType() == 2){
	cout << "Artist: " << dynamic_cast<Music*>(*it)->getArtist() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*it)->getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*it)->getPublisher() << endl << endl;
      }
    }
  }
}

int main()
{
  bool exit = false;
  vector<Media*> mediaArr;
  char input[7];
  char input2[50];
  int input3;
  while(!exit){
    cout << "Do you wnat to add, search, delete, or exit:";
    cin.get(input, 7);
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(input, "add") == 0){
      ADD(&mediaArr);
    }
    else if(strcmp(input, "search") == 0){
      cout << "Do you want to enter a year or a title?:";
      cin.get(input, 7);
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "title") == 0){
	cin.get(input2, 50);
	cin.clear();
	cin.ignore(10000, '\n');
	SEARCH(input2, &mediaArr);
      }
      else if(strcmp(input, "year") == 0){
	cin >> input3;
	cin.clear();
	cin.ignore(10000, '\n');
	SEARCH(input3, &mediaArr);
      }
    }
    else if(strcmp(input, "delete") == 0){

    }
    else if(strcmp(input, "exit") == 0){
      exit = true;
    }
    else{
      cout << "Sorry I dont know what you mean" << endl;
    }
  }
  return 0;
}
