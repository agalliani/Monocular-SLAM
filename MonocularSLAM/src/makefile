#----------------------------------------------------------------------------
#       COMPONENT DEFINITION
#----------------------------------------------------------------------------
COMPONENT     = MonocularSLAM
PACKAGE       = MonocularSLAM
PACKAGE-DIR   = $(STAR_NAV_COM)/$(PACKAGE)

COMPONENT-SRC = ImageProcessing.cpp  \
		MonocularSLAM.cpp

BIN-DIR       = $(PACKAGE-DIR)/bin


#----------------------------------------------------------------------------
#       REQUIRED FUNCTIONAL LIBRARIES
#----------------------------------------------------------------------------

FUNC-INCLUDE_dir  = -I$(STAR_NAV_FUN_INC)
FUNC-LIB_dir      = -L$(STAR_NAV_FUN_LIB)
FUNC-LIBs         = -lstarfunc_math 


#----------------------------------------------------------------------------
#       REQUIRED COMPONENT FRAMEWORK LIBRARIES
#----------------------------------------------------------------------------

# Core libraries
CORE-LIB_dir      = -L$(STAR_CF_LIB)
CORE-INCLUDE_dir  = -I$(STAR_CF_INC)
CORE-LIBs         = -lstarcore_runtime


# IDL libraries
IDL-LIB_dir       = -L$(STAR_MSG_LIB)
IDL-INCLUDE_dir   = -I$(STAR_MSG_INC)
IDL-LIBs          = -lstaridl_sensor_msgs -lstaridl_configuration_msgs

#----------------------------------------------------------------------------
#       REQUIRED SYSTEM LIBRARIES
#-------------------------------------rpath=/home/user/.usr/lib----------------------------------------
# E-PROSIMA DDS
DDS-LIBs          = -lfastcdr -lfastrtps

#SYSTEM
SYS-LIBs	  = -ldl -lnsl -lm

#BOOST
BOOST-LIBs	  = -lpthread -lrt -lboost_system -lboost_thread -lboost_filesystem

#OPENCV
OPENCV-INCLUDE_dir   = -I/usr/include/opencv4/
OPENCV-LIBs          = `pkg-config opencv4 --cflags --libs`


#----------------------------------------------------------------------------
#       COMPILER DIRECTIVES
#----------------------------------------------------------------------------

CPP= g++

CPPFLAGS = -c -Wall -fpic -m64 -O2 -std=c++0x
LN= g++
AR=ar
LDFLAGS= -m64 
#SYSLIBS= -ldl -lnsl -lm -lpthread -lrt -lboost_system -lboost_thread
DEFINES= 

INCLUDES= -Iinclude/ $(IDL-INCLUDE_dir) $(CORE-INCLUDE_dir) $(FUNC-INCLUDE_dir) $(OPENCV-INCLUDE_dir) 

Static_LIBS  = $(CORE-LIB_dir)/ $(CORE-LIBs) $(IDL-LIB_dir)/ $(IDL-LIBs)
Dynamic_LIBS = $(FUNC-LIB_dir)/ $(FUNC-LIBs) $(DDS-LIBs) $(BOOST-LIBs) $(OPENCV-LIBs) $(SYS-LIBs)


DIRECTORIES= output.dir $(BIN-DIR).dir

COMPONENT_TARGET= $(PACKAGE-DIR)/bin/$(COMPONENT)


all: $(DIRECTORIES) $(COMPONENT_TARGET) clean

#COMPONENT_OBJS = $(COMPONENT-SRC:src/%.cpp=output/%.o)
COMPONENT_OBJS = $(COMPONENT-SRC:%.cpp=output/%.o)

OBJS+= $(COMPONENT_OBJS)

$(COMPONENT_TARGET): $(COMPONENT_OBJS)  
	$(LN) $(LDFLAGS) -o $@ $(COMPONENT_OBJS) -Wl,-Bstatic $(Static_LIBS) -Wl,-Bdynamic $(Dynamic_LIBS)

output/%.o:%.cxx
	$(CPP) $(CPPFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

output/%.o:%.cpp
	$(CPP) $(CPPFLAGS) $(INCLUDES) $(DEFINES) -c $< -o $@

.PHONY: $(COMPONENT_TARGET) 

clean:
	@rm -r output

%.dir : 
	@echo "Checking directory $*"
	@if [ ! -d $* ]; then \
		echo "Making directory $*"; \
		mkdir -p $* ; \
	fi;
