/****************************************************************************************************************************
Title        : PlaylistItem.hpp
Authors      : Sam Gustafsson
Description  : Interface file of the PlaylistItem implementation
Dependencies : PlaylistItem.cpp
****************************************************************************************************************************/

#ifndef PLAYLIST_ITEM
#define PLAYLIST_ITEM

#include <string>


class PlaylistItem{
    public:

    /*
    Parameterized Construtor
    Parameters: title, length, genre
    Goal: Update member variables with given parameters
*/

    PlaylistItem();
    PlaylistItem(std::string title, double length, std::string genre);

/************************ Getter Functions ************************/

/*
    Goal: Return the value of title_
*/
    std::string getTitle() const;

/*
    Goal: Return the value of length_
*/
    double getLength() const;

/*
    Goal: Return the value of genre_
*/
    std::string getGenre() const;

/************************ Setter Functions ************************/

/*
    Goal: Update the value of title_ with the given parameter
*/
    void setTitle(std::string title);

/*
    Goal: Update the value of length_ with the given parameter
*/
    void setLength(double length);

/*
    Goal: Update the value of genre_ with the given parameter
*/
    void setGenre(std::string genre);

/************************ Other Functions ************************/

/*
    A virtual function to be implemented by the children classes
*/
    virtual void display() const = 0;

    private:

    std::string title_;
    double length_;
    std::string genre_;

};





#endif