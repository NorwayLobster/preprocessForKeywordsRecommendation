INC_DIR:= ./include/net /usr/include/mysql/  
SRC_DIR:= .
LD_LIBRARY_PATH:=/home/cheng/20200224/spellCorrection/lib
#LD_LIBRARY_PATH:=/home/cheng/20200224/project/lib
SOURCES:=$(wildcard *.cc)
OBJECTS:=$(patsubst %.cc,%.o,$(SOURCES))
LIBS:=  -lnet -lpthread -lcrypt -lmysqlclient 
#CXXFLAGS:=-g -Wall -fpic -std=c++11  -I ../../include/net -I /usr/include/mysql/ 
CXXFLAGS:=-g -Wall  -std=c++11 $(LIBS) -Wl,-rpath=$(LD_LIBRARY_PATH) -L $(LD_LIBRARY_PATH) $(addprefix -I, $(INC_DIR)) -Wno-deprecated
ELF:=a.out

$(ELF):$(OBJECTS)
	$(CXX)  $^  -o $@  $(CXXFLAGS) 
clean:
	rm -rf $(OBJECTS) 
