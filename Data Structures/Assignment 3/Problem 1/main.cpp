#include <iostream>
#include "LinkedList.h"
using namespace std;
/**
 * end is exclusive , begin is inclusive
 *
 * insert in begin
 * insert in the middle of the list
 * insert in end
 * erase with begin twice
 * erase from the end
 *
 *
 *
 */
int main(){
    LinkedList<int> ll(3 ,3);
//    ll.begin();
    ll.insertHead(5);
    ll.insertHead(6);
    auto a = ll.endd(); /// end is exclusive
    --a;
    ll.Insert(100 , a);
    ll.Insert(101 , a);
//    ll.Insert(101 , ll.begin());
    ll.printList();
    puts("----");
    a = ll.endd(); --a;
//    ll.erase(ll.begin());
//    ll.erase(ll.begin());
    ll.erase(a);
    a = ll.endd(); --a;
    ll.erase(a);
    ll.printList();
    puts("+++");
//    ll.Insert(102 , (ll.begin()++));
//    ll.Insert(103 , (ll.begin()++));
//    ll.printList();
//    puts("----");
////    ll.Insert(103 , (ll.begin()++)++);
//
//    ll.Insert(505,a);
//    ll.Insert(506 , a);
////        ll.erase(ll.begin());
////        ll.erase((ll.begin()++));
////        auto itt = ll.endd();
////        --itt;
////        ll.erase(itt);
//    ll.printList();
////    ll.Insert(505 , --ut);
//
//    auto it = ll.begin()++;
//    --ll.begin();
//    --it;
//    cout <<*it;
//    ll.print();


}