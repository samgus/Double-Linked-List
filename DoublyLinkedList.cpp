/****************************************************************************************************************************
Title        : DoublyLinkedList.cpp
Authors      : Sam Gustafsson
Description  : Implementation file of the DoublyLinkedList class/interface
Dependencies : DoublyLinkedList.hpp
****************************************************************************************************************************/
#include "DoublyLinkedList.hpp"
#include <iostream>

template<typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(){
    list_size = 0;
    head_ptr = NULL;
}
template<typename ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& other_list){
    DoubleNode<ItemType>* new_list_ = other_list.getHeadPtr(); //pointing to the head ptr of the other list

    for (int i = 1; i <= other_list.getSize(); i++){ 
        insert(new_list_->getItem(), i);
        new_list_ = new_list_->getNext();
    }
}
template<typename ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList(){
    clear();
}
template<typename ItemType> 
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position){ //provided implementation from slides
    DoubleNode<ItemType>* node_ptr = new DoubleNode<ItemType>(item, nullptr, nullptr);
    DoubleNode<ItemType>* temp_ptr = getAtPos(position); 

    if (head_ptr == nullptr){
    // Insert first node
        node_ptr->setNext(nullptr);
        node_ptr->setPrevious(nullptr);
        head_ptr = node_ptr;
        tail_ptr = node_ptr;
    }
    else if (temp_ptr == head_ptr) {
       // Insert new node at head of chain
        node_ptr->setNext(head_ptr);
        node_ptr->setPrevious(nullptr);
        head_ptr->setPrevious(node_ptr);
        head_ptr = node_ptr;
    }
    else if (temp_ptr == nullptr) {
        //insert at end of list
        node_ptr->setNext(nullptr);
        node_ptr->setPrevious(tail_ptr);
        tail_ptr->setNext(node_ptr);
        tail_ptr = node_ptr;
    }
    else{
        (temp_ptr->getPrevious())->setNext(node_ptr); //assigning the previous node's next node
        node_ptr->setPrevious(temp_ptr->getPrevious()); //assigning new node's previous node
        temp_ptr->setPrevious(node_ptr); // assigning next node's previous node
        node_ptr->setNext(temp_ptr); //assigning new node's next node
    }
    list_size++;
    return true;
}
   //inserts item at position in caller list
template<typename ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position){ //provided implementation from slides
    DoubleNode<ItemType>* temp_ptr = getAtPos(position);
    if (temp_ptr == nullptr){ // no node at position
        return false;
    } 
    else{
        
        if (temp_ptr == head_ptr){
            head_ptr->setPrevious(nullptr);
            head_ptr = temp_ptr->getNext(); 
            

            temp_ptr->setNext(nullptr); 
            delete temp_ptr;
            temp_ptr = nullptr;
        }
      
        else if (temp_ptr == tail_ptr) {
            //remove tail_ptr node
            tail_ptr  = temp_ptr->getPrevious();
            tail_ptr ->setNext(nullptr);
            // Return node to the system
            temp_ptr->setPrevious(nullptr);
            delete temp_ptr;
            temp_ptr = nullptr;
        }
        else{
            temp_ptr->getPrevious()->setNext(temp_ptr->getNext());
            temp_ptr->getNext()->setPrevious(temp_ptr->getPrevious());
            // Return node to the system
            temp_ptr->setNext(nullptr);
            temp_ptr->setPrevious(nullptr);
            delete temp_ptr;
            temp_ptr = nullptr;
        }
        list_size--;
        return true;
        }
    }
    
   //removes the node at position
template<typename ItemType>
int DoublyLinkedList<ItemType>::getSize() const{
    return list_size;
}                       
   // returns the number of the nodes in the calling list
template<typename ItemType>			
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const{
    return head_ptr;
} 
   // returns a copy of the headPtr
template<typename ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int &pos) const{
    DoubleNode<ItemType>* temp_ptr = head_ptr;
    for (int i = 1; i < pos; i++){
        temp_ptr = temp_ptr->getNext();
    }
    return temp_ptr;
}
   // returns a pointer to the node located at pos
template<typename ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const{
    if (list_size == 0){
        return true;
    }
    return false;
}                     
   // returns whether the calling list is empty
template<typename ItemType>
void DoublyLinkedList<ItemType>::clear(){
    while (!isEmpty()){
        remove(1);
    }
}                              
   // clears the list
template<typename ItemType>
int DoublyLinkedList<ItemType>::getIndexOf(const ItemType &item) const{
    DoubleNode<ItemType>* temp_ptr = head_ptr;
    int x = 1;
    while (x <= list_size){
        //if the item does not equal to the item im looking for, traverse the chain by 1 
        //and increment x by 1
        if (item != temp_ptr->getItem()){
            temp_ptr = temp_ptr->getNext();
            x++;
        }
        else {
           return x; //else return x
        }
    }
    return -1;
} 
   // returns the position of the given item in the list, -1 otherwise
template<typename ItemType>
void DoublyLinkedList<ItemType>::display() const{
    //traversing through and printing each object
    DoubleNode<ItemType>* new_position; //creating the pointer once so we're not creating new pointers for each list item.
    for (int i = 1; i <= list_size; i++){
        new_position = getAtPos(i);
        
        if (i != list_size){
            std::cout << new_position->getItem() << " ";
        }
        else{
            std::cout << new_position->getItem();
        }
    }
    std::cout << std::endl;
}                       
   // prints the contents of the calling list in order
template<typename ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const{
    DoubleNode<ItemType>* new_position; //creating the pointer once so we're not creating new pointers for each list item.
    for (int i = list_size; i >= 1; i--){
        new_position = getAtPos(i);
        
        if (i != 1){
            std::cout << new_position->getItem() << " ";
        }
        else{
            std::cout << new_position->getItem();
        }
    }
    std::cout << std::endl;
 }              
   // prints the contents of the calling list in reverse order
template<typename ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType> &a_list){
    DoubleNode<ItemType>* y = head_ptr;
    DoubleNode<ItemType>* z = a_list.getHeadPtr();

    DoublyLinkedList<ItemType> list_;

    while (y != nullptr || z != nullptr){
        if (y != nullptr){
            list_.insert(y->getItem(), list_.list_size + 1); //inserting into new list
            y = y->getNext();
        }
        if (z != nullptr){
            list_.insert(z->getItem(), list_.list_size + 1); //inserting into new list
            z = z->getNext();
        }
    }
    return list_;
}
// returns the interleaved list of the calling and parameter lists