 ///
 /// @file    helloworld.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-11-12 01:05:47
 ///
 
#include <iostream>
#include "helloworld/helloworld.hpp"
using std::cout;
using std::endl;
namespace hello{
Helloworld::Helloworld(){cout<<"helloworld ctor()"<<endl;}
Helloworld::~Helloworld(){cout<<"helloworld dtor()"<<endl;}
void Helloworld::print(){
	cout<<"hello world!"<<endl;
}
}//end of namespace hello
