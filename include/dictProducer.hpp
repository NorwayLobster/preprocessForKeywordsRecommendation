//
//  wordStatistics.hpp
//  mutex condition 互斥锁 条件变量的封装
//
//  Created by ChengWang on 3/10/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#ifndef wordStatistics_hpp
#define wordStatistics_hpp

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include "Noncopyable.h"
#include "configure.hpp"
#include "splitTool.hpp"
using namespace std;

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

class dictProducer:Noncopyable{
public:
    dictProducer(string &);
    dictProducer(string & ,splitTool *psplitTool);
    ~dictProducer();
    void buildDict();
    void buildChinsesDict();
    void buildIndex();
    void storeDict(const string &filename);
    void storeIndex(const string &filename);
private:
    vector<string> __file;
//    unordered_map<string,int> __hashDict;
    map<string,int> __hashDict;
//    map<string,int> __mDict;
    vector<pair<string,int>> __vDict;
    map<string, set<int>> __dictIndex;
//    unordered_map<string, set<int>> __dictIndex;
    string & _filePath;
	splitTool * _psplitTool;
};



#endif /* wordStatistics_hpp */
