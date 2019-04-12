#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

template <class T>
class LinkedList{
private:
    Node <T> * mHead  = nullptr;
    Node <T> * mTail = nullptr ;
    Node <T> * mDummy = nullptr;
    int mSZ = 0;
public:
    template <class >   /// todo check this
    class myIterator{
        public:
            Node<T> * curr = nullptr;

            myIterator(){

            }
            myIterator(Node<T> * obj){
                curr = obj;
            }
            myIterator(const myIterator<T> &obj){
                this->curr= obj.curr;
            }
            void operator=(const myIterator<T> &obj ){
                this->curr = obj.curr;

            }
            void operator ++(){
                try {
                    if(curr->nxt == nullptr){
                        throw "error no next ";
                    }
                    curr = curr->nxt;
                }
                catch (string msg){
                    cout<<msg<<endl;
                }

        }
            myIterator<T>&operator++(int dummy = 1){
                try {
                    if(curr == nullptr) {
                        string s = "can;t";
                        throw s;
                    }
                    curr =curr->nxt;
                }
                catch (string s ){
                    cout<<s<<endl;
                }


                return *this;
            }
            void operator --(){
                try {
                    if(curr->prev == nullptr){
                        string msg ="error no previous";
                        throw  msg;
                    }
                    curr = curr->prev;
                }
                catch (string msg){
                    cout<<msg<<endl;
                }
            }
            T &operator *(){
                return curr->mValue;
            }
            bool operator==(const myIterator<T> &obj)const{
                return this->curr == obj.curr;
            }
            bool operator!=(const myIterator<T> &obj)const{
                return (this->curr != obj.curr);
            }


    };

    LinkedList(){
        mDummy = new Node<T> (-1);
        mSZ= 0 ;
    }
    LinkedList(T value , int intializeSize){
        mDummy = new Node<T> (-1);
        mSZ = intializeSize;
        Node<T> * mDummy = new Node<T> (-1);
        for (int i = 0; i <mSZ ; ++i) {
            insertHead(value);
        }


    }
    void insertHead(T value){
        Node <T> *toBeInserted = new Node<T>(value);
        if(mHead != nullptr) {
            mHead->prev = toBeInserted;
            toBeInserted->nxt = mHead;
            mHead = toBeInserted;    /// prev of the toBeInserted is null , nxt is the old head  then the head will point to the new node
        }
        else {
            mHead = toBeInserted;
            mTail = toBeInserted;
            mTail->nxt = mDummy;
            mDummy->prev = mTail;
            mDummy->nxt = nullptr;
        }
    }
    void Insert(T value , myIterator<T> position ){ /// changing the value in the pointer of the iterator not the pointer itself
                                                    /// then changing the nxt and prev in the new node to be inserted to the nxt of the current iterator
        if(mHead != nullptr) {
            for (auto i = this->begin(); i != this->endd(); ++i) {
                if (i == position) {
                    Node<T> *toBeInserted = new Node<T>(position.curr->mValue);
                    Node<T> *old = position.curr;
                    //                toBeInserted->nxt = position.curr->nxt;
                    //                toBeInserted->prev = position.curr;
                    //                position.curr->nxt   = toBeInserted;
                    //                position.curr->mValue = value;
                    /**   trying another method - */
                    toBeInserted->mValue = old->mValue;
                    old->mValue = value;
                    toBeInserted->nxt = old->nxt;
                    //                if(old->nxt != this->endd().curr){
                    old->nxt->prev = toBeInserted;
                    //                }
                    old->nxt = toBeInserted;
                    toBeInserted->prev = old;
                    if (toBeInserted->nxt == mDummy) {
                        this->mTail = toBeInserted;
                    }
                    break;

                }

            }
        }
        else {
            this->insertHead(value);
        }
    }
    myIterator<T>  erase (myIterator <T> position){
        try {
            if (position == this->endd() || position.curr == nullptr) {
                string msg = "the iterator is out of boundaries";
                throw msg;
            }
            auto currIt = position ;
            auto nxtIt = position++ ;
            --position;
            if(currIt.curr->prev != nullptr)
                currIt.curr->prev->nxt = nxtIt.curr;
            if(position == this->begin()){
                mHead = nxtIt.curr;
            }

            nxtIt.curr->prev = currIt.curr->prev;
            if(nxtIt == this->endd()){
                mTail = nxtIt.curr->prev;
            }
            delete [] currIt.curr;
            currIt.curr = nullptr;

            return nxtIt;

        }
        catch (string msg ){
            cout<<msg<<endl;

        }

    }
    void printList(){

        for (myIterator<T> it  = this->begin(); it!=this->endd() ; it++) {
            cout<<(*it)<<endl;
        }

    }
    void print(){
                Node<T> * curr = mHead;
        while((curr != mTail->nxt)){
            cout<<curr->mValue<<endl;
            curr = curr->nxt;
        }
    }
    myIterator<T> begin(){
        myIterator<T> ret(mHead);
        return ret;
    }
    myIterator<T> endd() {
        if(mTail->nxt == nullptr){
            cout<<"fuck my life\n";
        }
        myIterator<T>ret(mTail->nxt);
        return ret;
    }


};

