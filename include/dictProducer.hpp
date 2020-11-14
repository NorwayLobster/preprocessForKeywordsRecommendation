//
//  wordStatistics.hpp
//  mutex condition 互斥锁 条件变量的封装
//
//  Created by ChengWang on 3/10/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#ifndef __wordStatistics_hpp__
#define __wordStatistics_hpp__

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include "Noncopyable.h"
#include "configure.hpp"
#include "splitToolCppJieba.hpp"
// #include "splitTool.hpp"
// using namespace std;

#if 0
class Configuration:public Noncopyable
{
public:
    Configuration(const string & );
    ~Configuration();
//    map<string,string> & get();
    void showConfig();
//private:
//    map<string, string> __filesPath;
    string __englishFilePath;
    string __chineseFilePath;
};
#endif
// class splitTool;//前向声明的用法？？？
class dictProducer:Noncopyable{
public:
    dictProducer();
    dictProducer(splitTool *psplitTool);
    ~dictProducer();
    void buildDict(const std::string &filename);
    void buildChineseDict(const std::string &filename);
    void storeDict(const std::string &filename);
private:
    std::vector<std::string> __words;
//    unordered_map<string,int> __hashDict;
    std::map<std::string,int> __hashDict;
//    map<string,int> __mDict;
    // std::vector<std::pair<std::string,int>> __vDict;
//    unordered_map<string, set<int>> __dictIndex;
	splitTool * _psplitTool;
};



#endif /* wordStatistics_hpp */
