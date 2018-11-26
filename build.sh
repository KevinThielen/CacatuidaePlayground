source ~/Projects/C++/external/emsdk-portable/emsdk_env.sh


 rm -r build
 rm -r bin

 mkdir build
 mkdir bin

 cd build 

# cmake .. -DCMAKE_TOOLCHAIN_FILE=${EMSCRIPTEN}/cmake/Modules/Platform/Emscripten.cmake \
# -DCMAKE_EXE_LINKER_FLAGS="-Oz -s DISABLE_EXCEPTION_CATCHING=1 --llvm-lto 1 --closure 1 \
#     -fno-exceptions -fno-rtti -s WASM=1 --shell-file ../../minimal_shell.html" \
# -DCMAKE_BUILD_TYPE=Release\

cmake .. -DCMAKE_TOOLCHAIN_FILE=${EMSCRIPTEN}/cmake/Modules/Platform/Emscripten.cmake -DCMAKE_BUILD_TYPE=Release \
          -DCMAKE_EXE_LINKER_FLAGS="-s ASSERTIONS=1 -s ALLOW_MEMORY_GROWTH=1 --shell-file ../../minimal_shell.html"

 make -j 8


cd ../bin
# #rename all html to index.html
 files=$(find -name '*.html')

for file in ${files} ; do
  mv "$file" "$(dirname $file)/index.html"
done