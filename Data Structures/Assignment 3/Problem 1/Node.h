//
// Created by www on 08/04/19.
//


#ifndef ASSIGNMENT_3_NODE_H
#define ASSIGNMENT_3_NODE_H
template <class  T>
class Node{
private:


public:
    Node * nxt  = nullptr;
    Node * prev  = nullptr;
    T mValue ;

    Node(){
        nxt = nullptr;
        prev = nullptr;
    }
    Node(T value){
        mValue = value;
    }
    void operator=(const Node <T> &obj){
        if(obj.nxt != nullptr)
            this->nxt= obj.nxt;
        if(obj.prev!= nullptr)
            this->prev = obj.prev;
        this->mValue = obj.mValue;
    }
    bool operator == (const Node <T> &obj)const{
        return obj.nxt == this->nxt && obj.prev == this->prev && this->mValue == obj.mValue;
    }
    bool operator!=(const Node<T> &obj )const{
        return !(*this == obj);
    }

};
#endif //ASSIGNMENT_3_NODE_H
