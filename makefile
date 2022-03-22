HW2_Part2.exe : HW2_Part2.o functions.o
	g++ HW2_Part2.o functions.o -o HW2_Part2.exe
HW2_Part2.o : HW2_Part2.cpp
	g++ -c HW2_Part2.cpp -o HW2_Part2.o
functions.o: functions.cpp
	g++ -c functions.cpp -o functions.o
run : HW2_Part2.exe
	./HW2_Part2.exe
clean:
	del *.o
	del main.exe