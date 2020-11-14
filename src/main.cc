 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-24 22:25:45
 ///
 
#include <iostream>
#include "configure.hpp"
#include "splitToolCppJieba.hpp"
#include "dictProducer.hpp"
#include "indexProducer.hpp"
#include "helloworld/helloworld.hpp"
using std::cout;
using std::endl;
using std::cerr;

int main(int argc, char**argv){
	if(2!=argc){
		cerr<<"args error: ./a.out conf.dat"<<endl;
		// cerr<<"args error: ./a.out conf.dat dict.dat dictIndex.dat"<<endl;
		exit(EXIT_FAILURE);
	}
    Configuration config(argv[1]);
//    Configuration config("./conf.dat");
    config.showConfig();
	string project_root_dir = config.getConf().at("project_root_dir");

//en
#if 0
	string en_file = project_root_dir+config.getConf().at("en_file");
	string en_dictionary_fullpath = project_root_dir+config.getConf()["en_dictionary_fullpath"];
	string en_dictionary_index_fullpath =project_root_dir+config.getConf()["en_dictionary_index_fullpath"];
    cout<<"en_file:"<<en_file<<endl;
    cout<<"en_dict...:"<<en_dictionary_fullpath<<std::endl;
    cout<<"en_dict_index...:"<<en_dictionary_index_fullpath<<std::endl;
    dictProducer dictPro;
    dictPro.buildDict(en_file);
    dictPro.storeDict(en_dictionary_fullpath); //dictPro.storeDict("../data/dictChinese.dat");
    indexProducer indexPro;
    indexPro.buildIndex(en_dictionary_fullpath);
    indexPro.storeIndex(en_dictionary_index_fullpath); //dictPro.storeIndex("../data/dictChineseIndex.dat");
#endif

//cn
#if 1 
	string cn_fileOfFilesName_fullPath = project_root_dir+config.getConf().at("cn_file_path");
	string cn_dictionary_fullpath = project_root_dir+config.getConf()["cn_dictionary_fullpath"];
	string cn_dictionary_index_fullpath =project_root_dir+config.getConf()["cn_dictionary_index_fullpath"];

	string jieba_dictionary_index_fullpath = project_root_dir+config.getConf()["dict_path"];
	string jieba_hmm_fullpath = project_root_dir+config.getConf()["hmm_path"];
	string jieba_user_dict_fullpath = project_root_dir+config.getConf()["user_dict_path"];
	string jieba_idf_fullpath = project_root_dir+config.getConf()["idf_path"];
	string jieba_stopword_fullpath = project_root_dir+config.getConf()["stopword_path"];

    splitToolCppJieba spT(jieba_dictionary_index_fullpath, jieba_hmm_fullpath, jieba_user_dict_fullpath, jieba_idf_fullpath, jieba_stopword_fullpath);
    // vector<string> words;  
    // string s="今天他来到了清华大学";
    // spT.cut(s,words);
    // for(auto w:words){
        // cout<<w<<endl;
    // }
    // cout<<"hello start:"<<endl;
    // hello::Helloworld hello_world;
    // hello_world.print();
    // cout<<"hello end:"<<endl;
    dictProducer cnDictPro(&spT);
    std::ifstream ifs(cn_fileOfFilesName_fullPath); 
    string line;
    while(std::getline(ifs,line)){
	string cn_file_path = project_root_dir+"inputData/"+line;
        cout<<"filePullPath:"<<cn_file_path<<endl;
        cnDictPro.buildChineseDict(cn_file_path);
    }
    cnDictPro.storeDict(cn_dictionary_fullpath); //dictPro.storeDict("../data/dictChinese.dat");

    indexProducer indexPro;
    indexPro.buildIndex(cn_dictionary_fullpath);
    indexPro.storeIndex(cn_dictionary_index_fullpath); //dictPro.storeIndex("../data/dictChineseIndex.dat");
#endif
    return 0;
}