CXX = g++
CXXFLAGS = -std=c++23 -O1 -Wl,--stack,83886080 -static -finput-charset=utf-8 -fexec-charset=utf-8
LIBS = -lconio2 -lnuklear -lbgi -lgdi32 -lmsimg32 -lcomdlg32 -luuid -loleaut32 -lole32 -lreflex

SRC = main.cpp interface.cpp button.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = release/main.exe

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ) $(LIBS)

clean:
	rm -f $(OBJ) $(EXEC)