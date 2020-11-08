//
//  wordStatistics.cpp
//  mutex condition 互斥锁 条件变量的封装
//
//  Created by ChengWang on 3/10/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include "dictProducer.hpp"
#include <fstream>
#include <sstream>

#include <stdio.h>
#include "configure.hpp"
#include "dictProducer.hpp"
//no this headfile #include <stringstream>
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


dictProducer::dictProducer(string & filePath):
_filePath(filePath){
    cout<<"dicrProducer()"<<endl;
}

dictProducer::~dictProducer(){
    cout<<"~dicrProducer()"<<endl;
}

void dictProducer::buildDict(){
    cout<<"buildDict()"<<endl;
    std::cout<<"_filePath:"<<_filePath<<std::endl;
    ifstream ifs(_filePath);
    if(!ifs){
        cerr<<"ifs error"<<endl;
        return ;
    }
    string word;
    vector<string> v;
    string line;
//    unordered_map<string, int> hash;
    stringstream ss;
    while(getline(ifs,line)){
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
    for(auto &__pair: __hashDict){
        __vDict.push_back(__pair);//里面是放着__pair的引用还是，它的copy 答：它的copy？？？？？？？？？？？？？？？
    }
}

void dictProducer::buildIndex(){
    cout<<"buildIndex()"<<endl;
    string str;
    stringstream ss;
    for(auto i=0;i<__vDict.size();++i){
        for(char c:__vDict[i].first)
        {//字符 怎么转 字符串
            ss.clear();
            ss<<c;
            //            ss<<c<<endl;
            ss>>str;
//            cout<<"str:"<<str<<endl;
            auto ite = __dictIndex.find(str);//find的key的类型是string
            //            cout<<"c:"<<c<<endl;
            if(__dictIndex.end()==ite)
            {
                set<int>  __set; __set.insert(i);
                //            error:   index_dict[str]=make_pair(str, std::move(__set));
                __dictIndex.insert(std::make_pair(str, std::move(__set)));
                //fuck!! c :是字符，str是string                index_dict.insert(std::make_pair(c, std::move(__set)));
            }
            else{ ite->second.insert(i); }
        }
    }
    return ;
}
void dictProducer::storeDict(const string &filename){
    ofstream ofs(filename);
    for(auto & _pair: __vDict)
        ofs<<_pair.first<<" "<<_pair.second<<endl;
    return ;
}
void dictProducer::storeIndex(const string &filename){
    ofstream ofs(filename);
    for(auto & _pair: __dictIndex){
        ofs<<_pair.first;
        for(auto a: _pair.second) ofs<<" "<<a;
        ofs<<endl;
    }
   return ;
}
