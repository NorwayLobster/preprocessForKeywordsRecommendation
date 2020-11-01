//
//  main.cpp
//  TextQuery-cheng
//
//  Created by ChengWang on 3/8/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <unordered_map>
//Implicit instantiation of undefined template 'std::__1::vector<std::__1::basic_string<char>, std::__1::allocator<std::__1::basic_string<char> > >
//原因：模板的未明确实例化，即找不到相关模板的定义，
//为加载相关容器的头文件
//#define FilePathDir "/Users/ChengWang/DocumentLibrary/Projects/spellCorrection用户输入助手/TextQuery-cheng/1.txt"
#define FilePathDir "/Users/ChengWang/DocumentLibrary/Projects/spellCorrection用户输入助手/TextQuery-cheng/The_Holy_Bible.txt"
using namespace std;
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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ifstream ifs(FilePathDir);
    if(!ifs){
        cerr<<"ifs error"<<endl;
        return 0;
    }
    string word;
    vector<string> v;
    string line;
    unordered_map<string, int> hash;
    stringstream ss;
    while(getline(ifs,line)){
//        v.push_back(line);
        ss.clear();
        ss<<line;
        while(ss>>word){
            preprocess(word);//当有word中有非字母时，直接跳过该词
//            v.push_back(word);
            if(word=="") continue;//有可能预处理后，变成了空字符串
            hash[word]+=1;
        }
    }
    int count =0;
    for(auto &a: hash){
//        if(a.first==""){cerr<<"have space"<<endl; break;}
        ++count;
        cout<<a.first<<":"<<a.second<<endl; }
    vector<pair<string, int>> v_dict;
    for(auto &__pair: hash){
        v_dict.push_back(__pair);//里面是放着__pair的引用还是，它的copy 答：它的copy？？？？？？？？？？？？？？？
    }
    cout<<"v_dict.size():"<<v_dict.size()<<endl;
    unordered_map<string,set<int>> index_dict;
//    for(auto & element: v_dict){
    string str;
    for(auto i=0;i<v_dict.size();++i){
        for(char c:v_dict[i].first)
        {//字符 怎么转 字符串
            ss.clear();
            ss<<c;
//            ss<<c<<endl;
            ss>>str;
            cout<<"str:"<<str<<endl;
            auto ite = index_dict.find(str);//find的key的类型是string
//            cout<<"c:"<<c<<endl;
            if(index_dict.end()==ite)
            {
                set<int>  __set; __set.insert(i);
                //            error:   index_dict[str]=make_pair(str, std::move(__set));
                index_dict.insert(std::make_pair(str, std::move(__set)));
                //fuck!! c :是字符，str是string                index_dict.insert(std::make_pair(c, std::move(__set)));
            }
            else{ ite->second.insert(i); }
        }
    }
    for(auto &__pair: index_dict){
        cout<<__pair.first<<":";
        for(auto a: __pair.second) cout<<a<<" "<<v_dict[a].first<<" "<<v_dict[a].second<<";";
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
    cout<<"hash.size():"<<hash.size()<<endl;
    cout<<"count:"<<count<<endl;
    copy(v.begin(),v.end(), ostream_iterator<string>(cout, "\n"));
//    copy(hash.begin(),hash.end(), ostream_iterator<string>(cout, "\n"));
    return 0;
}
