
rm -r build
mkdir build
cd build 

cmake .. -DCMAKE_TOOLCHAIN_FILE=${EMSCRIPTEN}/cmake/Modules/Platform/Emscripten.cmake \
-DCMAKE_EXE_LINKER_FLAGS="-Oz -s DISABLE_EXCEPTION_CATCHING=1 --llvm-lto 1 --closure 1 \
    -fno-exceptions -fno-rtti -s USE_WEBGL2=0 -s WASM=1 -s ALLOW_MEMORY_GROWTH=1 --shell-file ../../minimal_shell.html" \
-DCMAKE_BUILD_TYPE=Release\



make