# The version of CXX, LD, and LLDEnzyme need to be pointing at the same version, in this case 14.
CXX			:= /usr/bin/clang++
LD	 		:= /usr/bin/ld.lld
LLDEnzyme 	:= /home/lpada/Projects/temp/Enzyme/enzyme/build/Enzyme/LLDEnzyme-14.so

CXXFLAGS 	+= -g -fuse-ld=$(LD) -flto
EnzymeNoOpt := -fno-vectorize -fno-slp-vectorize -fno-unroll-loops
LLDFLAGS    += -Wl,--lto-legacy-pass-manager,--mllvm=--load=$(LLDEnzyme),--save-temps

app: main.o square.o dsquare.o
	@echo "\nCompiling done, now linking\n"
	$(CXX) -O3 $(CXXFLAGS) main.o square.o dsquare.o -o app $(LLDFLAGS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(EnzymeNoOpt) -c main.cpp

square.o: square.cpp
	$(CXX) $(CXXFLAGS) $(EnzymeNoOpt) -c square.cpp

dsquare.o: dsquare.cpp
	$(CXX) $(CXXFLAGS) $(EnzymeNoOpt) -c dsquare.cpp

clean:
	rm -f main main.o square square.o dsquare dsquare.o app*