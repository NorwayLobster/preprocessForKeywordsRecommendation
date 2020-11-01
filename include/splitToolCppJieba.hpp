 ///
 /// @file    splitToolCppJieba.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-24 20:33:08
 ///
 
#ifndef __SPLITTOOL_CPPJIEBA__
#define __SPLITTOOL_CPPJIEBA__
#include <iostream>
#include <iostream>
#include "splitTool.hpp"
using std::cout;
using std::endl;
class splitToolCppJieba:
public splitTool{
public:
	splitToolCppJieba();
	~splitToolCppJieba();
	vector<string> cut(const string & sentence);
};
#endif
