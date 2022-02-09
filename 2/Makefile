CC_EXEC = g++
CC_FLAGS = -std=c++11
CC = $(CC_EXEC) $(CC_FLAGS)
Object_files = main.o World.o channel.o bot.o echo.o fred.o librarian.o logger.o AlreadyExistsError.o NotExistError.o SameNameError.o

all: 2.out

2.out: $(Object_files)
	$(CC) $(Object_files) -o 2.out

main.o: main.cpp World.hpp
	$(CC) -c main.cpp

World.o: World.cpp World.hpp bot.hpp channel.hpp echo.hpp fred.hpp librarian.hpp logger.hpp AlreadyExistsError.hpp NotExistError.hpp SameNameError.hpp
	$(CC) -c World.cpp

channel.o: channel.cpp channel.hpp bot.hpp echo.hpp
	$(CC) -c channel.cpp

bot.o: bot.cpp bot.hpp
	$(CC) -c bot.cpp

echo.o: echo.cpp echo.hpp bot.hpp
	$(CC) -c echo.cpp

fred.o: fred.cpp fred.hpp bot.hpp
	$(CC) -c fred.cpp

librarian.o: librarian.cpp librarian.hpp bot.hpp
	$(CC) -c librarian.cpp

logger.o: logger.cpp logger.hpp bot.hpp
	$(CC) -c logger.cpp

AlreadyExistsError.o: AlreadyExistsError.cpp AlreadyExistsError.hpp
	$(CC) -c AlreadyExistsError.cpp

NotExistError.o: NotExistError.cpp NotExistError.hpp
	$(CC) -c NotExistError.cpp

SameNameError.o: SameNameError.cpp SameNameError.hpp
	$(CC) -c SameNameError.cpp

.PHONY: clean
clean:
	rm -r *.o
	rm 2.out