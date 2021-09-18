/****************************************************************************************************************************
Title        : DoubleNode.hpp
Authors      : Sam Gustafsson
Description  : Interface file of the Double Node implementation
Dependencies : DoubleNode.cpp
****************************************************************************************************************************/

#ifndef DOUBLE_NODE
#define DOUBLE_NODE

template<typename ItemType>
class DoubleNode{
    public:
    // Setter Functions
    DoubleNode();
    DoubleNode(ItemType value);
    DoubleNode(ItemType value, DoubleNode<ItemType>* next_ptr, DoubleNode<ItemType>* prev_ptr);
    void setItem(const ItemType &anItem);
    void setPrevious(DoubleNode<ItemType> *previousNodePtr);
    void setNext(DoubleNode<ItemType> *nextNodePtr);

    // Getter Functions
    ItemType getItem() const;
    DoubleNode<ItemType> *getNext() const;
    DoubleNode<ItemType> *getPrevious() const;

    private:
    ItemType item_;
    DoubleNode<ItemType> *next_;
    DoubleNode<ItemType> *prev_;
};

#include "DoubleNode.cpp"
#endif