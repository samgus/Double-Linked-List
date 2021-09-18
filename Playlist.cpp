/****************************************************************************************************************************
Title        : Playlist.cpp
Authors      : Sam Gustafsson
Description  : Implementation file of the Playlist class/interface
Dependencies : Playlist.hpp, DoublyLinkedList.hpp, PlaylistItem.hpp, DoubleNode.hpp
****************************************************************************************************************************/

#include "Playlist.hpp"
#include "DoublyLinkedList.hpp"
#include "PlaylistItem.hpp"
#include "DoubleNode.hpp"

#include <iostream>

Playlist::Playlist() : DoublyLinkedList(){
}

double Playlist::getTotalTime() const{
    DoubleNode<PlaylistItem*>* x = head_ptr;
    double sum = 0;
    for (int i = 1; i <= getSize(); i++){
        sum += x->getItem()->getLength();
        x = x->getNext(); //advance to the next pointer
    }
    return sum;
}

void Playlist::operator+=(Playlist rhs){ //union
    std::cout<<"statement"<<std::endl;
    DoubleNode<PlaylistItem*>* x = rhs.head_ptr;
    for (int i = 0; i < rhs.list_size; i++){
        std::cout<<"inside for loop"<<std::endl;
        insert(x->getItem(), getSize() + 1);
        std::cout<<"test"<<std::endl;
        x = x->getNext();
    }
}

void Playlist::operator-=(Playlist rhs){ //intersect
    DoubleNode<PlaylistItem*>* x = rhs.head_ptr;
    for (int i = 0; i < rhs.list_size; i++){
        int y = getIndexOf(x->getItem());
        if (y != -1){
            remove(y);
        }
        x = x->getNext();
    }
}

void Playlist::skip(){
    DoubleNode<PlaylistItem*>* x = head_ptr;
    insert(x->getItem(), list_size + 1);
    remove(1);
}

void Playlist::rewind(){ //moves the last song to the front
    DoubleNode<PlaylistItem*>* x = tail_ptr;
    insert(x->getItem(), 1);
    remove(list_size);
}

void Playlist::display(){
    DoubleNode<PlaylistItem*>* x = head_ptr;
    while (x) {
        x->getItem()->display();
        x = x->getNext();
    }
}