all:
	@echo "Usage: make <day><part> (Example: make 21)"

11:
	g++ -o main 1/1.cpp
	@echo "Test:"
	@./main < 1/test.txt
	@echo "Input:"
	@./main < 1/input.txt

12:
	g++ -o main 1/2.cpp
	@echo "Test:"
	@./main < 1/test.txt
	@echo "Input:"
	@./main < 1/input.txt

21:
	g++ -o main 2/1.cpp
	@echo "Test:"
	@./main < 2/test.txt
	@echo "Input:"
	@./main < 2/input.txt

22:
	g++ -o main 2/2.cpp
	@echo "Test:"
	@./main < 2/test.txt
	@echo "Input:"
	@./main < 2/input.txt

31:
	g++ -o main 3/1.cpp
	@echo "Test:"
	@./main < 3/test.txt
	@echo "Input:"
	@./main < 3/input.txt

32:
	g++ -o main 3/2.cpp
	@echo "Test:"
	@./main < 3/test.txt
	@echo "Input:"
	@./main < 3/input.txt

41:
	g++ -o main 4/1.cpp
	@echo "Test:"
	@./main < 4/test.txt
	@echo "Input:"
	@./main < 4/input.txt

42:
	g++ -o main 4/2.cpp
	@echo "Test:"
	@./main < 4/test.txt
	@echo "Input:"
	@./main < 4/input.txt

51:
	g++ -o main 5/1.cpp
	@echo "Test:"
	@./main < 5/test.txt
	@echo "Input:"
	@./main < 5/input.txt

52:
	g++ -o main 5/2.cpp
	@echo "Test:"
	@./main < 5/test.txt
	@echo "Input:"
	@./main < 5/input.txt

61:
	g++ -o main 6/1.cpp
	@echo "Test:"
	@./main < 6/test.txt
	@echo "Input:"
	@./main < 6/input.txt

62:
	g++ -o main 6/2.cpp
	@echo "Test:"
	@./main < 6/test.txt
	@echo "Input:"
	@./main < 6/input.txt