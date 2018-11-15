//imports
#include <iostream>
#include <vector>
#include <cstring>
#include "media.h"
#include "movie.h"
#include "videogame.h"
#include "music.h"

using namespace std;

void ADD(vector<Media*>* media)//Add media
{
  char input[12];//media type selection variable
  cout << "What kind of Media would you like to add?: ";
  cin.get(input, 12);//getting the media type selection
  cin.clear();
  cin.ignore(10000, '\n');
  if(strcmp(input, "movie") == 0){//what to do if the input is the string "movie"
    Movie* movie = new Movie();//new Movie object in heap
    //following lines set the values for movie
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
    media->push_back(movie);//add Movie to the media vector
  }
  else if(strcmp(input, "video game") == 0){//what to do if the input was "video game"
    Videogame* videogame = new Videogame();//new Videogame object in heap
    //following lines set the values for videogame
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
    media->push_back(videogame);//add videogame to the media vector
  }
  else if(strcmp(input, "music") == 0){//what to do if the input was "music"
    Music* music = new Music();//new Music object in heap
    //following lines set the valudes for Music
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
    media->push_back(music);//add music to the media vector
  }
  else//what to do if the input is none of the above
  {
    cout << "Sorry that type of media is not supported" << endl;
  }
}

void SEARCH(char* title, vector<Media*>* media)//search for media
{
  vector<Media*>::iterator it;//create itorator for media array
  for(it = media->begin(); it != media->end(); ++it){//for loop through iterator
    if(strcmp(title, (*it)->getTitle()) == 0){//if the title matches the input..
      cout << endl << "Title: " << (*it)->getTitle() << endl;//print title
      cout << "Year: " << *(*it)->getYear() << endl;//print year
      if((*it)->getType() == 0){//if the type return 0 it is a Movie
	//print out the specific feilds for a movie
	cout << "Director: " << dynamic_cast<Movie*>(*it)->getDirector() << endl;//dynamic cast the *it to a movie
	cout << "Duration: " << *dynamic_cast<Movie*>(*it)->getDuration() << endl;
	cout << "Rating: " << *dynamic_cast<Movie*>(*it)->getRating() << endl << endl;
      }
      else if((*it)->getType() == 1){//if the type returns a 1 than it is a videogame
	//print out specific feilds for a videogame
	cout << "Publisher: " << dynamic_cast<Videogame*>(*it)->getPublisher() << endl;
	cout << "Rating: " << *dynamic_cast<Videogame*>(*it)->getRating() << endl << endl;
      }
      else if((*it)->getType() == 2){//if the type returns a 2 than it is music
	//print out specific feilds for music
	cout << "Artist: " << dynamic_cast<Music*>(*it)->getArtist() << endl;
	cout << "Duration: " << *dynamic_cast<Music*>(*it)->getDuration() << endl;
	cout << "Publisher: " << dynamic_cast<Music*>(*it)->getPublisher() << endl << endl;
      }
    }
  }
}

void DELETE(char* title, vector<Media*>* media)//delete items in media array
{
  char input[5];//char for yes or no
  //the section bellow is exactly the same as search
  vector<Media*>::iterator it;//iterator through media
  for(it = media->begin(); it != media->end(); ++it){//for loop through the media array
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
      //new code
      cout << "Do you want to delete this pointer? 'yes' or 'no': ";
      cin.get(input, 5); //inputs yes or no into the input cstring
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "yes") == 0){//if input is yes...
	delete *it;//delete the object
	it = media->erase(it);//delete the memory/space in the media array
	return;
      }
    }
  }
}
//the following 2 funcions are exactly the same as above with a few noted changes
void SEARCH(int year, vector<Media*>* media)
{
  vector<Media*>::iterator it;
  for(it = media->begin(); it != media->end(); ++it){
    if(year == *(*it)->getYear()){//if the year of it is eaqual to entered year...
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

void DELETE(int year, vector<Media*>* media)
{
  char input[5];
  vector<Media*>::iterator it;
  for(it = media->begin(); it != media->end(); ++it){
    if(year == *(*it)->getYear()){//if the uear of it is eaqual to entered year...
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
	  cout << "Do you want to delete this pointer? 'yes' or 'no': ";
	  cin.get(input, 5);
	  cin.clear();
	  cin.ignore(10000, '\n');
	  if(strcmp(input, "yes") == 0){
		  delete *it;
		  it = media->erase(it);
		  return;
	  }
    }
  }
}



int main()
{
  bool exit = false;//run condition
  vector<Media*> mediaArr;//media array
  char input[7];//input for decition tree
  char input2[50];//title input
  int input3;//year input
  while(!exit){//running loop
    cout << "Do you wnat to add, search, delete, or exit:";
    cin.get(input, 7);//gets input for first decition in decition tree
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(input, "add") == 0){//if input is add
      ADD(&mediaArr);// run add
    }
    else if(strcmp(input, "search") == 0){//if input is search
      cout << "Do you want to enter a year or a title?:";
      cin.get(input, 7);//stores what function of search should be run in cstring
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "title") == 0){//if title
		cout << "Title: ";
		cin.get(input2, 50);//enter desired title
		cin.clear();
		cin.ignore(10000, '\n');
		SEARCH(input2, &mediaArr);//search using cstring search
      }
      else if(strcmp(input, "year") == 0){//if year
		cout << "Year: ";
		cin >> input3;//enter desired year
		cin.clear();
		cin.ignore(10000, '\n');
		SEARCH(input3, &mediaArr);//search using int search
      }
    }
    else if(strcmp(input, "delete") == 0){//if input is delete
      //same decition tree as search
      cout << "Do you want to enter a year or a title?:";
      cin.get(input, 7);//
      cin.clear();
      cin.ignore(10000, '\n');
      if(strcmp(input, "title") == 0){
	cout << "Title: ";
	cin.get(input2, 50);
	cin.clear();
	cin.ignore(10000, '\n');
	DELETE(input2, &mediaArr);//delete using cstring delete
      }
      else if(strcmp(input, "year") == 0){
	cout << "Year: ";
	cin >> input3;
	cin.clear();
	cin.ignore(10000, '\n');
	DELETE(input3, &mediaArr);//delete using int delete
      }
    }
    else if(strcmp(input, "exit") == 0){//if input is exit
      exit = true;//stop the run loop
    }
    else{//if none type sorry i dont know what you mean
      cout << "Sorry I dont know what you mean" << endl;
    }
  }
  return 0;//stop program
}
