#ifndef LINK_H
#define LINK_H
#pragma once
#include<stdio.h>
template<typename Elem> class Link
{
public:
 Elem element;
 Link* next;
 Link(Elem& elem,Link* next=NULL)
 {
  element=elem;
  this->next=next;
 }
 Link(Link* next=NULL)
 {
  this->next=next;
 }
 
};
#endif
