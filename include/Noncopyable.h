//
//  Noncpoyable.h
//  spellCorrection用户输入助手
//
//  Created by ChengWang on 3/10/19.
//  Copyright © 2019 ChengWangMacPro15.4. All rights reserved.
//

#ifndef Noncpoyable_h
#define Noncpoyable_h
class Noncopyable{
public:
    Noncopyable()=default;
    ~Noncopyable()=default;
    Noncopyable(Noncopyable&)=delete;//copy ctor 没有返回值和返回值类型
    const Noncopyable operator=(const Noncopyable&)=delete;
//    Noncopyable operator=(const Noncopyable&)=delete;
};

#endif /* Noncpoyable_h */
