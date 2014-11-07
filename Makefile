CXXFLAGS =	-o -g -Wall -std=c++0x

OBJS =	main.o population.o individual.o utilities.o
TARGET = tsp
TEST = tests/distances12.in

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)
all:  $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

test: $(TARGET) $(TEST)
	./$(TARGET) < $(TEST)
