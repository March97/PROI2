CXX = g++  -Wall -pedantic -std=c++11

sources=main.cpp Restaurant.cpp RestaurantChain.cpp
headers=Restaurant.h RestaurantChain.h

debug: $(sources) $(headers)
	$(CXX) -g -DDEBUG $(sources) -o $@

release: $(sources) $(headers)
	$(CXX) $(sources) -o $@

clean:
	rm -rf debug
	rm -rf release
