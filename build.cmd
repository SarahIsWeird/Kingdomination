@echo off
g++ -o build/main.o -c src/main.cpp -I"D:\SFML-2.5.1\include" -Isrc/map/include -Isrc/territory/include -Isrc/camera/include
g++ -o build/territory.o -c src/territory/territory.cpp -I"D:\SFML-2.5.1\include" -Isrc/territory/include
g++ -o build/map.o -c src/map/map.cpp -I"D:\SFML-2.5.1\include" -Isrc/map/include -Isrc/territory/include
g++ -o build/editor.o -c src/map/editor.cpp -I"D:\SFML-2.5.1\include" -Isrc/map/include -Isrc/territory/include
g++ -o build/camera.o -c src/camera/camera.cpp -I"D:\SFML-2.5.1\include" -Isrc/camera/include

g++ -o Kingdomination.exe build/*.o -L"D:\SFML-2.5.1\lib" -lsfml-system -lsfml-main -lsfml-window -lsfml-graphics

del /Q build\*