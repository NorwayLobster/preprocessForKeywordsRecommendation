 ///
 /// @file    indexProducer.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-11-13 00:09:18
 ///
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include  "indexProducer.hpp"
#include  "utilities/utilities.hpp"
// using namespace std;
using std::string;
using std::cout;
using std::endl;
indexProducer::indexProducer(){ cout<<"indexProducer() ctor"<<endl; }
indexProducer::~indexProducer(){ cout<<"~indexProducer() dtor"<<endl; }

void indexProducer::__readDict(const std::string& dictFullPath){
  std::ifstream ifs(dictFullPath);
  if(!ifs){cout<<"ifstream error"<<endl;}
  string line;
  std::stringstream ss;
  string key;
  int num;
  while(std::getline(ifs,line)){
    ss.clear();
    ss<<line;
    ss>>key>>num;
    __vDict.push_back(std::pair<string,int>(key,num)); 
    // __vDict.push_back(std::make_pair(key,num)); 
  }
  cout<<"finish reading Dict"<<endl;
}

  //字典中的(key,frequence)中每个key的每个单字作为Index的key，(key,frequence)在字典中的下标的set，作为index的value
  //难点：字母数字汉字混合的字节流，转化成，字符流。
void indexProducer::buildIndex(const std::string& dictFullPath){
    __readDict(dictFullPath);
    std::cout<<"buildIndex()"<<std::endl;
    std::string str;
    std::stringstream ss;
    for(auto i=0;i<__vDict.size();++i){
        std::vector<std::string> singleEnglishOrChineseCharacter_vec;
        utilities::splitEnglishAndChineseCharacter(__vDict[i].first,singleEnglishOrChineseCharacter_vec);
        for(std::string& str:singleEnglishOrChineseCharacter_vec)
        {//字符 怎么转 字符串
            // ss.clear();
            // ss<<c;
            // cout<<"c:"<<c<<endl;//LOG_DEBUG("c:",c);
            // ss>>str;
        //    cout<<"str:"<<str<<endl;
            auto ite = __dictIndex.find(str);//find的key的类型是string
            //            cout<<"c:"<<c<<endl;
            if(__dictIndex.end()==ite){
                std::set<int>  __set;
                __set.insert(i);
                //            error:   index_dict[str]=make_pair(str, std::move(__set));
                __dictIndex.insert(std::make_pair(str, std::move(__set)));
                //fuck!! c :是字符，str是string                index_dict.insert(std::make_pair(c, std::move(__set)));
            }else{ 
                ite->second.insert(i); 
            }
        }
    }
    return ;
}

void indexProducer::storeIndex(const string &filename){
    std::ofstream ofs(filename);
    for(auto & _pair: __dictIndex){
        ofs<<_pair.first;
        for(auto a: _pair.second) ofs<<" "<<a;
        ofs<<std::endl;
    }
   return ;
}