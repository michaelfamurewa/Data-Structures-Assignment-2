#include "linkedList.h"

using namespace std;


linkedList::linkedList(){
    headPtr = nullptr;
    tailPtr = nullptr;
}

int linkedList::size() {
    int size = 0;
    if(headPtr == nullptr)
        return size;
    else {
        // Iterates through the list starting at the head counting each iteration to get size
        node* temp = headPtr;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        return size;
    }
}

void linkedList::push_front(string value){
    node* temp = new node;
    temp->data = value;
    temp->index = 0;
    if(headPtr != nullptr){  // if the list is not empty
        temp->next = headPtr;
        headPtr = temp;

        temp = headPtr->next;
        while(temp != nullptr){
            temp->index += 1; // Iterating through to update indices of elements after what was pushed to the front
            temp = temp->next;
        }
    }
    else{
        headPtr = temp;
        tailPtr = temp;
    }

}

void linkedList::push_back(string value){
    node* temp = new node;
    temp->data = value;
    temp->index = size();
    if(headPtr != nullptr){
        tailPtr->next = temp;
        temp->next = nullptr;
        tailPtr = temp; //update tail to new node
    }
    else{
        headPtr = temp;
        tailPtr = temp;
    }

}

void linkedList::pop_front() {
    if(headPtr == nullptr)
        return;
    else{
        node* temp = new node;
        temp = headPtr->next;
        delete headPtr; // deallocate the space
        headPtr = temp;

        temp = headPtr;
        while(temp != nullptr){ //Updating indices of the list
            temp->index -= 1;
            temp = temp->next;
        }
    }
}

void linkedList::pop_back(){
    if(headPtr == nullptr)
        return;
    else{
        node* temp = headPtr;
        while(temp->next != tailPtr){
            temp = temp->next;
        }
        delete tailPtr;
        tailPtr = temp;
    }
}

void linkedList::print(){
    node* temp = headPtr;
    while(temp != nullptr){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

string linkedList::front() {
    return headPtr->data;
}

string linkedList::back() {
    return tailPtr->data;
}

bool linkedList::empty() {
    if(headPtr == nullptr)
        return true;
    else
        return false;
}

void linkedList::insert(unsigned int index, string value) {
    if(index > size() - 1){
        push_back(value);
    }
    else{
        node* temp = headPtr;
        node* newNode = new node;
        newNode->index = index;
        while(temp != nullptr){
            if(temp->next->index == index){
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
                break;
            }
            temp = temp->next;
        }
        temp = newNode->next;
        while(temp != nullptr){
            temp->index += 1;
            temp = temp->next;
        }
    }
}

bool linkedList::remove(unsigned int index) {
    if(index > size() - 1) // Check to see of index is out of bounds
        return false;
    else{
        node* temp = headPtr;
        node* removed = new node; // Placeholder
        while(temp != nullptr){
            if(temp->next->index == index){
                removed = temp->next;
                temp->next = removed->next;
                delete removed;
                break;
            }
            temp = temp->next;
        }
        temp = temp->next;
        while(temp != nullptr){
            temp->index -= 1;
            temp = temp->next;
        }
        return true;
    }
}

unsigned int linkedList::find(std::string key) {
    bool found = false;
    node* temp = headPtr;
    while(temp != nullptr){
        if(temp->data == key){
            found = true;
            break;
        }
        temp = temp->next;
    }
    if(found)
        return temp->index;
    else
        return size();
}