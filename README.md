#### Clone the repository
```
git clone https://github.com/painfulexistence/msdfgen-wasm
cd msdfgen-wasm
```

#### Install dependencies
WIP

##### Build this library
Note that CMake build does not work at this point.
```
em++ -o msdfgen-wasm.js msdfgenWasm.cpp -I ext/msdfgen/include/ -Lext/msdfgen/lib -lmsdfgen-core -lbz2 -lfreetype -lpng -lpng16 -ltinyxml2 -lz -lmsdfgen-ext -DNDEBUG -O3 -sEXPORTED_RUNTIME_METHODS=ccall,cwrap -sEXPORTED_FUNCTIONS=_test,_generateMSDFTexture
```

#### License
Apart from the /ext folder, this software is licensed under the MIT license
