# The version of CXX, LD, and LLDEnzyme need to be pointing at the same version, in this case 14.
CXX			:= /usr/bin/clang++
LD	 		:= /usr/bin/ld.lld
LLDEnzyme 	:= /home/lpada/Projects/temp/Enzyme/enzyme/build/Enzyme/LLDEnzyme-14.so

CXXFLAGS 	+= -g -fuse-ld=$(LD) -flto
EnzymeNoOpt := -fno-vectorize -fno-slp-vectorize -fno-unroll-loops
LLDFLAGS    += -Wl,--lto-legacy-pass-manager,--mllvm=--load=$(LLDEnzyme),--save-temps

app: main.o square.o
	@echo "\nCompiling done, now linking\n"
	$(CXX) -O3 $(CXXFLAGS) main.o square.o -o app $(LLDFLAGS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) $(EnzymeNoOpt) -c main.cpp

square.o: square.cpp
	$(CXX) $(CXXFLAGS) $(EnzymeNoOpt) -c square.cpp

clean:
	rm -f main main.o square square.o app*