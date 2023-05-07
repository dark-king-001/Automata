all: compile run clean

production:complile

compile:
	g++ -o main main.cpp

run:
	./main

clean:
	rm main