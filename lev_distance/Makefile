gcc_options = -std=c++17 -Wall --pedantic-error

lev : LevenshteinDist.cpp LevenshteinDist.h LevenshteinDist.h.gch
	g++ $(gcc_options) -include LevenshteinDist.h $< -o $@

LevenshteinDist.h.gch : LevenshteinDist.h
	g++ $(gcc_options) -x c++-header -o $@ $<

run : lev
	./lev test test1

clean : 
	rm -f ./lev
	rm -f ./LevenshteinDist.h.gch

.PHONY : run clean

