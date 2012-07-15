#/bin/bash

# flags added:

# flags not added:
#	dynamic

pushd /Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad

llvm-g++-4.2 -dynamic -x c++ -g -arch i386 -fmessage-length=0 -pipe -Wno-trigraphs -fpascal-strings -O3 -fasm-blocks -funroll-loops -Wno-deprecated-declarations -Wno-invalid-offsetof -msse3 -mssse3 -I/Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/build/dynamicLoad.build/Release/dynamicLoad.build/dynamicLoad.hmap -I/Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/bin/include -I../../../libs/openFrameworks -I../../../libs/openFrameworks/3d -I../../../libs/openFrameworks/app -I../../../libs/openFrameworks/communication -I../../../libs/openFrameworks/events -I../../../libs/openFrameworks/gl -I../../../libs/openFrameworks/graphics -I../../../libs/openFrameworks/math -I../../../libs/openFrameworks/sound -I../../../libs/openFrameworks/types -I../../../libs/openFrameworks/utils -I../../../libs/openFrameworks/video -I../../../libs/poco/include -I../../../libs/freetype/include -I../../../libs/freetype/include/freetype2 -I../../../libs/fmodex/include -I../../../libs/glew/include -I../../../libs/FreeImage/include -I../../../libs/tess2/include -I../../../libs/cairo/include/cairo -I../../../libs/rtAudio/include -I/Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/build/dynamicLoad.build/Release/dynamicLoad.build/DerivedSources/i386 -I/Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/build/dynamicLoad.build/Release/dynamicLoad.build/DerivedSources -F/Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/bin -F/Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/../../../libs/glut/lib/osx -D__MACOSX_CORE__ -lpthread -fPIC -o "testApp.o" -include /var/folders/vx/3dppd6fj23v5v17gjmg8djpm0000gn/C/com.apple.Xcode.501/SharedPrecompiledHeaders/Carbon-haecntaoyugdtxhiixqgbfyvgjpn/Carbon.h -c /Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/src/testApp.cpp
llvm-g++-4.2 -arch i386 -dynamiclib -undefined suppress -flat_namespace testApp.o -o testApp.dylib
#llvm-g++-4.2 -arch i386 -dynamiclib -undefined suppress -flat_namespace testApp.o -arch i386 -L/Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/bin -F/Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/bin -F/Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/../../../libs/glut/lib/osx -dead_strip ../../../libs/poco/lib/osx/PocoCrypto.a ../../../libs/poco/lib/osx/PocoData.a ../../../libs/poco/lib/osx/PocoDataODBC.a ../../../libs/poco/lib/osx/PocoDataSQLite.a ../../../libs/poco/lib/osx/PocoFoundation.a ../../../libs/poco/lib/osx/PocoNet.a ../../../libs/poco/lib/osx/PocoNetSSL.a ../../../libs/poco/lib/osx/PocoUtil.a ../../../libs/poco/lib/osx/PocoXML.a ../../../libs/poco/lib/osx/PocoZip.a ../../../libs/tess2/lib/osx/tess2.a ../../../libs/glew/lib/osx/glew.a ../../../libs/cairo/lib/osx/cairo-script-interpreter.a ../../../libs/cairo/lib/osx/cairo.a ../../../libs/cairo/lib/osx/pixman-1.a ../../../libs/fmodex/lib/osx/libfmodex.dylib ../../../libs/rtAudio/lib/osx/rtAudio.a -framework GLUT /Users/elliot/dev/openFrameworks/openFrameworks/libs/openFrameworksCompiled/lib/osx/openFrameworks.a -framework AGL -framework ApplicationServices -framework AudioToolbox -framework Carbon -framework CoreAudio -framework CoreFoundation -framework CoreServices -framework OpenGL -framework QuickTime -framework AppKit -framework Cocoa -framework IOKit -o testApp.dylib

# ld flags:
# -rdynamic
# -Wl,-all_load

popd