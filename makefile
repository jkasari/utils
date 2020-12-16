test: testString

testString: jasonString
	g++ -std=c++17 -Wall -Wpedantic jasonString.o testString.cpp -o testString

jasonString:
	g++ -std=c++17 -Wall -Wpedantic -c jasonString.cpp

clean:
	rm -rf testString *.o
	
.PHONY: test testString jasonString clean
