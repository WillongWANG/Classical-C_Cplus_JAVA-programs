#ifndef LSTACK_H
#define LSTACK_H

#pragma once

#include "Link.h"

template <typename Elem>
class LStack 
{
private:
 Link<Elem>* top;
 int size;

public:
 //构造函数
 LStack(int sz=10)
 {
  top=NULL;size=0;
 }
 //析构函数
 ~LStack()
 {
  clear();
 }
 //清空栈
 void clear()
 {
  if(top!=NULL)
  {
   Link<Elem>* tempElem=top;
   top=top->next;
   delete tempElem;
  }
  size = 0;
 }
 //出栈
 bool pop(Elem& item)
 {
  if(size==0)
  {
   return false;
  }
  Link<Elem>* tempElem=top;
  item=top->element;
  top=top->next;
  delete tempElem;
  size--;
  return true;
 }
 //入栈
 bool push(Elem& item)
 {
  top=new Link<Elem>(item,top);
  size++;
  return true;
 }
 //取值
 bool topValue(Elem& item)
 {
  if(size==0)
  {
   return false;
  }
  item=top->element;
  return true;
 }
 int length(){
 	return size;
 }
};

#endif
