/****************************************************************************************************************************
Title        : DoubleNode.cpp
Authors      : Sam Gustafsson
Description  : Implementation file of the Double Node class/interface
Dependencies : DoubleNode.hpp
****************************************************************************************************************************/

#include "DoubleNode.hpp"

#include <iostream>

template<typename ItemType>
DoubleNode<ItemType>::DoubleNode(){
    prev_ = nullptr;
    next_ = nullptr;
}

template<typename ItemType>
DoubleNode<ItemType>::DoubleNode(ItemType value){
    item_ = value;
    prev_ = nullptr;
    next_ = nullptr;
}

template<typename ItemType>
DoubleNode<ItemType>::DoubleNode(ItemType value, DoubleNode<ItemType>* next_ptr, DoubleNode<ItemType>* prev_ptr){
    item_ = value;
    prev_ = prev_ptr;
    next_ = next_ptr;
}

template<typename ItemType>
void DoubleNode<ItemType>::setItem(const ItemType &anItem){ //setting the anItem values to the private member varible item_
    item_ = anItem;
}

template<typename ItemType>
void DoubleNode<ItemType>::setPrevious(DoubleNode<ItemType> *previousNodePtr){ //setting the set previous ptr to a simple varible
    prev_ = previousNodePtr;
}

template<typename ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType> *nextNodePtr){ //setting the set next ptr to a simple varible
    next_ = nextNodePtr;
}

// Getter Functions
template<typename ItemType>
ItemType DoubleNode<ItemType>::getItem() const{
    return item_;
}

template<typename ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>:: getNext() const{ //gettting the next pointer
    return next_;
}

template<typename ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>:: getPrevious() const{ //getting the prev pointer
    return prev_;
}