<!--
 * @Author: your name
 * @Date: 2020-11-08 19:45:26
 * @LastEditTime: 2020-11-18 14:23:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /preprocessForKeywordsRecommendation/README.md
-->
# preprocessForKeywordsRecommendation
the preprocessing for Keywords Recommendation System
# project development plan
## step 1: create the project, build a building framework using CMake
## step 2: develop the main bussiness logic 
## step 3: create UT using GTest/GMock
## step 4: do code static analysis(cppcheck, cppformat,...) 
## step 5: compile flag etc
## step 6: re-factor it into a microsevice, based on K8S and Docker
## step 7: add CI/CD 
## step 8: add a web interface
## step 9: 按微服务的那个回调架构设计, bussiness logic写在requestHandler里面,
## step 10:  use baidu/lac which is based on deep learning, instead of cppjieba
## step 11: 定时任务 每天定时执行，进行增量update index和字典

