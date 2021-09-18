/****************************************************************************************************************************
Title        : Song.cpp
Authors      : Sam Gustafsson
Description  : Implementation file of the Song class/interface
Dependencies : Song.hpp
****************************************************************************************************************************/

#include "Song.hpp"
#include <iostream>

Song::Song(std::string title, double length, std::string genre, std::string artist) : PlaylistItem(title, length, genre){
    artist_ = artist;
}

//Getter Functions
    std::string Song::getArtist() const{
        return artist_;
    }

//Setter Functions
    void Song::setArtist(std::string artist){
        artist_ = artist;
    }

//Other Functions
    void Song::display() const{ //displaying the values of the functions in an organized way
        std::cout << getTitle() << std::endl;
        std::cout << "Artist: " << getArtist() << std::endl;
        std::cout << "Genre: " << getGenre() << std::endl;
        std::cout << "Length: " << getLength() << std::endl;
        std::cout << std::endl;
    }