
rm -r build
mkdir build
cd build 

cmake .. -DCMAKE_TOOLCHAIN_FILE=${EMSCRIPTEN}/cmake/Modules/Platform/Emscripten.cmake \
-DCMAKE_EXE_LINKER_FLAGS="-Oz -s DISABLE_EXCEPTION_CATCHING=1 --llvm-lto 1 --closure 1 \
    -fno-exceptions -fno-rtti -s WASM=1 --shell-file ../../minimal_shell.html" \
-DCMAKE_BUILD_TYPE=Release\



make