//
//  wordStatistics.cpp
//  mutex condition 互斥锁 条件变量的封装
//
//  Created by ChengWang on 3/10/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "configure.hpp"
#include "dictProducer.hpp"
//no this headfile #include <stringstream>
using std::string;
using std::cout;
using std::endl;
void preprocess(string & s){
    for(auto ite = s.begin();ite!=s.end();++ite){
        if(!isalpha(*ite)){
            auto new_ite=s.erase(ite);
            ite=--new_ite;
        }
        
        if(isupper(*ite)){
            //             tolower(*ite);//note：值传递，
            * ite= tolower(*ite);
        }
    }
}


#if 0
Configuration::Configuration(const string & configFilePath)
{
    cout<<"Configuration()"<<endl;
    ifstream ifs(configFilePath);
    if(!ifs){cerr<<"ifs error"<<endl;}
    getline(ifs, __englishFilePath);
    getline(ifs, __chineseFilePath);
}
Configuration::~Configuration(){
    cout<<"~Configuration()"<<endl;
}

void Configuration::showConfig(){
    cout<<"showConfig()"<<endl;
    cout<<"path:"<<__englishFilePath<<","<<__chineseFilePath<<endl;
}
#endif


dictProducer::dictProducer(){
    std::cout<<"dicrProducer()"<<std::endl;
}

dictProducer::dictProducer(splitTool*p) 
:_psplitTool(p){
    std::cout<<"dicrProducer(splitTool*)"<<std::endl;
}


dictProducer::~dictProducer(){
    std::cout<<"~dicrProducer()"<<std::endl;
}

//way1: 整篇文章一个大字符串，然后jieba解析, 弊端：大内存占用
//way2: 每行每行解析，弊端：词组被换行分开
void dictProducer::buildChineseDict( const std::string & _filePath){ 
    std::cout<<"buildChineseDict()"<<std::endl;
    std::ifstream ifs(_filePath);
    if(!ifs){
        std::cerr<<"ifstream error"<<endl;
    }
    string article;
    string line;
    while(std::getline(ifs,line)){
        article+=line;
    }
    _psplitTool->cut(article,__words);
    for(auto word:__words){
        __hashDict[word]+=1;
    }
    __words.clear();//内存不动，size减为0
}



void dictProducer::buildDict(const std::string & _filePath){
    std::cout<<"buildDict()"<<std::endl;
    std::cout<<"_filePath:"<<_filePath<<std::endl;
    std::ifstream ifs(_filePath);
    if(!ifs){
        std::cerr<<"ifs error"<<std::endl;
        return ;
    }
    std::string word;
    std::vector<std::string> v;
    std::string line;
//    unordered_map<string, int> hash;
    std::stringstream ss;
    while(std::getline(ifs,line)){
        //        v.push_back(line);
        ss.clear();
        ss<<line;
        while(ss>>word){
            preprocess(word);//当有word中有非字母时，直接跳过该词
            //            v.push_back(word);
            if(word=="") continue;//有可能预处理后，变成了空字符串
            __hashDict[word]+=1;
        }
    }
}



void dictProducer::storeDict(const string &filename){
    std::cout<<"storeDict(const string &)"<<std::endl;
    std::ofstream ofs(filename);

    for(auto &_pair: __hashDict){
        // __vDict.push_back(__pair);//里面是放着__pair的引用还是，它的copy 答：它的copy？？？？？？？？？？？？？？？
    // }
    // for(auto & _pair: __vDict)
        ofs<<_pair.first<<" "<<_pair.second<<std::endl;
    }
    return ;
}

