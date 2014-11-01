CXXFLAGS =	-o -g -Wall -std=c++0x

OBJS =	main.o population.o individual.o utilities.o
TARGET = tsp
$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)
all:  $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
