 ///
 /// @file    indexProducer.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-11-13 00:08:00
 ///
#ifndef __Index_Producer_Hpp__ 
#define __Index_Producer_Hpp__ 
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <set>
// using namespace std;
class indexProducer{
    public:
      indexProducer();
      ~indexProducer();
      void buildIndex(const std::string&filename);
      void storeIndex(const std::string &filename);
    private:
      void __readDict(const std::string& );
      std::vector<std::pair<std::string, int>> __vDict;
      std::map<std::string, std::set<int>> __dictIndex;
};
#endif