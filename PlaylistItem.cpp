/****************************************************************************************************************************
Title        : PlaylistItem.cpp
Authors      : Sam Gustafsson
Description  : Implementation file of the Playlist Item class/interface
Dependencies : PlaylistItem.hpp
****************************************************************************************************************************/

#include "PlaylistItem.hpp"


PlaylistItem::PlaylistItem(std::string title, double length, std::string genre){
    title_ = title;
    length_ = length;
    genre_ = genre;
}

//Getter Functions
std::string PlaylistItem::getTitle() const{
    return title_;
}

double PlaylistItem::getLength() const{
    return length_;
}

std::string PlaylistItem::getGenre() const{
    return genre_;
}

//Setter Functions
void PlaylistItem::setTitle(std::string title){
    title_ = title;
}

void PlaylistItem::setLength(double length){
    length_ = length;
}

void PlaylistItem::setGenre(std::string genre){
    genre_ = genre;
}