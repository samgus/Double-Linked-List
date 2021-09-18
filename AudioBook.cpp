/****************************************************************************************************************************
Title        : AudioBook.cpp
Authors      : Sam Gustafsson
Description  : Implementation file of the AudioBook class/interface
Dependencies : AudioBook.hpp
****************************************************************************************************************************/

#include "AudioBook.hpp"
#include <iostream>

AudioBook::AudioBook(std::string title, double length, std::string genre, std::string author, std::string speaker) : PlaylistItem(title, length, genre){
    author_ = author;
    speaker_ = speaker;
}

std::string AudioBook::getAuthor() const{
    return author_;
}

std::string AudioBook::getSpeaker() const{
    return speaker_;
}

void AudioBook::setAuthor(std::string author){
    author_ = author;
}

void AudioBook::setSpeaker(std::string speaker){
    speaker_ = speaker;
}

void AudioBook::display() const{ //displaying the values of the functions in an organized way
    std::cout << getTitle() << std::endl;
    std::cout << "Author: " << getAuthor() << std::endl;
    std::cout << "Narrator: " << getSpeaker() << std::endl;
    std::cout << "Genre: " << getGenre() << std::endl;
    std::cout << "Length: " << getLength() << std::endl;
    std::cout << std::endl;

}