 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-24 22:25:45
 ///
 
#include <iostream>
#include "configure.hpp"
#include "dictProducer.hpp"
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
	string en_file = config.getConf()["en_file"];
	string cn_dictionary_fullpath = config.getConf()["cn_dictionary_fullpath"];
	string cn_dictionary_index_fullpath = config.getConf()["cn_dictionary_index_fullpath"];
    dictProducer dictPro(en_file);
    dictPro.buildDict();
    dictPro.buildIndex();
//    dictPro.storeDict("../data/dictChinese.dat");
 //   dictPro.storeIndex("../data/dictChineseIndex.dat");
    dictPro.storeDict(cn_dictionary_fullpath);
    dictPro.storeIndex(cn_dictionary_index_fullpath);
    
    return 0;
}
