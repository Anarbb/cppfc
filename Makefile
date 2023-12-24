CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = Adherent.cpp Entrainement.cpp Entraineur.cpp Equipement.cpp Groupe.cpp main.cpp SalleDeSport.cpp SalleEntrainement.cpp Sport.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(EXEC) $(OBJS)

re: clean all

