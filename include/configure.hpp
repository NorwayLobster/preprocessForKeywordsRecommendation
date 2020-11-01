 ///
 /// @file    configure.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-24 19:44:37
 ///
 
#ifndef __CONFIGURE_HPP__
#define __CONFIGURE_HPP__
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "Noncopyable.h"
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
class Configuration:public Noncopyable{
public:
		Configuration(){cout<<"Configuration()"<<endl;};
		Configuration(const string & filePath);
		map<string,string>  getConf();
		void showConfig();
		~Configuration();
private:
		void readFile();
private:
	string _filePath;
	map<string,string> _conf;
};
#endif
