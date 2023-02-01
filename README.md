# Enzyme Example - C++
This project gives an example of using the [Enzyme](https://enzyme.mit.edu/) AD tool on a simple C++ project using the Clang compiler, and the LLVM-based [Intel DPC++/C++ Compiler](https://www.intel.com/content/www/us/en/develop/documentation/oneapi-dpcpp-cpp-compiler-dev-guide-and-reference/top.html).

## Dependencies (using Intel compiler)
- `LLVMEnzyme-15.so`, this is the Enzyme LLVM pass plugin built against LLVM version 15
- `llvm-link`, version 15 (llvm bitcode module linker)
- `opt`, version 15 (llvm bitcode module optimizer)
- `icx`, version 2022.2.1 (Intel DPC++/C++ Compiler)

## Dependencies (using Clang compiler)
- `LLDEnzyme-15.so`, this is the Enzyme LLD pass plugin built against LLVM version 15
- `ld.lld`, version 15 (llvm linker - drop in replacement for GNU's `ld` linker)
- `clang`, version 15

## Setup
- If `clang`, `ld.lld`, `llvm-link`, `opt`, or `icx` aren't in your path then either add them to your path, or put their paths in the appropriate variables in `Makefile`.
- In `Makefile-icx` and `Makefile-clang`, modify respectively the paths `/usr/local/lib/Enzyme/LLVMEnzyme-15.so` to be and `/usr/local/lib/Enzyme/LLDEnzyme-15.so` be actual paths to the libraries.

## Notes
- Documentation for building `LLVMEnzyme-15.so`/`LLDEnzyme-15.so` can be found at [here](https://enzyme.mit.edu/Installation/), however the process can be simplified. Instead of building LLVM manually as suggested, simply install the llvm headers/libraries and build against these. The headers/libraries can be installed using `apt install llvm-15-dev` (you might need to first [add the llvm 15 toolchain repository to apt](https://apt.llvm.org/))), and then the required cmake directory can be found using `dpkg -L llvm-15-dev | grep lib/cmake/llvm`, at which point one can then follow the Enzyme build steps.