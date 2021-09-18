/****************************************************************************************************************************
Title        : Podcast.hpp
Authors      : Sam Gustafsson
Description  : Interface file of the Podcast implementation
Dependencies : PlaylistItem.hpp, Podcast.cpp
****************************************************************************************************************************/

#ifndef PODCAST_
#define PODCAST_

#include <string>

#include "PlaylistItem.hpp"

class Podcast : public PlaylistItem{
    public:
    Podcast(std::string title, double length, std::string genre, 
      std::string nameOfPodcast, std::string host, std::string guest);

    std::string getNameOfPodcast() const;
    std::string getHost() const;
    std::string getGuest() const;

    void setNameOfPodcast(std::string nameOfPodcast);
    void setHost(std::string host);
    void setGuest(std::string guest);

/*
    Goal: Displays the member variables to the console. 
            Format is based on the given example in podcastExample.txt.
*/
    void display() const;

    private:
    std::string name_of_podcast_;
    std::string host_;
    std::string guest_;
};

#endif
