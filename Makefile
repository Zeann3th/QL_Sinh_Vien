compile:
	@echo Compiling...
	@if not exist build (mkdir build)
	@g++ -c main.c -o build/main.o
	@g++ -c sort.c -o build/sort.o
	@g++ build/main.o build/sort.o -o build/app.exe

run:
	@echo Running...
	@build/app.exe

dev: compile run

clean:
	@echo Cleaning...
	@if exist build (rmdir /S /Q build)
