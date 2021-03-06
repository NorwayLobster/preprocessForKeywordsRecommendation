 ///
 /// @file    splitToolEnglish.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-24 19:53:19
 ///
 
#ifndef __SPLITTOOL_ENGLISH__
#define __SPLITTOOL_ENGLISH__
#include <iostream>
#include "splitTool.hpp"
using std::cout;
using std::endl;
class splitToolBaiDuLAC: public splitTool
{
public:
	splitToolBaiDuLAC();
	~splitToolBaiDuLAC();
	virtual vector<string> cut(const string & sentence);
};
#endif
